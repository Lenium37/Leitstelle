//
// Created by Johannes on 07.10.2019.
//

#include "vehicle_label_menu.h"

VehicleLabelMenu::VehicleLabelMenu(QWidget *parent) :
    QMenu(parent) {
  addAction("Action1");
}
void VehicleLabelMenu::showMenu(const QPoint &pos) {
  exec(QCursor::pos());
}