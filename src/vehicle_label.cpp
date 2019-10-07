//
// Created by Johannes on 07.10.2019.
//

#include "vehicle_label.h"
#include <QtXml> // ??? needed for setProperty to work
#include <iostream>
#include <QAction>

const std::string VehicleLabel::get_text() {
  return this->m_text;
}

void VehicleLabel::set_text(const std::string &text) {
  this->m_text = text;
}

const int VehicleLabel::get_status() {
  return this->m_status;
}

void VehicleLabel::set_status(const int &status) {
  this->m_status = status;
  switch(status) {
    case 0:
      this->setProperty("class", "vehicleLabelStatus0");
      break;
    case 1:
      this->setProperty("class", "vehicleLabelStatus1");
      break;
    case 2:
      this->setProperty("class", "vehicleLabelStatus2");
      break;
    case 3:
      this->setProperty("class", "vehicleLabelStatus3");
      break;
    case 4:
      this->setProperty("class", "vehicleLabelStatus4");
      break;
    case 5:
      this->setProperty("class", "vehicleLabelStatus5");
      break;
    case 6:
      this->setProperty("class", "vehicleLabelStatus6");
      break;
    case 7:
      this->setProperty("class", "vehicleLabelStatus7");
      break;
    case 8:
      this->setProperty("class", "vehicleLabelStatus8");
      break;
    default:
      break;
  }
}

void VehicleLabel::status_changed() {
  auto* action = qobject_cast<QAction*>(sender());
  if (!action) {
    return;
  }
  int new_status = std::stoi(action->text().toStdString());
  this->set_status(new_status);
  switch(new_status) {
    case 0:
      this->setStyleSheet("background-color: rgb(255, 0, 0);");
      break;
    case 1:
      this->setStyleSheet("background-color: rgb(200, 255, 255);");
      break;
    case 2:
      this->setStyleSheet("background-color: rgb(0, 255, 0);");
      break;
    case 3:
      this->setStyleSheet("background-color: rgb(255, 255, 0);");
      break;
    case 4:
      this->setStyleSheet("background-color: rgb(255, 150, 0);");
      break;
    case 5:
      this->setStyleSheet("background-color: rgb(255, 255, 255);");
      break;
    case 6:
      this->setStyleSheet("background-color: rgb(90, 90, 90);");
      break;
    case 7:
      this->setStyleSheet("background-color: rgb(0, 255, 255);");
      break;
    case 8:
      this->setStyleSheet("background-color: rgb(0, 100, 255);");
      break;
    default:
      break;
  }

}
