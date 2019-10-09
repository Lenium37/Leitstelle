//
// Created by Johannes on 09.10.2019.
//

#ifndef LEITSTELLE_SRC_DIGITAL_CLOCK_H_
#define LEITSTELLE_SRC_DIGITAL_CLOCK_H_

#include <QtWidgets/QLCDNumber>
#include <QtCore/QTime>
#include <QTimer>
#include <iostream>

class DigitalClock : public QLCDNumber
{
  Q_OBJECT

 public:
  //DigitalClock(QWidget *parent = nullptr);
  DigitalClock(QWidget *parent = nullptr) : QLCDNumber(parent) {
    this->setDigitCount(8);
    setSegmentStyle(Filled);
    this->setStyleSheet("font-size: 20px;");

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
    timer->start(1000);

    showTime();

    setWindowTitle(tr("Digital Clock"));
    resize(250, 60);
  }

 private slots:
      void showTime() {
        QTime time = QTime::currentTime();
        QString text = time.toString("hh:mm:ss");
        this->display(text);

        //display("20:24:22");
  };
};

/*DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent) {
  setSegmentStyle(Filled);

  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
  timer->start(1000);

  showTime();

  setWindowTitle(tr("Digital Clock"));
  resize(150, 60);
}

void DigitalClock::showTime()
{
  QTime time = QTime::currentTime();
  QString text = time.toString("hh:mm");
  if ((time.second() % 2) == 0)
    text[2] = ' ';
  display(text);
}*/

#endif //LEITSTELLE_SRC_DIGITAL_CLOCK_H_
