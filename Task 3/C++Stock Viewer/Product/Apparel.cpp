#include "Apparel.h"

Apparel::Apparel() : Product(){
    material = "";
};

Apparel::Apparel(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material) 
        : Product(name, cost, supplier, discount_amount, packing_units, cost_per_unit){
    this->material = material; 
};

Apparel::Apparel(const Apparel& other) : Product(other) {
    this->material = other.material;
}

std::string Apparel::display_product_info(){
    return Product::display_product_info() +
            "\nMaterial: "+material;
}
