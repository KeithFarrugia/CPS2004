#ifndef TECH_H
#define TECH_H
#include "Electronics.h"

class Tech : public Electronics{
public:

    Tech();
    Tech(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string manufacturer, std::string type);
    Tech(const Tech& other);

    //Getters
    std::string getSize()const{return type;};
    //Setters
    void setType(const std::string type){this->type = type;};
    
    std::string display_product_info()override;
    Tech* clone()override{return new Tech(*this);};
    
    void copyToProto(PBStockItem* message)override;
    void copyFromProto(const PBStockItem& message)override;
private:
    std::string type;
};

#endif //TECH_H