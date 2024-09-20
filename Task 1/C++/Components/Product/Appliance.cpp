#include "Appliance.h"

Appliance::Appliance() : Electronics(){
    size = "";
}


Appliance::Appliance(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string manufacturer, std::string size) 
            : Electronics(name, cost, supplier, discount_amount, packing_units, cost_per_unit, manufacturer){
    this->size = size;
}

Appliance::Appliance(const Appliance& other) : Electronics(other) {
    this->size = other.size;
}

std::string Appliance::display_product_info(){
    return Electronics::display_product_info() + 
            "\nSize: "+size;
}