//
// Created by Johannes on 06.10.2019.
//

#ifndef LEITSTELLE_SRC_LEITSTELLE_H_
#define LEITSTELLE_SRC_LEITSTELLE_H_

#include "vehicle_window.h"
#include "main_window.h"
#include "vehicle.h"
#include "vehicle_label.h"
#include "vehicle_label_menu.h"

class Leitstelle : public QObject {

  Q_OBJECT

 private:
  MainWindow* m_main_window;
  VehicleWindow* m_vehicle_window;
  //MessageWindow m_message_window;
  //InfoWindow m_info_window;

  int init();
  int read_vehicles_from_xml();
  int place_vehicles_in_window();
  int show_only_vehicles_with_status(int status);

  std::map<const std::string, std::shared_ptr<Vehicle>> m_vehicles_fire;
  std::map<const std::string, std::shared_ptr<Vehicle>> m_vehicles_ems;
  std::map<const std::string, VehicleLabel*> m_vehicle_labels;

 public:
  Leitstelle();
  ~Leitstelle();

  std::map<const std::string, std::shared_ptr<Vehicle>> get_vehicles_fire();
  std::map<const std::string, std::shared_ptr<Vehicle>> get_vehicles_ems();
  void add_vehicle(std::shared_ptr<Vehicle> vehicle, bool is_fire);

  public slots:
    void update_vehicle_labels(int new_status);
};

#endif //LEITSTELLE_SRC_LEITSTELLE_H_
