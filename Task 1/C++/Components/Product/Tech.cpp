#include "Tech.h"

Tech::Tech() : Electronics(){
    type = "";
}

Tech::Tech(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string manufacturer, std::string type) 
            : Electronics(name, cost, supplier, discount_amount, packing_units, cost_per_unit, manufacturer){
    this->type = type;
};

Tech::Tech(const Tech& other) : Electronics(other) {
    this->type = other.type;
}

std::string Tech::display_product_info(){
    return Electronics::display_product_info()+
            "\nType: "+type;
}