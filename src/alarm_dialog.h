#ifndef ALARM_DIALOG_H
#define ALARM_DIALOG_H

#include <QDialog>
#include <QFile>
// #include "xml_aao_reader.h"
#include "vehicle.h"

namespace Ui {
class AlarmDialog;
}

class AlarmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmDialog(QWidget *parent = nullptr);
    ~AlarmDialog();
    void set_aao(std::map<const std::string, std::vector<Vehicle>> aao);
    void set_vehicles();
    std::string get_current_stichwort();
    std::string get_current_freitext();
    std::string get_current_address();
    std::string get_current_vehicles();
    std::string get_current_vehicles_translated(std::map<const std::string, std::shared_ptr<Vehicle>> vehicles_fire, std::map<const std::string, std::shared_ptr<Vehicle>> vehicles_ems);

    // void add_AAO(QFile aao_file);

private:
    Ui::AlarmDialog *ui;
    std::map<const std::string, std::vector<Vehicle>> m_aao;
    // std::map<const std::string, std::vector<Vehicle>> m_aao;

private slots:
    void indexChanged(int index);
    void check_alarm();

};

#endif // ALARM_DIALOG_H
