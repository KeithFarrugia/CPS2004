#ifndef SEEDS_H
#define SEEDS_H
#include "Flora.h"
class Seeds : public Flora {
public:
    Seeds();
    Seeds(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, bool isCultivated, int expirationDays);
    Seeds(const Seeds& other);
    
    // Getters
    int getExpirationDays()const{return expirationDays;}; 
    // Setters
    void setExpirationDays(const int expirationDays){this->expirationDays = expirationDays;};

    std::string display_product_info()override;
    Seeds* clone()override{return new Seeds(*this);};
private:
    int expirationDays;
};

#endif //SEEDS_H