#include "alarm_dialog.h"
#include "ui_alarm_dialog.h"
#include <QStringList>
#include <QComboBox>
#include <iostream>

AlarmDialog::AlarmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->textVehicleList->setReadOnly(true);
    // connect(ui->comboBox, &QComboBox::currentIndexChanged,
    //     this, &AlarmDialog::change_vehicles());
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(indexChanged(int)));
    // QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(check_alarm()));

}

AlarmDialog::~AlarmDialog()
{
    delete ui;
}

void AlarmDialog::check_alarm() {
    if(this->get_current_address() == "") {
        std::cout << "no address provided" << std::endl;
        this->ui->lineEdit->setStyleSheet("border: 1px solid red");
    } else {
        this->accept();
    }
}

void AlarmDialog::set_aao(std::map<const std::string, std::vector<Vehicle>> aao) {
    this->m_aao = aao;
    for (auto const& aao_entry : aao) {
        ui->comboBox->addItems(QStringList() << QString::fromStdString(aao_entry.first));
    }
    this->set_vehicles();
}

void AlarmDialog::set_vehicles() {
    std::string current_text = ui->comboBox->currentText().toStdString();
    std::vector<Vehicle> vehicles = this->m_aao.at(current_text);

    std::string vehicle_text;
    for (Vehicle vehicle : vehicles) {
        vehicle_text = vehicle_text + vehicle.get_name() + "\n";
    }

    ui->textVehicleList->setPlainText(QString::fromStdString(vehicle_text));
}

void AlarmDialog::indexChanged(int index) {
    this->set_vehicles();
}

std::string AlarmDialog::get_current_stichwort() {
    return this->ui->comboBox->currentText().toStdString();
}

std::string AlarmDialog::get_current_freitext() {
    return this->ui->plainTextEdit->toPlainText().toStdString();
}

std::string AlarmDialog::get_current_address() {
    return this->ui->lineEdit->text().toStdString();
}

std::string AlarmDialog::get_current_vehicles() {
    return this->ui->textVehicleList->toPlainText().toStdString();
}

std::string removeSpaces(std::string input) {
  input.erase(std::remove(input.begin(),input.end(),' '),input.end());
  return input;
}

std::string vehicle_type_to_name(std::string vehicle_name, std::map<const std::string, std::shared_ptr<Vehicle>> vehicles_fire, std::map<const std::string, std::shared_ptr<Vehicle>> vehicles_ems, std::string vehicles_translated) {
    for (std::pair<const std::string, std::shared_ptr<Vehicle>> &v : vehicles_fire) {
        Vehicle * vehicle = v.second.get();
        if(removeSpaces(vehicle->get_type_string()) == removeSpaces(vehicle_name)) {
            if(vehicles_translated.find(vehicle->get_vehicle_callout()) == std::string::npos)
                return vehicle->get_vehicle_callout();
        }
    }
    for (std::pair<const std::string, std::shared_ptr<Vehicle>> &v : vehicles_ems) {
        Vehicle * vehicle = v.second.get();
        if(vehicle->get_type_string() == vehicle_name) {
            if(vehicles_translated.find(vehicle->get_vehicle_callout()) == std::string::npos)
                return vehicle->get_vehicle_callout();
        }
    }
    return "";
}


std::string AlarmDialog::get_current_vehicles_translated(std::map<const std::string, std::shared_ptr<Vehicle>> vehicles_fire, std::map<const std::string, std::shared_ptr<Vehicle>> vehicles_ems) {
    std::string vehicles = this->get_current_vehicles();
    std::string vehicles_translated = "";
    size_t start = 0;
    size_t end;
    while (1) {
        std::string vehicle;
        if ((end = vehicles.find("\n", start)) == std::string::npos) {
            if (!(vehicle = vehicles.substr(start)).empty()) {
                vehicles_translated = vehicles_translated + vehicle_type_to_name(vehicle, vehicles_fire, vehicles_ems, vehicles_translated) + "\n";
            }
            break;
        }
        vehicle = vehicles.substr(start, end - start);
        vehicles_translated = vehicles_translated + vehicle_type_to_name(vehicle, vehicles_fire, vehicles_ems, vehicles_translated) + "\n";
        start = end + 1;
    }
    return vehicles_translated;
}