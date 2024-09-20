#ifndef SHIPMENT_MANAGER_H
#define SHIPMENT_MANAGER_H

#include <vector>
#include "Shipment.h"
#include <iostream>

class ShipmentManager {
public:
    void addShipment(Shipment* shipment);
    void deleteShipment(int ID);
    Shipment* getShipment(int ID);
    void viewShipment();
    void viewShipment(int ID);
    void clearShipment();

    void dispatchShipment(int ID);

    ~ShipmentManager();
private:
    std::vector<Shipment*> shipments;
};

#endif // SHIPMENT_MANAGER_H
