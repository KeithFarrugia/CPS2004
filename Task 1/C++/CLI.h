#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <memory>

#include "InputHandler.h"
#include "Components/TransportManager.h"
#include "Components/ShipmentManager.h"
#include "Components/Stock.h"

class CLI{
public:
    static void MainMenu(ShipmentManager* shipmentManager, TransportManager* transportManager, Stock* stock);

    static void StockUtilityMenu(Stock* s);

    static void TransportUtilityMenu(TransportManager* transportManager);
    

    static void ShipmentUtilityMenu(ShipmentManager* shipmentManager, TransportManager* transportManager, Stock* stock);
    static void ShipmentEdit(Shipment* shipment, TransportManager* transportManager, Stock* stock);
    static void ShipmentAddProduct(Shipment* shipment, Stock* stock);
    
private:
    // Generic Menu with error handling
    static int Menu(std::string menu, int rangeOptions);

    // Goes through a menu of the product hierarchy
    static int createProduct(Product* p); 

    static Product* ProductMenu(); 
    static Transport* TransportMenu(); 
};

#endif //CLI_H