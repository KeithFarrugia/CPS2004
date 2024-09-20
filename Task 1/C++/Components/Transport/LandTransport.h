#ifndef LANDTRANSPORT_H
#define LANDTRANSPORT_H
#include "Transport.h"
class LandTransport : public Transport{
public:

    LandTransport();
    LandTransport(const int code, float speed, float costPerMeter, const std::string route, const std::string type);
    LandTransport(const LandTransport& other);
    
    // Getters
    std::string getType()const{return type;};
    // Setters
    void setType(const std::string type){this->type = type;};

    LandTransport* clone()override{return new LandTransport(*this);};
    std::string to_string()override;

private:
    std::string type;
};

#endif //LANDTRANSPORT_H