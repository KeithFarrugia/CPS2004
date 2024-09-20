#include "LandTransport.h"
LandTransport::LandTransport(){
    type = "";
}
LandTransport::LandTransport(const int code, float speed, float costPerMeter, const std::string route, const std::string type)
                : Transport(code, speed, costPerMeter, route){
    this->type = type;
}
LandTransport::LandTransport(const LandTransport& other) : Transport(other) {
    this->type = other.type;
}


std::string LandTransport::to_string(){
    return Transport::to_string() +
            "\nType: " +type;
}