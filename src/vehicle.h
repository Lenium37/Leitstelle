//
// Created by Johannes on 06.10.2019.
//

#ifndef LEITSTELLE_SRC_VEHICLE_H_
#define LEITSTELLE_SRC_VEHICLE_H_

#include <string>
#include <memory>

enum VehicleStatus {
  STATUS0,
  STATUS1,
  STATUS2,
  STATUS3,
  STATUS4,
  STATUS5,
  STATUS6,
  STATUS7,
  STATUS8
};

enum VehicleType {
  MTF,
  LF10,
  DLK23,
  KTW
};

class Vehicle {
 private:
  bool m_enabled;
  std::string m_city_callout;
  std::string m_vehicle_callout;
  std::string m_name;
  VehicleType m_type;
  VehicleStatus m_status;
  int m_position_in_list;

 public:
  Vehicle();
  Vehicle(bool enabled, const std::string& city_callout, const std::string& vehicle_callout, const std::string& type, const int& status, const int &position_in_list);
  ~Vehicle();

  const bool get_enabled();
  void set_enabled(const bool& enabled);

  const std::string get_city_callout();
  void set_city_callout(const std::string& city_callout);

  const std::string get_vehicle_callout();
  void set_vehicle_callout(const std::string& vehicle_callout);

  const std::string get_name();
  void set_name(const std::string& name);

  const VehicleType get_type();
  const std::string get_type_string();
  void set_type(const std::string& type);

  const VehicleStatus get_status();
  void set_status(const int& status);

  const int get_position_in_list();
  void set_position_in_list(const int& position);

};

#endif //LEITSTELLE_SRC_VEHICLE_H_
