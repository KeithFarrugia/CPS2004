#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "Product.h"

class Consumable : public Product{
public:
    Consumable();
    Consumable(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, int calories);
    Consumable(const Consumable& other);
    
    // Getters
    int getCalories()const{return calories;};
    // Setters
    void setCalories(const int calories){this->calories = calories;};

    virtual std::string display_product_info()override;
    virtual Consumable* clone()override{return new Consumable(*this);};

    virtual void copyToProto(PBStockItem* message)override{}; // Blank to be filled by child class
    virtual void copyFromProto(const PBStockItem& message)override{}; // Blank to be filled by child class
protected:
    int calories;
};
#endif //CONSUMABLE_H