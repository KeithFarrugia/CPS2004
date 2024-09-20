#ifndef PHYSICAL_H
#define PHYSICAL_H

#include "Games.h"

class Physical : public Games{
public:

    Physical();
    Physical(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string genre, int number_of_Players);
    Physical(const Physical& other);
    
    // Getters
    int getNumber_of_Players()const{return number_of_players;};
    // Setters
    void setNumber_of_Players(const int number_of_players){this->number_of_players = number_of_players;};

    std::string display_product_info()override;
    Physical* clone()override{return new Physical(*this);};

    void copyToProto(PBStockItem* message)override;
    void copyFromProto(const PBStockItem& message)override;
private:
    int number_of_players;

};

#endif //PHYSICAL_H