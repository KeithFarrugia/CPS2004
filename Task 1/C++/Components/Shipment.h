#ifndef SHIPMENT_H
#define SHIPMENT_H
#include "TransportManager.h"
#include "Stock.h"
#include <memory>

class Shipment {
public:
    Shipment();
    Shipment(int ID, std::string customer, Transport& transport, float distance);


    // Add, Delete, Update, Calculate
    void addProduct(Stock* stockList, std::string stockname, int quantity);
    void deleteProduct(Stock* stockList, std::string stockname);
    bool ConfigureTransport(TransportManager* transportManager, int code); // is the main way of setting transport
    
    float calculateTime();
    

    // Getters
    int getID() const { return ID; }
    std::string getCustomer(){ return customer; }
    Transport* getTransport(){ return transport; }
    Stock* getProductList(){ return &productlist; }
    float getDistance() const { return distance; }
    float getCost()const{return cost;}
    bool getIsDispatched()const{return dispatched;}

    // Setters
    void setID(int id) { ID = id; }
    void setCustomer(const std::string& customer) { this->customer = customer; }
    void setTransport(Transport& transport){delete this->transport; this->transport = new Transport(transport);}; // Used for roll back
    void setProductList(const Stock& productlist) { this->productlist = productlist; }
    void setDistance(float d) { distance = d; }
    void setDispatched(bool dispatched){this->dispatched = dispatched;}
    void setCost(float cost){this->cost = cost;}
    void updateCost();

    void deleteShipment();
private:
    static int GlobalId;

    int ID;
    std::string customer;
    Transport* transport;
    Stock productlist;
    float distance;
    bool dispatched;

    float cost;
    float calculateTotalCost();
};

#endif //SHIPMENT_H