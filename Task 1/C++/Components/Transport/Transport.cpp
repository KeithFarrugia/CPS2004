#include "Transport.h"
Transport::Transport(){
    code = 0;
    speed = 0.0f;
    costPerMeter = 0.0f;
    route = "";
};
Transport::Transport(int code, float speed, float costPerMeter, const std::string route){
    this->code = code;
    this->speed = speed;
    this->costPerMeter = costPerMeter;
    this->route = route;
};

Transport::Transport(const Transport& other) {
    this->code = other.code;
    this->speed = other.speed;
    this->costPerMeter = other.costPerMeter;
    this->route = other.route;
}

float Transport::estimateDeliveryTime(float distance){
    return distance/speed;
};
float Transport::calcPrice(float distance){
    return distance*costPerMeter;
};
std::string Transport::to_string(){
    return "Code: "+std::to_string(code)+
            "\nSpeed: "+std::to_string(speed)+
            "\nCost per Meter: "+std::to_string(costPerMeter)+
            "\nRoute: "+route;
};
