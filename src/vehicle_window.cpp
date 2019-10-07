//
// Created by Johannes on 04.10.2019.
//

#include <iostream>
#include "vehicle_window.h"
#include "ui_vehicle_window.h"

VehicleWindow::VehicleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VehicleWindow)
{
    ui->setupUi(this);
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

