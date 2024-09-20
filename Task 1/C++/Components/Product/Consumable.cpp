#include "Consumable.h"

Consumable::Consumable () : Product(){
    calories = 0;
}

Consumable::Consumable (std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, int calories)
            : Product(name, cost, supplier, discount_amount, packing_units, cost_per_unit){
    this->calories = calories;
}

Consumable::Consumable(const Consumable& other) : Product(other) {
    this->calories = other.calories;
}

std::string Consumable::display_product_info(){
    return Product::display_product_info() + 
            "\nCalories: " + std::to_string(calories);
}