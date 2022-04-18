//
// Created by Johannes on 06.10.2019.
//

#ifndef LEITSTELLE_SRC_XML_VEHICLE_LIST_READER_H_
#define LEITSTELLE_SRC_XML_VEHICLE_LIST_READER_H_

#include <QtCore/QIODevice>
#include <QtCore/QXmlStreamReader>
#include "vehicle.h"

class XmlVehicleListReader {
 public:
  XmlVehicleListReader();
  ~XmlVehicleListReader();
  static bool read(QIODevice *device, std::map<const std::string, std::shared_ptr<Vehicle>>& vehicles_fire, std::map<const std::string, std::shared_ptr<Vehicle>>& vehicles_ems);
  static bool read_aao(QIODevice *device, std::map<const std::string, std::vector<Vehicle>>& m_aao);

};

#endif //LEITSTELLE_SRC_XML_VEHICLE_LIST_READER_H_
