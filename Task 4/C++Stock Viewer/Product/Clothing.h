#ifndef CLOTHING_H
#define CLOTHING_H

#include "Apparel.h"

class Clothing : public Apparel{
public:
    Clothing();
    Clothing(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string style);
    Clothing(const Clothing& other);
    
    // Getters
    std::string getStyle()const{return style;};
    // Setters
    void setStyle(const std::string style){this->style = style;};

    std::string display_product_info()override;
    Clothing* clone()override{return new Clothing(*this);};
    
    void copyToProto(PBStockItem* message)override;
    void copyFromProto(const PBStockItem& message)override;
protected:
    std::string style;
};
#endif //CLOTHING_H