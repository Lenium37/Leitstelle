//
// Created by Johannes on 06.10.2019.
//

// #include <iostream>
#include "xml_aao_reader.h"

XmlAAOReader::XmlAAOReader() {

}

XmlAAOReader::~XmlAAOReader() = default;

// bool XmlAAOReader::read(QIODevice *device, std::map<const std::string, std::vector<Vehicle>>& aao) {
bool XmlAAOReader::read(QIODevice *device) {
  QXmlStreamReader reader;
  reader.setDevice(device);
  std::map<const std::string, std::vector<Vehicle>> aao;

  if (reader.readNextStartElement()) {
    if (reader.name() == "type_of_calls") {
      while (reader.readNextStartElement()) {
        if (reader.name() == "call") {
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
          aao.insert(std::pair<const std::string, std::vector<Vehicle>>(name_acronym, vehicles));

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
