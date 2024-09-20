#include "Food.h"

Food::Food() : Consumable(){
    bool isCanned = false;
}

Food::Food(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, int calories, bool isCanned)
    : Consumable(name, cost, supplier, discount_amount, packing_units, cost_per_unit, calories){
    this->isCanned = isCanned;
}

Food::Food(const Food& other) : Consumable(other) {
    this->isCanned = other.isCanned;
}

std::string Food::display_product_info() {
    return Consumable::display_product_info() 
    + "\nIs Canned: " + (isCanned? "true" : "false");
}

// ========================================== PROTOBUFFERS
void Food::copyToProto(PBStockItem* message){
    PBFood* pbFood = message->mutable_food();
    pbFood->set_iscanned(isCanned);

    PBConsumable* pbConsumable = pbFood->mutable_consumable();
    pbConsumable->set_calories(calories);

    PBProduct* pbProduct = pbConsumable->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Food::copyFromProto(const PBStockItem& message) {
    const PBFood& pbFood = message.food();
    name = pbFood.consumable().product().name();
    cost = pbFood.consumable().product().cost();
    supplier = pbFood.consumable().product().supplier();
    packaging.setUnits(pbFood.consumable().product().packaging().units());
    packaging.setCost_Per_Unit(pbFood.consumable().product().packaging().costperunit());
    calories = pbFood.consumable().calories();
    isCanned = pbFood.iscanned();
}