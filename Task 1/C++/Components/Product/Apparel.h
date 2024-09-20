#ifndef APPAREL_H
#define APPAREL_H

#include "Product.h"

class Apparel : public Product{
public:
    Apparel();
    Apparel(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material);
    Apparel(const Apparel& other);

    // Getters
    std::string getMaterial()const{return material;};
    //Setters
    void setMaterial(const std::string material){this->material = material;};

    virtual std::string display_product_info() override;
    virtual Apparel* clone()override{return new Apparel(*this);};
protected:
    std::string material;
};
#endif //APPAREL_H
