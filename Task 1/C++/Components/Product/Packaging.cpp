#include "Packaging.h"

Packaging::Packaging(){
    packaging_units = 0;
    packaging_cost = 0;
};

Packaging::Packaging(int packaging_units, float packaging_cost){
    this->packaging_units = packaging_units;
    this->packaging_cost = packaging_cost;
};

Packaging::Packaging(const Packaging& other) {
    // Copy the values of the other object
    this->packaging_units = other.packaging_units;
    this->packaging_cost = other.packaging_cost;
}

float Packaging::calculate_Total_Cost(){
    return packaging_units*packaging_cost;
};

std::string Packaging::display_product_info(){
    return "Packaing Units: "  +std::to_string(packaging_units)+
           "\nCost per Unit: " +std::to_string(packaging_cost)+
           "\nTotal Packaging Cost: " +std::to_string(calculate_Total_Cost());
}

