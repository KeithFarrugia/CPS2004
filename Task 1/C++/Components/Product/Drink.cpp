#include "Drink.h"

Drink::Drink() : Consumable(){
    this->isCarbonated = false;
}

Drink::Drink(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, int calories, bool isCarbonated)
    : Consumable(name, cost, supplier, discount_amount, packing_units, cost_per_unit, calories){
    this->isCarbonated = isCarbonated;
}

Drink::Drink(const Drink& other) : Consumable(other) {
    this->isCarbonated = other.isCarbonated;
}

std::string Drink::display_product_info(){
    return Consumable::display_product_info() + 
            "\nIs Carbonated: " + (isCarbonated ? "True" : "False");
}