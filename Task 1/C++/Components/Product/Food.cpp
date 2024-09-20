#include "Food.h"

Food::Food() : Consumable(){
    bool isCanned = false;
}

Food::Food(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, int calories, bool isCanned)
    : Consumable(name, cost, supplier, discount_amount, packing_units, cost_per_unit, calories){
    this->isCanned = isCanned;
}

Food::Food(const Food& other) : Consumable(other) {
    this->isCanned = other.isCanned;
}

std::string Food::display_product_info() {
    return Consumable::display_product_info() 
    + "\nIs Canned: " + (isCanned? "true" : "false");
}