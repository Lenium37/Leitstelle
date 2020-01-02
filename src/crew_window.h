#ifndef CREW_WINDOW_H
#define CREW_WINDOW_H

#include <QMainWindow>

namespace Ui {
class CrewWindow;
}

class CrewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CrewWindow(QWidget *parent = nullptr);
    ~CrewWindow();

private:
    Ui::CrewWindow *ui;
    void display_crew_text();

 private slots:
  void toggle_fullscreen();
};

#endif // CREW_WINDOW_H
