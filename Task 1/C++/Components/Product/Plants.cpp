#include "Plants.h"
Plants::Plants() : Flora(){
    bearsFruit = false;
}
Plants::Plants(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, bool isCultivated, bool bearsFruit) 
        : Flora(name, cost, supplier, discount_amount, packing_units, cost_per_unit, isCultivated){
    this->bearsFruit = bearsFruit;
}

Plants::Plants(const Plants& other) : Flora(other) {
    this->bearsFruit = other.bearsFruit;
}

std::string Plants::display_product_info(){
    return Flora::display_product_info()+
            "\nBears Fruit: " +(bearsFruit? "true" : "false");
}