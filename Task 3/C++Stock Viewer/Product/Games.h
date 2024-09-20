#ifndef GAMES_H
#define GAMES_H

#include "Product.h"

class Games : public Product{
public:
    Games();
    Games(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string genre);
    Games(const Games& other);
    
    // Getters
    std::string getGenre()const{return genre;};
    // Setters
    void setGenre(const std::string genre){this->genre = genre;};

    virtual std::string display_product_info()override;
    virtual Games* clone()override{return new Games(*this);};
    
    virtual void copyToProto(PBStockItem* message)override{}; // Blank to be filled by child class
    virtual void copyFromProto(const PBStockItem& message)override{}; // Blank to be filled by child class
protected:
    std::string genre;

};

#endif //GAMES_H