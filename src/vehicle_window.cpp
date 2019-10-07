//
// Created by Johannes on 04.10.2019.
//

#include <iostream>
#include "vehicle_window.h"
#include "ui_vehicle_window.h"

VehicleWindow::VehicleWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::VehicleWindow) {
  ui->setupUi(this);
  ui->gridLayoutVehiclesFire->setColumnStretch(0, 1);
  ui->gridLayoutVehiclesFire->setColumnStretch(1, 1);
  ui->gridLayoutVehiclesFire->setColumnStretch(2, 1);
  ui->gridLayoutVehiclesFire->setColumnStretch(3, 1);
  ui->gridLayoutVehiclesFire->setColumnStretch(4, 1);
  ui->gridLayoutVehiclesFire->setRowStretch(0, 1);
  ui->gridLayoutVehiclesFire->setRowStretch(1, 1);
  ui->gridLayoutVehiclesFire->setRowStretch(2, 1);
  ui->gridLayoutVehiclesFire->setRowStretch(3, 1);
  ui->gridLayoutVehiclesFire->setRowStretch(4, 1);
  ui->gridLayoutVehiclesFire->setRowStretch(5, 1);

  ui->gridLayoutVehiclesEms->setColumnStretch(0, 1);
  ui->gridLayoutVehiclesEms->setColumnStretch(1, 1);
  ui->gridLayoutVehiclesEms->setColumnStretch(2, 1);
  ui->gridLayoutVehiclesEms->setColumnStretch(3, 1);
  ui->gridLayoutVehiclesEms->setColumnStretch(4, 1);
  ui->gridLayoutVehiclesEms->setRowStretch(0, 1);
  ui->gridLayoutVehiclesEms->setRowStretch(1, 1);
  ui->gridLayoutVehiclesEms->setRowStretch(2, 1);
  ui->gridLayoutVehiclesEms->setRowStretch(3, 1);

  ui->gridLayoutVehiclesFire->setRowMinimumHeight(0, 60);
  ui->gridLayoutVehiclesFire->setRowMinimumHeight(1, 60);
  ui->gridLayoutVehiclesFire->setRowMinimumHeight(2, 60);
  ui->gridLayoutVehiclesFire->setRowMinimumHeight(3, 60);
  ui->gridLayoutVehiclesFire->setRowMinimumHeight(4, 60);
  ui->gridLayoutVehiclesFire->setRowMinimumHeight(5, 60);
  ui->gridLayoutVehiclesFire->setColumnMinimumWidth(0, 120);
  ui->gridLayoutVehiclesFire->setColumnMinimumWidth(1, 120);
  ui->gridLayoutVehiclesFire->setColumnMinimumWidth(2, 120);
  ui->gridLayoutVehiclesFire->setColumnMinimumWidth(3, 120);
  ui->gridLayoutVehiclesFire->setColumnMinimumWidth(4, 120);

  ui->gridLayoutVehiclesEms->setRowMinimumHeight(0, 60);
  ui->gridLayoutVehiclesEms->setRowMinimumHeight(1, 60);
  ui->gridLayoutVehiclesEms->setRowMinimumHeight(2, 60);
  ui->gridLayoutVehiclesEms->setRowMinimumHeight(3, 60);
  ui->gridLayoutVehiclesEms->setColumnMinimumWidth(0, 120);
  ui->gridLayoutVehiclesEms->setColumnMinimumWidth(1, 120);
  ui->gridLayoutVehiclesEms->setColumnMinimumWidth(2, 120);
  ui->gridLayoutVehiclesEms->setColumnMinimumWidth(3, 120);
  ui->gridLayoutVehiclesEms->setColumnMinimumWidth(4, 120);

  QObject::connect(ui->pushButtonStatus0, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatus1, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatus2, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatus3, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatus4, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatus5, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatus6, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatus7, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatus8, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
  QObject::connect(ui->pushButtonStatusAlle, &QPushButton::clicked, this, &VehicleWindow::status_button_clicked);
}

VehicleWindow::~VehicleWindow()
{
  delete ui;
}

void VehicleWindow::status_button_clicked() {
  int new_status = -1;
  if(QObject::sender()->objectName().toStdString() == "pushButtonStatus0")
    new_status = 0;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatus1")
    new_status = 1;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatus2")
    new_status = 2;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatus3")
    new_status = 3;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatus4")
    new_status = 4;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatus5")
    new_status = 5;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatus6")
    new_status = 6;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatus7")
    new_status = 7;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatus8")
    new_status = 8;
  else if(QObject::sender()->objectName().toStdString() == "pushButtonStatusAlle")
    new_status = -1;
  this->m_current_status_displayed = new_status;

  emit status_displayed_changed(new_status);
}

int VehicleWindow::get_current_status_displayed() {
  return this->m_current_status_displayed;
}

