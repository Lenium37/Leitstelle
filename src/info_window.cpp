#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "info_window.h"
#include "ui_info_window.h"
#include "digital_clock.h"

InfoWindow::InfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
  ui->setupUi(this);

  // add clock
  auto* info_clock = new DigitalClock();
  info_clock->setStyleSheet("font-size: 20px;"); // does not do anything
  this->findChild<QHBoxLayout *>("clockLayout")->addWidget(info_clock);

  // insert info texts into textareas
  this->insert_info_texts();
}

InfoWindow::~InfoWindow()
{
    delete ui;
}

void InfoWindow::insert_info_texts() {
  QFile file1(":info_notfallpraxis.txt");
  if (!file1.open(QFile::ReadOnly | QFile::Text)) std::cerr << "could not open info1 file!" << std::endl;
  QTextStream in1(&file1);
  in1.setCodec("UTF-8");
  this->findChild<QTextBrowser *>("info1")->setFontPointSize(15);
  this->findChild<QTextBrowser *>("info1")->setFrameStyle(QFrame::NoFrame);
  this->findChild<QTextBrowser *>("info1")->setText(in1.readAll());

  QFile file2(":info_notfallpraxis-kinder.txt");
  if (!file2.open(QFile::ReadOnly | QFile::Text)) std::cerr << "could not open info2 file!" << std::endl;
  QTextStream in2(&file2);
  in2.setCodec("UTF-8");
  this->findChild<QTextBrowser *>("info2")->setFontPointSize(15);
  this->findChild<QTextBrowser *>("info2")->setFrameStyle(QFrame::NoFrame);
  this->findChild<QTextBrowser *>("info2")->setText(in2.readAll());

  QFile file3(":info_apotheken-notdienst.txt");
  if (!file3.open(QFile::ReadOnly | QFile::Text)) std::cerr << "could not open info3 file!" << std::endl;
  QTextStream in3(&file3);
  in3.setCodec("UTF-8");
  this->findChild<QTextBrowser *>("info3")->setFontPointSize(15);
  this->findChild<QTextBrowser *>("info3")->setFrameStyle(QFrame::NoFrame);
  this->findChild<QTextBrowser *>("info3")->setText(in3.readAll());

  QFile file4(":info_zahnaerztlicher-notdienst.txt");
  if (!file4.open(QFile::ReadOnly | QFile::Text)) std::cerr << "could not open info4 file!" << std::endl;
  QTextStream in4(&file4);
  in4.setCodec("UTF-8");
  this->findChild<QTextBrowser *>("info4")->setFontPointSize(15);
  this->findChild<QTextBrowser *>("info4")->setFrameStyle(QFrame::NoFrame);
  this->findChild<QTextBrowser *>("info4")->setText(in4.readAll());

  QFile file5(":info_augenaerztlicher-notdienst.txt");
  if (!file5.open(QFile::ReadOnly | QFile::Text)) std::cerr << "could not open info5 file!" << std::endl;
  QTextStream in5(&file5);
  in5.setCodec("UTF-8");
  this->findChild<QTextBrowser *>("info5")->setFontPointSize(15);
  this->findChild<QTextBrowser *>("info5")->setFrameStyle(QFrame::NoFrame);
  this->findChild<QTextBrowser *>("info5")->setText(in5.readAll());

  QFile file6(":info_tieraerztlicher-notdienst.txt");
  if (!file6.open(QFile::ReadOnly | QFile::Text)) std::cerr << "could not open info6 file!" << std::endl;
  QTextStream in6(&file6);
  in6.setCodec("UTF-8");
  this->findChild<QTextBrowser *>("info6")->setFontPointSize(15);
  this->findChild<QTextBrowser *>("info6")->setFrameStyle(QFrame::NoFrame);
  this->findChild<QTextBrowser *>("info6")->setText(in6.readAll());

}
