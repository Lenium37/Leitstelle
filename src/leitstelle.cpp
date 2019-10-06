//
// Created by Johannes on 06.10.2019.
//

#include "leitstelle.h"
#include "xml_vehicle_list_reader.h"
#include <QtXml>
#include <iostream>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

Leitstelle::Leitstelle() {

  this->init();
  QGridLayout *layout_vehicles_fire = this->m_vehicle_window.findChild<QGridLayout *>("gridLayoutVehiclesFire");
  QPushButton *btn = new QPushButton;
  layout_vehicles_fire->addWidget(btn, 3, 3);

  this->m_main_window.setWindowState(Qt::WindowMaximized);
  this->m_vehicle_window.setWindowState(Qt::WindowMaximized);
  this->m_vehicle_window.show();
}

int Leitstelle::init() {
  this->read_vehicles_from_xml();
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

