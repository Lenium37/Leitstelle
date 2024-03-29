#ifndef INFO_WINDOW_H
#define INFO_WINDOW_H

#include <QMainWindow>

namespace Ui {
class InfoWindow;
}

class InfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfoWindow(QWidget *parent = nullptr);
    ~InfoWindow();

private:
    Ui::InfoWindow *ui;
    void insert_info_texts();

private slots:
    void toggle_fullscreen();

};

#endif // INFO_WINDOW_H
