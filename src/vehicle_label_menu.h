//
// Created by Johannes on 07.10.2019.
//

#ifndef LEITSTELLE_SRC_VEHICLE_LABEL_MENU_H_
#define LEITSTELLE_SRC_VEHICLE_LABEL_MENU_H_

#include <QMenu>

class VehicleLabelMenu : public QMenu {
    Q_OBJECT
   public:
    explicit VehicleLabelMenu(QWidget *parent = 0);

    signals:

   public slots:
        void showMenu(const QPoint &pos);

};

#endif //LEITSTELLE_SRC_VEHICLE_LABEL_MENU_H_
