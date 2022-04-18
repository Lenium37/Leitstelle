#ifndef ALARM_WINDOW_H
#define ALARM_WINDOW_H

#include <QMainWindow>

namespace Ui {
class AlarmWindow;
}

class AlarmWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlarmWindow(std::string stichwort, std::string vehicles, std::string freitext, QWidget *parent = nullptr);
    ~AlarmWindow();

private:
    Ui::AlarmWindow *ui;

private slots:
    void toggle_fullscreen();
};

#endif // ALARM_WINDOW_H
