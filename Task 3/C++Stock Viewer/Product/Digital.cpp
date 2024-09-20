#include "Digital.h"

Digital::Digital() : Games(){
    developer = "";
};

Digital::Digital(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string genre, std::string developer) 
            : Games(name, cost, supplier, discount_amount, packing_units, cost_per_unit, genre){
    this->developer = developer;
}

Digital::Digital(const Digital& other) : Games(other) {
    this->developer = other.developer;
}

std::string Digital::display_product_info(){
    return Games::display_product_info()  
            +"\nDeveloper: "+developer; 
}

// ========================================== PROTOBUFFERS
void Digital::copyToProto(PBStockItem* message){
    PBDigital* pbDigital = message->mutable_digital();
    pbDigital->set_developer(developer);

    PBGames* pbGames = pbDigital->mutable_games();
    pbGames->set_genre(genre);

    PBProduct* pbProduct = pbGames->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Digital::copyFromProto(const PBStockItem& message) {
    const PBDigital& pbDigital = message.digital();
    name = pbDigital.games().product().name();
    cost = pbDigital.games().product().cost();
    supplier = pbDigital.games().product().supplier();
    packaging.setUnits(pbDigital.games().product().packaging().units());
    packaging.setCost_Per_Unit(pbDigital.games().product().packaging().costperunit());
    genre = pbDigital.games().genre();
    developer = pbDigital.developer();
}