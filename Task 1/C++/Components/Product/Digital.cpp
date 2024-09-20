#include "Digital.h"

Digital::Digital() : Games(){
    developer = "";
};

Digital::Digital(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string genre, std::string developer) 
            : Games(name, cost, supplier, discount_amount, packing_units, cost_per_unit, genre){
    this->developer = developer;
}

Digital::Digital(const Digital& other) : Games(other) {
    this->developer = other.developer;
}

std::string Digital::display_product_info(){
    return Games::display_product_info()  
            +"\nDeveloper: "+developer; 
}