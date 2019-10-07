//
// Created by Johannes on 06.10.2019.
//

#include "leitstelle.h"
#include "xml_vehicle_list_reader.h"
#include <QtXml>
#include <iostream>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include "unistd.h"

Leitstelle::Leitstelle() {
  this->m_main_window = new MainWindow();
  this->m_vehicle_window = new VehicleWindow();

  this->init();
  this->m_main_window->setWindowState(Qt::WindowMaximized);
  this->m_vehicle_window->setWindowState(Qt::WindowMaximized);
  this->m_vehicle_window->show();
}

int Leitstelle::init() {
  this->read_vehicles_from_xml();
  this->place_vehicles_in_window();
  QObject::connect(this->m_vehicle_window, &VehicleWindow::status_displayed_changed, this, &Leitstelle::update_vehicle_labels);
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
}

int Leitstelle::place_vehicles_in_window() {
  for(auto const& entry : this->m_vehicles_fire) {
    std::shared_ptr<Vehicle> vehicle = entry.second;
    std::string name = vehicle->get_city_callout() + "\n" + vehicle->get_vehicle_callout() + "\n(" + vehicle->get_type_string() + ")";
    VehicleLabel* label = new VehicleLabel(QString::fromStdString(name));
    label->set_status(vehicle->get_status());
    int row = vehicle->get_position_in_list() / 6;
    int column = (vehicle->get_position_in_list() - 1) % 5;
    auto* menu = new VehicleLabelMenu();
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
    auto* menu = new VehicleLabelMenu();
    label->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(label, SIGNAL(customContextMenuRequested(QPoint)), menu, SLOT(showMenu(QPoint)));
    this->m_vehicle_window->findChild<QGridLayout *>("gridLayoutVehiclesEms")->addWidget(label, row, column);
    this->m_vehicle_labels.insert(std::pair<std::string, VehicleLabel*>(label->get_text(), label));
  }
  return 0;
}

void Leitstelle::update_vehicle_labels(int new_status) {
  std::cout << "Status changed to " << new_status << std::endl;
  this->show_only_vehicles_with_status(new_status);
  //std::cout << "hi" << std::endl;
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
      if (label->get_status() != status)
        label->setVisible(false);
      else
        label->setVisible(true);
    }
  }
  return 0;
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

