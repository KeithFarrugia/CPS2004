#include "Seeds.h"
Seeds::Seeds() : Flora(){
    expirationDays = 0;
}

Seeds::Seeds(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, bool isCultivated, int expirationDays) 
        : Flora(name, cost, supplier, discount_amount, packing_units, cost_per_unit, isCultivated){
    this->expirationDays = expirationDays;
}

Seeds::Seeds(const Seeds& other) : Flora(other) {
    this->expirationDays = other.expirationDays;
}

std::string Seeds::display_product_info(){
    return Flora::display_product_info()+
            "\nExpiration Days: " + std::to_string(expirationDays);
}