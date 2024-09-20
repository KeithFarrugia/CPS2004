#ifndef PACKAGING_H
#define PACKAGING_H

#include <iostream>

class Packaging{
public:
    Packaging();
    Packaging(int packaging_units, float packaging_cost);
    Packaging(const Packaging& other);

    // Getters
    int getUnits(){return packaging_units;};
    float getCost_Per_Unit(){return packaging_cost;};
    // Setters
    void setUnits(int packaging_units){this->packaging_units = packaging_units;};
    void setCost_Per_Unit(float packaging_cost){this->packaging_cost = packaging_cost;}

    float calculate_Total_Cost();
    std::string display_product_info();
private:
    int packaging_units;
    float packaging_cost;

};
#endif //PACKAGING_H