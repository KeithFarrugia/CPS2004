#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "Apparel.h"

class Accessory : public Apparel{
public:
    Accessory();
    Accessory(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string brand);
    Accessory(const Accessory& other);
    // Getters
    std::string getBrand()const{return brand;};
    // Setters
    void setBrand(const std::string brand){this->brand = brand;};

    std::string display_product_info()override;
    Accessory* clone()override{return new Accessory(*this);};
private:
    std::string brand;
};
#endif //ACCESSORY_H