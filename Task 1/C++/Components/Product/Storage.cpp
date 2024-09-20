#include "Storage.h"

Storage::Storage() :Furniture(){
    capacity = 0;
}

Storage::Storage(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, int capacity)
      : Furniture(name, cost, supplier, discount_amount, packing_units, cost_per_unit, material){
    this->capacity = capacity;
}

Storage::Storage(const Storage& other) : Furniture(other) {
    this->capacity = other.capacity;
}

std::string Storage::display_product_info(){
    return Furniture::display_product_info() +
           "\nStorage Capacity: " + std::to_string(capacity) + " units";
}