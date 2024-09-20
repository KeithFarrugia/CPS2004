#include "Decor.h"

Decor::Decor() : Furniture(){
    style = "";
}

Decor::Decor(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string style)
        : Furniture(name, cost, supplier, discount_amount, packing_units, cost_per_unit, material){
    this->style = style;
}

Decor::Decor(const Decor& other) : Furniture(other) {
    this->style = other.style;
}


std::string Decor::display_product_info(){
    return Furniture::display_product_info() +
           "\nStyle: " + style;
}