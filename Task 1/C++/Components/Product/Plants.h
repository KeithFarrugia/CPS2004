#ifndef PLANTS_H
#define PLANTS_H
#include "Flora.h"

class Plants: public Flora{
public:
    Plants();
    Plants(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, bool isCultivated, bool bearsFruit);
    Plants(const Plants& other);
    
    // Getters
    bool getBearsFruit(){return bearsFruit;};
    // Setters
    void setBearsFruit(bool bearsFruit){this->bearsFruit = bearsFruit;};

    std::string display_product_info()override;
    Plants* clone()override{return new Plants(*this);};
private:
    bool bearsFruit;
};
#endif //PLANTS_H