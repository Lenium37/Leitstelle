//
// Created by Johannes on 04.10.2019.
//

#include "vehicle_window.h"
#include "ui_vehicle_window.h"

VehicleWindow::VehicleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VehicleWindow)
{
    ui->setupUi(this);
}

VehicleWindow::~VehicleWindow()
{
  delete ui;
}
