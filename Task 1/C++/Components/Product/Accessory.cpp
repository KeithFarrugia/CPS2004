#include "Accessory.h"

Accessory::Accessory() : Apparel(){
    brand = "";
}

Accessory::Accessory(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string brand) 
            : Apparel(name, cost, supplier, discount_amount, packing_units, cost_per_unit, material){
    this->brand = brand;
}

Accessory::Accessory(const Accessory& other) : Apparel(other) {
    this->brand = other.brand;
}

std::string Accessory::display_product_info(){
    return Apparel::display_product_info() 
            +"\nBrand: " +brand;
}