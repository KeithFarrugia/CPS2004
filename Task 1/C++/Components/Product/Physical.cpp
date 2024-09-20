#include "Physical.h"

Physical::Physical() : Games(){
    number_of_players = 0;
};      

Physical::Physical(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string genre, int number_of_Players) 
        : Games(name, cost, supplier, discount_amount, packing_units, cost_per_unit, genre){
    this->number_of_players = number_of_Players;
}

Physical::Physical(const Physical& other) : Games(other) {
    this->number_of_players = other.number_of_players;
}

std::string Physical::display_product_info(){
    return Games::display_product_info() +
            "\nNumber of Players: " +std::to_string(number_of_players); 
}