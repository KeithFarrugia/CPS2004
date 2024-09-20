#ifndef FOOD_H
#define FOOD_H

#include "Consumable.h"

class Food : public Consumable {
public:

    Food();
    Food(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, int calories, bool isCanned);
    Food(const Food& other);
    
    // Getter
    bool getIsCanned() const{return isCanned;};

    // Setter
    void setIsCanned(bool isCanned){this->isCanned = isCanned;};

    std::string display_product_info() override;
    Food* clone()override{return new Food(*this);};
private:
    bool isCanned;
};

#endif //FOOD_H