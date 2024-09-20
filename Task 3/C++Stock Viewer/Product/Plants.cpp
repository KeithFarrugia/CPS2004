#include "Plants.h"
Plants::Plants() : Flora(){
    bearsFruit = false;
}
Plants::Plants(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, bool isCultivated, bool bearsFruit) 
        : Flora(name, cost, supplier, discount_amount, packing_units, cost_per_unit, isCultivated){
    this->bearsFruit = bearsFruit;
}

Plants::Plants(const Plants& other) : Flora(other) {
    this->bearsFruit = other.bearsFruit;
}

std::string Plants::display_product_info(){
    return Flora::display_product_info()+
            "\nBears Fruit: " +(bearsFruit? "true" : "false");
}

// ========================================== PROTOBUFFERS
void Plants::copyToProto(PBStockItem* message){
    PBPlants* pbPlants = message->mutable_plants();
    pbPlants->set_bearsfruit(bearsFruit);

    PBFlora* pbFlora = pbPlants->mutable_flora();
    pbFlora->set_iscultivated(isCultivated);

    PBProduct* pbProduct = pbFlora->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Plants::copyFromProto(const PBStockItem& message) {
    const PBPlants& pbPlants = message.plants();
    name = pbPlants.flora().product().name();
    cost = pbPlants.flora().product().cost();
    supplier = pbPlants.flora().product().supplier();
    packaging.setUnits(pbPlants.flora().product().packaging().units());
    packaging.setCost_Per_Unit(pbPlants.flora().product().packaging().costperunit());
    isCultivated = pbPlants.flora().iscultivated();
    bearsFruit = pbPlants.bearsfruit();
}