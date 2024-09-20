#ifndef STORAGE_H
#define STORAGE_H

#include "Furniture.h"

class Storage : public Furniture {

public:
    Storage();
    Storage(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, int capacity);
    Storage(const Storage& other);
    
    // Getters
    int getCapacity()const{return capacity;};
    // Setters
    void setCapacity(int capacity){this->capacity = capacity;};

    std::string display_product_info()override;
    Storage* clone()override{return new Storage(*this);};
private:
    int capacity;
};

#endif //STORAGE_H