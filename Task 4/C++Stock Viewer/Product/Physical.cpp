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



// ========================================== PROTOBUFFERS
void Physical::copyToProto(PBStockItem* message){
    PBPhysical* pbPhysical = message->mutable_physical();
    pbPhysical->set_numberofplayers(number_of_players);

    PBGames* pbGames = pbPhysical->mutable_games();
    pbGames->set_genre(genre);

    PBProduct* pbProduct = pbGames->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Physical::copyFromProto(const PBStockItem& message) {
    const PBPhysical& pbPhysical = message.physical();
    name = pbPhysical.games().product().name();
    cost = pbPhysical.games().product().cost();
    supplier = pbPhysical.games().product().supplier();
    packaging.setUnits(pbPhysical.games().product().packaging().units());
    packaging.setCost_Per_Unit(pbPhysical.games().product().packaging().costperunit());
    genre = pbPhysical.games().genre();
    number_of_players = pbPhysical.numberofplayers();
}