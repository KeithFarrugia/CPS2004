#include "Flora.h"

Flora::Flora() : Product(){
    isCultivated = false;
}

Flora::Flora(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, bool isCultivated) 
        : Product(name, cost, supplier, discount_amount, packing_units, cost_per_unit){
    this->isCultivated = isCultivated;
}

Flora::Flora(const Flora& other) : Product(other) {
    this->isCultivated = other.isCultivated;
}

std::string Flora::display_product_info(){
    return Product::display_product_info() +
            "\nIs Cultivated: "+(isCultivated? "true" : "false");
}