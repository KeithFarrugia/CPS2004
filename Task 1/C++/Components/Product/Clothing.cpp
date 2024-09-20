#include "Clothing.h"

Clothing::Clothing() : Apparel(){
    style = "";
}

Clothing::Clothing(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string style) 
            : Apparel(name, cost, supplier, discount_amount, packing_units, cost_per_unit, material){
    this->style = style;
}

Clothing::Clothing(const Clothing& other) : Apparel(other) {
    this->style = other.style;
}

std::string Clothing::display_product_info(){
    return Apparel::display_product_info() +
            "\nStyle: " +style;
}