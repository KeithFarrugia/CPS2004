#ifndef DIGITAL_H
#define DIGITAL_H

#include "Games.h"

class Digital : public Games{
public:
    Digital();
    Digital(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string genre,  std::string developer);
    Digital(const Digital& other);

    // Getters
    std::string getDeveloper()const {return developer;};
    // Setters
    void setDeveloper(const std::string developer){this->developer = developer;};

    std::string display_product_info()override;
    Digital* clone()override{return new Digital(*this);};

    
    void copyToProto(PBStockItem* message)override;
    void copyFromProto(const PBStockItem& message)override;
private:
    std::string developer;
};

#endif //DIGITAL_H