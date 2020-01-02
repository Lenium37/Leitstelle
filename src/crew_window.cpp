#include <QtWidgets/QShortcut>
#include <QtCore/QFile>
#include <iostream>
#include <QtCore/QTextStream>
#include "crew_window.h"
#include "ui_crew_window.h"

CrewWindow::CrewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CrewWindow)
{
  ui->setupUi(this);
  QShortcut * toggleFuillscreenShortcut = new QShortcut(QKeySequence("F11"), this);
  QObject::connect(toggleFuillscreenShortcut, SIGNAL(activated()), this, SLOT(toggle_fullscreen()));

  this->display_crew_text();
}

CrewWindow::~CrewWindow()
{
    delete ui;
}

void CrewWindow::toggle_fullscreen() {
  isFullScreen() ? showMaximized() : showFullScreen();
}

void CrewWindow::display_crew_text() {

  // crew
  QFile file(":crew.txt");
  if (!file.open(QFile::ReadOnly | QFile::Text)) std::cerr << "could not open crew file!" << std::endl;
  QTextStream in(&file);
  in.setCodec("UTF-8");
  this->findChild<QTextBrowser *>("crew")->setFontPointSize(25);
  this->findChild<QTextBrowser *>("crew")->setFrameStyle(QFrame::NoFrame);
  this->findChild<QTextBrowser *>("crew")->setText(in.readAll());

  // running text
  this->findChild<QGraphicsView *>("running_text")->setFrameStyle(QFrame::NoFrame);
}