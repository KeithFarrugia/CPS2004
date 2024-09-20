#ifndef FURNITURE_H
#define FURNITURE_H

#include "Product.h"

class Furniture : public Product {
public:
    Furniture();
    Furniture(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material);
    Furniture(const Furniture& other);
    
    // Getters
    std::string getMaterial()const{return material;};

    // Setters
    void setMaterial(const std::string material){this->material = material;};

    virtual std::string display_product_info() override;
    virtual Furniture* clone()override{return new Furniture(*this);};
protected:
    std::string material;
};

#endif //FURNITURE_H