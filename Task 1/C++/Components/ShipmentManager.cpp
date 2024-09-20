#include "ShipmentManager.h"

void ShipmentManager::addShipment(Shipment* newShipment) {
    // Check if shipment ID is already in use
    if(getShipment(newShipment->getID()) == nullptr){
        shipments.push_back(newShipment);
        printf("\n------Shipment Added------\n");
        printf(  "--------Code: %d--------\n",newShipment->getID());
        newShipment->updateCost();
        return;
    }
    printf("\nERROR: ID Already in Use\n");
}

void ShipmentManager::deleteShipment(int ID) {
    for(int i = 0; i<shipments.size(); i++){

        if(shipments[i]->getID() == ID){
            // Memory Management
            if(shipments[i]->getIsDispatched() == false){
                shipments[i]->getProductList()->clearStock();
                delete shipments[i]->getTransport();

                shipments.erase(shipments.begin() + i);
                printf("\nDeleted Succesfully\n");
            }
            printf("ERROR: Cannnot change shipment since it has been dispatched\n");
            return;
        }
    }
    printf("\nERROR: ID NOT found\n");
}

void ShipmentManager::viewShipment(){
    for(Shipment* shipment : shipments){
        printf("\nID: %d\n",shipment->getID());
        printf("Custumer: %s\n",shipment->getCustomer().c_str());
        printf("Distance: %f\n",shipment->getDistance());
        printf("Total Cost: %.2f\n",shipment->getCost());
        printf("Estimated Time: %.2f\n",shipment->calculateTime());
        printf("Is dispatched: %s\n", (shipment->getIsDispatched()? "true" : "false"));
        printf("=============Transport============= \n%s\n", shipment->getTransport()->to_string().c_str());
        printf("\n=============Stock=============\n");
        shipment->getProductList()->displayStock();
    }
}
void ShipmentManager::viewShipment(int ID){
    Shipment* shipment = getShipment(ID);
    if(shipment != nullptr){
        printf("\nID: %d\n",shipment->getID());
        printf("Custumer: %s\n",shipment->getCustomer().c_str());
        printf("Distance: %f\n",shipment->getDistance());
        printf("Total Cost: %.2f\n",shipment->getCost());
        printf("Estimated Time: %.2f\n",shipment->calculateTime());
        printf("Is dispatched: %s\n", (shipment->getIsDispatched()? "true" : "false"));
        printf("=============Transport============= \n%s\n", shipment->getTransport()->to_string().c_str());
        printf("\n=============Stock=============\n");
        shipment->getProductList()->displayStock();
        return;
    }
    printf("\nERROR: ID NOT found\n");
}

Shipment* ShipmentManager::getShipment(int ID){
    for (Shipment* shipment : shipments) {
        if (shipment->getID() == ID) {
            return shipment;
        }
    }
    return nullptr;
}

void ShipmentManager::clearShipment(){
    for(Shipment* s : shipments){
        s->deleteShipment();
        delete s;
    }
    shipments.clear();
}

void ShipmentManager::dispatchShipment(int ID){
    Shipment* shipment = getShipment(ID);
    if(shipment != nullptr){
        shipment->setDispatched(true);
        return;
    }
}




ShipmentManager::~ShipmentManager(){
    clearShipment();
}
