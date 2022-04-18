//
// Created by Johannes on 09.10.2019.
//

#ifndef LEITSTELLE_SRC_DIGITAL_TIMER_H_
#define LEITSTELLE_SRC_DIGITAL_TIMER_H_

#include <QtWidgets/QLCDNumber>
#include <QtCore/QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <iostream>

class DigitalTimer : public QLCDNumber
{
  Q_OBJECT

 public:
  DigitalTimer(QWidget *parent = nullptr) : QLCDNumber(parent) {
    this->setDigitCount(8);
    this->setSegmentStyle(Flat);
    this->setFrameShape(QFrame::NoFrame);
    this->setMinimumHeight(50);

    this->start_timer = new QElapsedTimer();
    this->start_timer->start();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalTimer::showTime);
    timer->start(1000);

    showTime();
  }

private:
  QElapsedTimer* start_timer;

 private slots:
      void showTime() {
        QTime time_empty = QTime(0, 0, 0);
        int time_elapsed_msecs = this->start_timer->elapsed();
        QTime time_elapsed = time_empty.addMSecs(time_elapsed_msecs);
        QString text = time_elapsed.toString("hh:mm:ss");
        this->display(text);
  };
};


#endif //LEITSTELLE_SRC_DIGITAL_CLOCK_H_
