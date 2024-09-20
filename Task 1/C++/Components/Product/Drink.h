#ifndef DRINK_H
#define DRINK_H

#include "Consumable.h"

class Drink : public Consumable {
public:
    Drink();
    Drink(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, int calories, bool isCarbonated);
    Drink(const Drink& other);
    
    // Getters
    bool getIsCarbonated()const{return isCarbonated;};

    // Setters
    void setIsCarbonated(const bool isCarbonated) {this->isCarbonated = isCarbonated;};

    std::string display_product_info() override;
    Drink* clone()override{return new Drink(*this);};
private:
    bool isCarbonated;
};

#endif //DRINK_H