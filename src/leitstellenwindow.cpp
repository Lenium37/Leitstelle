#include "leitstellenwindow.h"
#include "ui_leitstellenwindow.h"
#include <QtWidgets/QShortcut>
#include <iostream>

LeitstellenWindow::LeitstellenWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LeitstellenWindow)
{
    ui->setupUi(this);
    
    QShortcut * toggleFuillscreenShortcut = new QShortcut(QKeySequence("F11"), this);
    QObject::connect(toggleFuillscreenShortcut, SIGNAL(activated()), this, SLOT(toggle_fullscreen()));
    
    QShortcut * closeEinsatzShortcut = new QShortcut(QKeySequence("DEL"), this);
    QObject::connect(closeEinsatzShortcut, SIGNAL(activated()), this, SLOT(close_einsatz()));


    // ui->aktuelleEinsaetze->setReadOnly(true);
    // ui->alteEinsaetze->setReadOnly(true);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &LeitstellenWindow::alarm_button_clicked);
}

LeitstellenWindow::~LeitstellenWindow()
{
    delete ui;
}

std::string LeitstellenWindow::get_aktuelle_einsaetze() {
    // return this->ui->aktuelleEinsaetze->toPlainText().toStdString();
    // this->ui->aktuelleEinsaetze->text
}

// void LeitstellenWindow::set_aktuelle_einsaetze(std::string new_text) {
//     this->ui->aktuelleEinsaetze->setPlainText(QString::fromStdString(new_text));
// }

void LeitstellenWindow::open_new_einsatz(std::string new_einsatz) {
    this->ui->aktuelleEinsaetze->addItem(QString::fromStdString(new_einsatz));
}

void LeitstellenWindow::toggle_fullscreen() {
  isFullScreen() ? showMaximized() : showFullScreen();
}

void LeitstellenWindow::close_einsatz() {
    QList<QListWidgetItem*> items = this->ui->aktuelleEinsaetze->selectedItems();
    foreach(QListWidgetItem * item, items) {
        this->ui->alteEinsaetze->addItem(this->ui->aktuelleEinsaetze->takeItem(this->ui->aktuelleEinsaetze->row(item)));
    }
}