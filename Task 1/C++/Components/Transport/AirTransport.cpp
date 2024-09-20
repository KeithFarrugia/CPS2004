#include "AirTransport.h"

AirTransport::AirTransport() : Transport(){
    model = "";
}

AirTransport::AirTransport(int code, float speed, float costPerMeter, const std::string route, const std::string model) 
            : Transport(code, speed, costPerMeter, route){
    this->model = model;
}

AirTransport::AirTransport(const AirTransport& other) : Transport(other) {
    this->model = other.model;
}

std::string AirTransport::to_string(){
    return Transport::to_string()+
            "\nModel: "+model;
}