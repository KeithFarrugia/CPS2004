#include "Product.h"
Product::Product(){
    cost = 0;
    name = "";
    supplier = "";
    packaging = Packaging(0, 0);
}

Product::Product(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit){
    this->cost = cost;
    this->name = name;
    this->supplier = supplier;
    this->packaging = Packaging(packing_units, cost_per_unit);
}

Product::Product(const Product& other) {
    // Copy the values of the other object
    this->cost = other.cost;
    this->name = other.name;
    this->supplier = other.supplier;
    this->discount_amount = other.discount_amount;
    this->packaging = Packaging(other.packaging);

}

float Product::calculate_discount() {
    // Get the current time
    std::time_t t = std::time(nullptr);

    // Convert the current time to a structure
    std::tm* now = std::localtime(&t);

    // Get the current month
    int currentMonth = now->tm_mon;

    // Check if the current month is December (index 11)
    if (currentMonth == 11 && (discount_amount >= 0 && discount_amount <= 1)){
       return (1 - discount_amount);;
    }else{
        return 1;
    };
}

std::string Product::display_product_info(){
    return  "Product: "+ name + 
            "\nCost: " +std::to_string(cost)+ 
            "\nSupplier: "+supplier+ 
            "\nDiscount Amount: "+std::to_string(discount_amount)+
            "\n" +packaging.display_product_info();
};