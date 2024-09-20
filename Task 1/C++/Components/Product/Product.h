#ifndef PRODUCT_H
#define PRODUCT_H

#include "Packaging.h"
#include <iostream>
#include <ctime>

class Product{
public:
    Product();
    Product(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit);
    Product(const Product& other);

    // Getters
    float getCost()const{return cost;}
    std::string getName()const{return name;};
    std::string getSupplier()const{return supplier;};
    float getDiscountAmount()const{return discount_amount;};
    float getPackagingCost(){return packaging.calculate_Total_Cost();};
    // Setters
    void setCost(const float cost){this->cost = cost;};
    void setName(const std::string name){this->name = name;};
    void setSupplier(const std::string supplier){this->supplier = supplier;};
    void setDiscountAmount(const float discount_amount){this->discount_amount = discount_amount;};
    void setPackagingData(const int packing_units, const float cost_per_unit){this->packaging = Packaging(packing_units, cost_per_unit);};


    float  calculate_discount();
    virtual std::string display_product_info();

    virtual Product* clone(){return new Product(*this);};
protected:
    float cost;
    std::string name;
    std::string supplier;
    float discount_amount;
    Packaging packaging;
};

#endif //PRODUCT_H