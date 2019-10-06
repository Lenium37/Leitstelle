#include <utility>

//
// Created by Johannes on 06.10.2019.
//

#include "vehicle.h"

Vehicle::Vehicle() {

}

Vehicle::Vehicle(bool enabled, const std::string& city_callout, const std::string& vehicle_callout, const std::string& type, const int& status, const int &position_in_list)
  : m_enabled(enabled), m_position_in_list(position_in_list) {
    this->set_name(city_callout + " " + vehicle_callout);
    this->set_type(type);
    this->set_status(status);
}

Vehicle::~Vehicle() = default;

const std::string Vehicle::get_name() {
  return this->m_name;
}

void Vehicle::set_name(const std::string& name) {
  this->m_name = name;
}

const VehicleType Vehicle::get_type() {
  return this->m_type;
}

void Vehicle::set_type(const std::string& type) {
  if(type == "DLK(A) 23-12")
    this->m_type = VehicleType::DLK23;
  else if(type == "LF 10")
    this->m_type = VehicleType::LF10;
  else if(type == "MTF")
    this->m_type = VehicleType::MTF;
  else if(type == "KTW")
    this->m_type = VehicleType::KTW;
}

const VehicleStatus Vehicle::get_status() {
  return this->m_status;
}

void Vehicle::set_status(const int& status) {
  if(status == 0)
    this->m_status = VehicleStatus::STATUS0;
  else if(status == 1)
    this->m_status = VehicleStatus::STATUS1;
  else if(status == 2)
    this->m_status = VehicleStatus::STATUS2;
  else if(status == 3)
    this->m_status = VehicleStatus::STATUS3;
  else if(status == 4)
    this->m_status = VehicleStatus::STATUS4;
  else if(status == 5)
    this->m_status = VehicleStatus::STATUS5;
  else if(status == 6)
    this->m_status = VehicleStatus::STATUS6;
  else if(status == 7)
    this->m_status = VehicleStatus::STATUS7;
  else if(status == 8)
    this->m_status = VehicleStatus::STATUS8;
}

const bool Vehicle::get_enabled() {
  return this->m_enabled;
}

void Vehicle::set_enabled(const bool& enabled) {
  this->m_enabled = enabled;
}

const std::string Vehicle::get_city_callout() {
  return this->m_city_callout;
}

void Vehicle::set_city_callout(const std::string& city_callout) {
  this->m_city_callout = city_callout;
}

const std::string Vehicle::get_vehicle_callout() {
  return this->m_vehicle_callout;
}

void Vehicle::set_vehicle_callout(const std::string& vehicle_callout) {
  this->m_vehicle_callout = vehicle_callout;
}

const int Vehicle::get_position_in_list() {
  return this->m_position_in_list;
}

void Vehicle::set_position_in_list(const int& position_in_list) {
  this->m_position_in_list = position_in_list;
}

