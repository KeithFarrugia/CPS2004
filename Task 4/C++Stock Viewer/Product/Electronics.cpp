#include "Electronics.h"

Electronics::Electronics() : Product(){
    manufacturer = "";
}

Electronics::Electronics(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string manufacturer) 
            : Product(name, cost, supplier, discount_amount, packing_units, cost_per_unit){
    this->manufacturer = manufacturer;
}

Electronics::Electronics(const Electronics& other) : Product(other) {
    this->manufacturer = other.manufacturer;
}


std::string Electronics::display_product_info(){
    return Product::display_product_info() + 
            "\nManufacturer: " +manufacturer;
};