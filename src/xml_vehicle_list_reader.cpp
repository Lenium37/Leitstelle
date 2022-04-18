//
// Created by Johannes on 06.10.2019.
//

#include <iostream>
#include "xml_vehicle_list_reader.h"

XmlVehicleListReader::XmlVehicleListReader() {

}

XmlVehicleListReader::~XmlVehicleListReader() = default;

bool XmlVehicleListReader::read(QIODevice *device, std::map<const std::string, std::shared_ptr<Vehicle>>& vehicles_fire, std::map<const std::string, std::shared_ptr<Vehicle>>& vehicles_ems) {
  QXmlStreamReader reader;
  reader.setDevice(device);
  bool is_fire = true;

  if (reader.readNextStartElement()) {
    if (reader.name() == "vehicles") {
      while (reader.readNextStartElement()) {
        if (reader.name() == "fire")
          is_fire = true;
        else if(reader.name() == "ems")
          is_fire = false;
        else
          reader.skipCurrentElement();

        while (reader.readNextStartElement()) {
          if (reader.name() == "vehicle") {
            int enabled, status, position_in_list;
            std::string city_callout, vehicle_callout, type;

            while (reader.readNextStartElement()) {
              if (reader.name() == "enabled") {
                enabled = reader.readElementText().toInt();
              } else if(reader.name() == "cityCallout") {
                city_callout = reader.readElementText().toStdString();
              } else if(reader.name() == "vehicleCallout") {
                vehicle_callout = reader.readElementText().toStdString();
              } else if(reader.name() == "vehicleType") {
                type = reader.readElementText().toStdString();
              } else if(reader.name() == "vehicleStatus") {
                status = reader.readElementText().toInt();
              } else if(reader.name() == "positionInList") {
                position_in_list = reader.readElementText().toInt();
              } else {
                  reader.skipCurrentElement();
              }
            }
            if (enabled) {
              std::shared_ptr<Vehicle> vehicle = std::make_shared<Vehicle>(enabled, city_callout, vehicle_callout, type, status, position_in_list);
              if(is_fire) {
                vehicles_fire.insert(std::pair<std::string, std::shared_ptr<Vehicle>>(vehicle->get_name(), vehicle));
              }
              else {
                //std::cout << "adding ems vehicle " << vehicle->get_name() << std::endl;
                vehicles_ems.insert(std::pair<std::string, std::shared_ptr<Vehicle>>(vehicle->get_name(), vehicle));
              }
            }
          } else {
            reader.skipCurrentElement();
          }
        }
      }
    } else {
      reader.raiseError(QObject::tr("Not a vehicle file"));
    }
  }

  device->close();
  return !reader.error();
}

bool XmlVehicleListReader::read_aao(QIODevice *device, std::map<const std::string, std::vector<Vehicle>>& m_aao) {
  QXmlStreamReader reader;
  reader.setDevice(device);

  if (reader.readNextStartElement()) {
    if (reader.name() == "stichwoerter") {
      while (reader.readNextStartElement()) {
        if (reader.name() == "stichwort") {
          std::string name, name_acronym;
          std::vector<Vehicle> vehicles;

          while (reader.readNextStartElement()) {
            if (reader.name() == "name") {
              name = reader.readElementText().toStdString();
            } else if(reader.name() == "name_acronym") {
              name_acronym = reader.readElementText().toStdString();
            } else if(reader.name() == "vehicles") {
              while (reader.readNextStartElement()) {
                std::string vehicle = reader.readElementText().toStdString();
                vehicles.push_back(Vehicle(false, "", vehicle, vehicle, 1, 0));
              }
            } else {
                reader.skipCurrentElement();
            }
          }
          m_aao.insert(std::pair<const std::string, std::vector<Vehicle>>(name_acronym, vehicles));

        } else {
            reader.skipCurrentElement();
        }
      }
    } else {
      reader.raiseError(QObject::tr("Not an AAO file"));
    }
  }

  device->close();
  return !reader.error();
  }