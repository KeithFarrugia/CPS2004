#ifndef AIRTRANSPORT_H
#define AIRTRANSPORT_H

#include "Transport.h"

class AirTransport : public Transport{
public:
    AirTransport();
    AirTransport(int code, float speed, float costPerMeter, const std::string route, const std::string model);
    AirTransport(const AirTransport& other);

    // Getters
    std::string getModel()const{return model;};
    //Setters
    void setModel(const std::string model){this->model = model;};

    AirTransport* clone()override{return new AirTransport(*this);};
    std::string to_string()override;

protected:
    std::string model;
};

#endif //AIRTRANSPORT_H