#ifndef SEATRANSPORT_H
#define SEATRANSPORT_H
#include "Transport.h"

class SeaTransport : public Transport{
public:
    SeaTransport();
    SeaTransport(const int code, float speed, float costPerMeter, const std::string route, const std::string shipName);
    SeaTransport(const SeaTransport& other);
    
    // Getters
    std::string getShipName()const{return shipName;};
    // Setters
    void setShipName(const std::string shipName){this->shipName =shipName;};


    SeaTransport* clone()override{return new SeaTransport(*this);};
    std::string to_string()override;
private:
    std::string shipName;
};
#endif //SEATRANSPORT_H