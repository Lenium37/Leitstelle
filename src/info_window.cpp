#include "info_window.h"
#include "ui_info_window.h"

InfoWindow::InfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
}

InfoWindow::~InfoWindow()
{
    delete ui;
}
