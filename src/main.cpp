//
// Created by Johannes on 04.10.2019.
//

#include "main_window.h"
#include "vehicle_window.h"
#include "leitstelle.h"
#include <QApplication>
#include <QtCore/QFile>

int main(int argc, char *argv[]) {

  QApplication a(argc, argv);

  // Setting Stylesheet
  QFile File(":styles.qss");
  File.open(QFile::ReadOnly);
  QString StyleSheet = QLatin1String(File.readAll());
  a.setStyleSheet(StyleSheet);

  auto* leitstelle = new Leitstelle();

  return QApplication::exec();
}