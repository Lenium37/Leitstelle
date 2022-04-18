#ifndef LEITSTELLENWINDOW_H
#define LEITSTELLENWINDOW_H

#include <QtWidgets/QMainWindow>

namespace Ui {
class LeitstellenWindow;
}

class LeitstellenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LeitstellenWindow(QWidget *parent = nullptr);
    ~LeitstellenWindow();

    std::string get_aktuelle_einsaetze();
    void set_aktuelle_einsaetze(std::string new_text);
    void open_new_einsatz(std::string new_einsatz);

    signals:
    void alarm_button_clicked();

private:
    Ui::LeitstellenWindow *ui;

private slots:
    void toggle_fullscreen();
    void close_einsatz();
};

#endif // LEITSTELLENWINDOW_H
