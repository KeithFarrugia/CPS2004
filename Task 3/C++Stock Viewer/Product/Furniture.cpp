#include "Furniture.h"

Furniture::Furniture() : Product(){
    material = "";
}

Furniture::Furniture(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material)
    : Product(name, cost, supplier, discount_amount, packing_units, cost_per_unit){
    this->material = material; 
}

Furniture::Furniture(const Furniture& other) : Product(other) {
    this->material = other.material;
}

std::string Furniture::display_product_info(){
    return Product::display_product_info()+
           "\nMaterial: " + material;
}