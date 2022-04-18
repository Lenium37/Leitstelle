//
// Created by Johannes on 06.10.2019.
//

#include "leitstelle.h"
#include "xml_vehicle_list_reader.h"
#include <QtXml>
#include <iostream>
#include <QtWidgets/QGridLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGroupBox>
#include "xml_aao_reader.h"
#include "unistd.h"

Leitstelle::Leitstelle() {
  this->m_main_window = new MainWindow();
  this->m_vehicle_window = new VehicleWindow();
  this->m_info_window = new InfoWindow();
  this->m_crew_window = new CrewWindow();
  this->m_leitstellen_window = new LeitstellenWindow();

  this->m_main_window->setWindowState(Qt::WindowMaximized);
  this->m_vehicle_window->setWindowState(Qt::WindowMaximized);
  this->m_info_window->setWindowState(Qt::WindowMaximized);
  this->m_crew_window->setWindowState(Qt::WindowMaximized);
  this->m_leitstellen_window->setWindowState(Qt::WindowMaximized);

  this->init();
  this->m_vehicle_window->show();
  this->m_info_window->show(); // do not show for now
  this->m_crew_window->show();
  this->m_leitstellen_window->show();
}

int Leitstelle::init() {
  this->read_vehicles_from_xml();
  this->place_vehicles_in_window();
  this->read_aao();
  QObject::connect(this->m_vehicle_window, &VehicleWindow::status_displayed_changed, this, &Leitstelle::update_vehicle_labels);
  QObject::connect(this->m_leitstellen_window, &LeitstellenWindow::alarm_button_clicked, this, &Leitstelle::new_alarm_dialog);
  return 0;
}

int Leitstelle::read_vehicles_from_xml() {
  // Open a file for reading
  QFile file(":vehicles.xml");
  if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return -1;
  }
  XmlVehicleListReader::read(&file, this->m_vehicles_fire, this->m_vehicles_ems);
  file.close();

  return 0;
}

int Leitstelle::place_vehicles_in_window() {
  for(auto const& entry : this->m_vehicles_fire) {
    std::shared_ptr<Vehicle> vehicle = entry.second;
    std::string name = vehicle->get_city_callout() + "\n" + vehicle->get_vehicle_callout() + "\n(" + vehicle->get_type_string() + ")";
    VehicleLabel* label = new VehicleLabel(QString::fromStdString(name));
    label->set_status(vehicle->get_status());
    int row = vehicle->get_position_in_list() / 6;
    int column = (vehicle->get_position_in_list() - 1) % 5;
    auto* menu = new VehicleLabelMenu(label);
    label->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(label, SIGNAL(customContextMenuRequested(QPoint)), menu, SLOT(showMenu(QPoint)));
    this->m_vehicle_window->findChild<QGridLayout *>("gridLayoutVehiclesFire")->addWidget(label, row, column);
    this->m_vehicle_labels.insert(std::pair<std::string, VehicleLabel*>(label->get_text(), label));
  }

  for(auto const& entry : this->m_vehicles_ems) {
    std::shared_ptr<Vehicle> vehicle = entry.second;
    std::string name = vehicle->get_city_callout() + "\n" + vehicle->get_vehicle_callout() + "\n(" + vehicle->get_type_string() + ")";
    VehicleLabel* label = new VehicleLabel(QString::fromStdString(name));
    label->set_status(vehicle->get_status());
    int row = vehicle->get_position_in_list() / 6;
    int column = (vehicle->get_position_in_list() - 1) % 5;
    auto* menu = new VehicleLabelMenu(label);
    label->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(label, SIGNAL(customContextMenuRequested(QPoint)), menu, SLOT(showMenu(QPoint)));
    this->m_vehicle_window->findChild<QGridLayout *>("gridLayoutVehiclesEms")->addWidget(label, row, column);
    this->m_vehicle_labels.insert(std::pair<std::string, VehicleLabel*>(label->get_text(), label));
  }
  return 0;
}

void Leitstelle::update_vehicle_labels(int new_status) {
  this->show_only_vehicles_with_status(new_status);
}

int Leitstelle::show_only_vehicles_with_status(int status) {
  if(status == -1) {
    for(const auto& entry : this->m_vehicle_labels) {
      VehicleLabel* label = entry.second;
      label->setVisible(true);
    }
  } else {
    for (const auto &entry : this->m_vehicle_labels) {
      VehicleLabel *label = entry.second;
      label->setVisible(label->get_status() == status);
    }
  }
  return 0;
}

void Leitstelle::read_aao() {
  QFile aao_file(":aao.xml");
  aao_file.open(QIODevice::ReadOnly);
  XmlVehicleListReader::read_aao(&aao_file, this->m_aao);
  aao_file.close();
}

void Leitstelle::new_alarm_dialog() {
  this->m_alarm_dialog = new AlarmDialog();
  this->m_alarm_dialog->set_aao(this->m_aao);
  QObject::connect(this->m_alarm_dialog, SIGNAL(finished (int)), this, SLOT(dialogIsFinished(int)));
  this->m_alarm_dialog->show();
}

Leitstelle::~Leitstelle() = default;

std::map<const std::string, std::shared_ptr<Vehicle>> Leitstelle::get_vehicles_fire() {
  return this->m_vehicles_fire;
}

std::map<const std::string, std::shared_ptr<Vehicle>> Leitstelle::get_vehicles_ems() {
  return this->m_vehicles_ems;
}

void Leitstelle::add_vehicle(std::shared_ptr<Vehicle> vehicle, bool is_fire) {
  if(is_fire)
    this->m_vehicles_fire.insert(std::pair<std::string, std::shared_ptr<Vehicle>>(vehicle->get_name(), vehicle));
}

void Leitstelle::dialogIsFinished(int result) {
  if(result == QDialog::Accepted) {
    
    std::string stichwort = this->m_alarm_dialog->get_current_stichwort();
    std::string address = this->m_alarm_dialog->get_current_address();
    std::string freitext = this->m_alarm_dialog->get_current_freitext();
    std::string vehicles_translated = this->m_alarm_dialog->get_current_vehicles_translated(this->m_vehicles_fire, this->m_vehicles_ems);
    this->m_leitstellen_window->open_new_einsatz(stichwort + " - " + address);

    this->m_alarm_window = new AlarmWindow(stichwort + " - " + address, vehicles_translated, freitext);
    QDesktopWidget qDesktopWidget;

    int screen = qDesktopWidget.screenNumber(this->m_crew_window);

    this->m_alarm_window->setWindowState(Qt::WindowMaximized);
    QRect screenRect = QApplication::desktop()->screenGeometry(screen);
    this->m_alarm_window->move(QPoint(screenRect.x(), screenRect.y()));
    this->m_alarm_window->show();
    return;
  }
}