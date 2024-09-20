#include "SeaTransport.h"

SeaTransport::SeaTransport() : Transport(){
    shipName = "";
};

SeaTransport::SeaTransport(const int code, float speed, float costPerMeter, const std::string route, const std::string shipName) 
            : Transport(code, speed, costPerMeter, route){
    this->shipName = shipName;
}

SeaTransport::SeaTransport(const SeaTransport& other) : Transport(other) {
    this->shipName = other.shipName;
}

std::string SeaTransport::to_string(){
    return Transport::to_string()+
            "\nShip Name: "+shipName;
}