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
#include "info_window.h"
#include "crew_window.h"
#include "leitstellenwindow.h"
#include "alarm_dialog.h"
#include "alarm_window.h"

class Leitstelle : public QObject {

  Q_OBJECT

 private:
  MainWindow* m_main_window;
  VehicleWindow* m_vehicle_window;
  InfoWindow* m_info_window;
  CrewWindow* m_crew_window;
  LeitstellenWindow* m_leitstellen_window;
  AlarmDialog* m_alarm_dialog;
  AlarmWindow* m_alarm_window;

  int init();
  int read_vehicles_from_xml();
  int place_vehicles_in_window();
  int show_only_vehicles_with_status(int status);
  void new_alarm_dialog();
  void read_aao();

  std::map<const std::string, std::shared_ptr<Vehicle>> m_vehicles_fire;
  std::map<const std::string, std::shared_ptr<Vehicle>> m_vehicles_ems;
  std::map<const std::string, VehicleLabel*> m_vehicle_labels;
  std::map<const std::string, std::vector<Vehicle>> m_aao;

 public:
  Leitstelle();
  ~Leitstelle();

  std::map<const std::string, std::shared_ptr<Vehicle>> get_vehicles_fire();
  std::map<const std::string, std::shared_ptr<Vehicle>> get_vehicles_ems();
  void add_vehicle(std::shared_ptr<Vehicle> vehicle, bool is_fire);

  public slots:
    void update_vehicle_labels(int new_status);
    void dialogIsFinished(int result);
};

#endif //LEITSTELLE_SRC_LEITSTELLE_H_
