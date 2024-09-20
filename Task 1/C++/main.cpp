#include <iostream>
#include "Components/Product_Include.h"
#include "Components/Stock.h"
#include "Components/Shipment.h"
#include "CLI.h"
int main(int, char**){
    Stock stock;
    ShipmentManager shipments;
    TransportManager transports;
    CLI::MainMenu(&shipments, &transports, &stock);
}
