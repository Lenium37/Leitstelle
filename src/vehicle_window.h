//
// Created by Johannes on 04.10.2019.
//

#ifndef LEITSTELLE_SRC_VEHICLE_WINDOW_H_
#define LEITSTELLE_SRC_VEHICLE_WINDOW_H_

#include <QtWidgets/QMainWindow>

namespace Ui {
  class VehicleWindow;
}

class VehicleWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit VehicleWindow(QWidget *parent = nullptr);
  ~VehicleWindow();

 private slots:

 private:
  Ui::VehicleWindow *ui;

};

#endif //LEITSTELLE_SRC_VEHICLE_WINDOW_H_
