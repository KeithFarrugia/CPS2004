#include "Games.h"
Games::Games():Product(){
    this->genre = "";
}
Games::Games(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string genre) 
            :Product(name, cost, supplier, discount_amount, packing_units, cost_per_unit){
    this->genre = genre;
}

Games::Games(const Games& other) : Product(other) {
    this->genre = other.genre;
}

std::string Games::display_product_info(){
    return Product::display_product_info()+ 
            "\nGenre: " +genre;
}