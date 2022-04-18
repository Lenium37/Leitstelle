#include "alarm_window.h"
#include "ui_alarm_window.h"
#include "digital_timer.h"
#include <QtWidgets/QShortcut>

AlarmWindow::AlarmWindow(std::string stichwort, std::string vehicles, std::string freitext, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlarmWindow)
{
    ui->setupUi(this);

    QShortcut * toggleFuillscreenShortcut = new QShortcut(QKeySequence("F11"), this);
    QObject::connect(toggleFuillscreenShortcut, SIGNAL(activated()), this, SLOT(toggle_fullscreen()));

    ui->vehicles_text->setReadOnly(true);
    ui->freitext_text->setReadOnly(true);

    ui->stichwort_text->setText(QString::fromStdString(stichwort));
    ui->vehicles_text->setPlainText(QString::fromStdString(vehicles));
    ui->freitext_text->setPlainText(QString::fromStdString(freitext));
        

    auto* info_clock = new DigitalTimer();
    this->findChild<QHBoxLayout *>("timer_layout")->addWidget(info_clock, Qt::AlignCenter);
}

AlarmWindow::~AlarmWindow()
{
    delete ui;
}

void AlarmWindow::toggle_fullscreen() {
  isFullScreen() ? showMaximized() : showFullScreen();
}