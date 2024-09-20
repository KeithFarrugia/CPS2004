#ifndef Electronics_H
#define Electronics_H
#include "Product.h"

class Electronics : public Product{
public:
    Electronics();
    Electronics(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string manufacturer);
    Electronics(const Electronics& other);
    
    // Getters
    std::string getManufacturer()const{return manufacturer;};

    // Setters
    void setManufacturer(const std::string){this->manufacturer = manufacturer;};

    virtual std::string display_product_info()override;
    virtual Electronics* clone()override{return new Electronics(*this);};
    
    virtual void copyToProto(PBStockItem* message)override{}; // Blank to be filled by child class
    virtual void copyFromProto(const PBStockItem& message)override{}; // Blank to be filled by child class
protected:
    std::string manufacturer;
};

#endif //Electronics_H