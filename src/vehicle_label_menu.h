//
// Created by Johannes on 07.10.2019.
//

#ifndef LEITSTELLE_SRC_VEHICLE_LABEL_MENU_H_
#define LEITSTELLE_SRC_VEHICLE_LABEL_MENU_H_

#include <QMenu>
#include "vehicle_label.h"

class VehicleLabelMenu : public QMenu {
    Q_OBJECT
 public:
  explicit VehicleLabelMenu(VehicleLabel *parent = 0);

 signals:

 public slots:
  void showMenu(const QPoint &pos);
  void print_current_status();

 private:
  VehicleLabel* m_parent_label;

};

#endif //LEITSTELLE_SRC_VEHICLE_LABEL_MENU_H_
