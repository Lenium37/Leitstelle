#include "info_window.h"
#include "ui_info_window.h"
#include "digital_clock.h"

InfoWindow::InfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);

  auto* info_clock = new DigitalClock();
  info_clock->setStyleSheet("font-size: 20px;");
  this->findChild<QHBoxLayout *>("clockLayout")->addWidget(info_clock);
}

InfoWindow::~InfoWindow()
{
    delete ui;
}
