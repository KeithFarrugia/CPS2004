#ifndef FLORA_H
#define FLORA_H

#include "Product.h"

class Flora : public Product{
public:
    Flora();
    Flora(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, bool isCultivated);
    Flora(const Flora& other);
    
    // Getters
    bool getIsCultivated()const{return isCultivated;};
    // Setters
    void setIsCultivated(const bool isCultivated){this->isCultivated = isCultivated;};

    virtual std::string display_product_info()override;
    virtual Flora* clone()override{return new Flora(*this);};
protected:
    bool isCultivated;
};
#endif //FLORA_H