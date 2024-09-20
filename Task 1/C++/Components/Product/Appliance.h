#ifndef APPLIANCE_H
#define APPLIANCE_H
#include "Electronics.h"

class Appliance : public Electronics{
public:
    Appliance();
    Appliance(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string manufacturer, std::string size);
    Appliance(const Appliance& other);

    //Getters
    std::string getSize()const{return size;};
    //Setters
    void setSize(const std::string size){this->size = size;};
    
    std::string display_product_info()override;
    Appliance* clone()override{return new Appliance(*this);};
protected:
    std::string size;
};

#endif //APPLIANCE_H