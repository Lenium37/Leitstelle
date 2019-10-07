//
// Created by Johannes on 07.10.2019.
//

#include <iostream>
#include "vehicle_label_menu.h"

VehicleLabelMenu::VehicleLabelMenu(VehicleLabel *parent) :
    QMenu(nullptr) {
  this->m_parent_label = parent;
  //this->addAction("Print current status", this, &VehicleLabelMenu::print_current_status);
  QMenu* submenu = this->addMenu("Change status");
  submenu->addAction("0", this->m_parent_label, &VehicleLabel::status_changed);
  submenu->addAction("1", this->m_parent_label, &VehicleLabel::status_changed);
  submenu->addAction("2", this->m_parent_label, &VehicleLabel::status_changed);
  submenu->addAction("3", this->m_parent_label, &VehicleLabel::status_changed);
  submenu->addAction("4", this->m_parent_label, &VehicleLabel::status_changed);
  submenu->addAction("5", this->m_parent_label, &VehicleLabel::status_changed);
  submenu->addAction("6", this->m_parent_label, &VehicleLabel::status_changed);
  submenu->addAction("7", this->m_parent_label, &VehicleLabel::status_changed);
  submenu->addAction("8", this->m_parent_label, &VehicleLabel::status_changed);
}

void VehicleLabelMenu::showMenu(const QPoint &pos) {
  exec(QCursor::pos());
}

void VehicleLabelMenu::print_current_status() {
  std::cout << "current status is " << this->m_parent_label->get_status() << std::endl;
}