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

  int get_current_status_displayed();

 public slots:
  void status_button_clicked();

 signals:
  void status_displayed_changed(int new_status);

 private:
  Ui::VehicleWindow *ui;
  int m_current_status_displayed;

  private slots:
    void toggle_fullscreen();

};

#endif //LEITSTELLE_SRC_VEHICLE_WINDOW_H_
