//
// Created by Johannes on 06.10.2019.
//

// #ifndef LEITSTELLE_SRC_XML_AAO_READER_H_
// #define LEITSTELLE_SRC_XML_AAO_READER_H_

#include <QtCore/QIODevice>
#include <QtCore/QXmlStreamReader>
#include "vehicle.h"

class XmlAAOReader {
 public:
  XmlAAOReader();
  ~XmlAAOReader();
  // static bool read(QIODevice *device, std::map<const std::string, std::vector<Vehicle>>& m_aao);
  static bool read(QIODevice *device);

};

// #endif //LEITSTELLE_SRC_XML_AAO_READER_H_
