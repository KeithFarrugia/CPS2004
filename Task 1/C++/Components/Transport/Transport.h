#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>

class Transport{
public:
    Transport();
    Transport(const int code, const float speed, const float costPerMeter, const std::string route);
    Transport(const Transport& other);

    // Getters
    int getCode()const{return code;};
    float getSpeed()const{return speed;};
    float getCostPerMeter()const{return costPerMeter;};
    const std::string getRoute()const{return route;};

    // Setters
    void setCode(const float code){this->code = code;};
    void setSpeed(const float speed){this->speed = speed;};
    void setCostPerMeter(const float costPerMeter){this->costPerMeter = costPerMeter;};
    void setRoute(const std::string route){this->route = route;};

    float estimateDeliveryTime(float distance);
    float calcPrice(float distance);

    virtual Transport* clone(){return new Transport(*this);};
    virtual std::string to_string();
protected:
    int code;
    float speed;
    float costPerMeter;
    std::string route;
};

#endif //TRANSPORT_H