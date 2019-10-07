//
// Created by Johannes on 07.10.2019.
//

#ifndef LEITSTELLE_SRC_VEHICLE_LABEL_H_
#define LEITSTELLE_SRC_VEHICLE_LABEL_H_

#include <QLabel>

class VehicleLabel : public QLabel {
  Q_OBJECT
 private:
  std::string m_text;
  int m_status;

 public:
  VehicleLabel(const QString &text, QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags()) :
      QLabel(text, parent, f){
    this->set_text(text.toStdString());
  }
  ~VehicleLabel() = default;

  const std::string get_text();
  void set_text(const std::string &text);

  const int get_status();
  void set_status(const int& status);


};

#endif //LEITSTELLE_SRC_VEHICLE_LABEL_H_
