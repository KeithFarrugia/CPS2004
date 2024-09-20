#ifndef DECOR_H
#define DECOR_H

#include "Furniture.h"

class Decor : public Furniture {
public:
    Decor();
    Decor(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string style);
    Decor(const Decor& other);

    // Getters
    std::string getStyle()const{return style;};
    // Setters
    void setStyle(const std::string style) {this->style = style;};

    std::string display_product_info() override;
    Decor* clone()override{return new Decor(*this);};
    
    void copyToProto(PBStockItem* message)override;
    void copyFromProto(const PBStockItem& message)override;
private:
    std::string style;

};

#endif //DECOR_H