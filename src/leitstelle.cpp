//
// Created by Johannes on 06.10.2019.
//

#include "leitstelle.h"
#include "xml_vehicle_list_reader.h"
#include "vehicle_label.h"
#include "vehicle_label_menu.h"
#include <QtXml>
#include <iostream>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

Leitstelle::Leitstelle() {

  this->init();
  this->m_main_window.setWindowState(Qt::WindowMaximized);
  this->m_vehicle_window.setWindowState(Qt::WindowMaximized);
  this->m_vehicle_window.show();
}

int Leitstelle::init() {
  this->read_vehicles_from_xml();
  this->place_vehicles_in_window();
  return 0;
}

int Leitstelle::read_vehicles_from_xml() {
  // Open a file for reading
  QFile file(":vehicles.xml");
  if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return -1;
  }

  XmlVehicleListReader::read(&file, this->m_vehicles_fire, this->m_vehicles_ems);
  std::cout << "number of fire vehicles: " << this->m_vehicles_fire.size() << std::endl;
  std::cout << "number of ems vehicles: " << this->m_vehicles_ems.size() << std::endl;
  for (auto const& entry : this->m_vehicles_fire) {
    std::cout << entry.first  // key
              << " : "
              << entry.second.get()->get_status() // value
              << std::endl ;
  }
  file.close();
}

int Leitstelle::place_vehicles_in_window() {
  for(auto const& entry : this->m_vehicles_fire) {
    std::string name = entry.second.get()->get_city_callout() + "\n" + entry.second.get()->get_vehicle_callout() + "\n(" + entry.second.get()->get_type_string() + ")";
    VehicleLabel* label = new VehicleLabel(QString::fromStdString(name));
    int row = entry.second.get()->get_position_in_list() / 6;
    int column = (entry.second.get()->get_position_in_list() - 1) % 5;
    auto* menu = new VehicleLabelMenu();
    label->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(label, SIGNAL(customContextMenuRequested(QPoint)), menu, SLOT(showMenu(QPoint)));
    this->m_vehicle_window.findChild<QGridLayout *>("gridLayoutVehiclesFire")->addWidget(label, row, column);
  }

  for(auto const& entry : this->m_vehicles_ems) {
    std::string name = entry.second.get()->get_city_callout() + "\n" + entry.second.get()->get_vehicle_callout() + "\n(" + entry.second.get()->get_type_string() + ")";
    VehicleLabel* label = new VehicleLabel(QString::fromStdString(name));
    int row = entry.second.get()->get_position_in_list() / 6;
    int column = (entry.second.get()->get_position_in_list() - 1) % 5;
    auto* menu = new VehicleLabelMenu();
    label->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(label, SIGNAL(customContextMenuRequested(QPoint)), menu, SLOT(showMenu(QPoint)));
    this->m_vehicle_window.findChild<QGridLayout *>("gridLayoutVehiclesEms")->addWidget(label, row, column);
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
