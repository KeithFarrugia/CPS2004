#include "Drink.h"

Drink::Drink() : Consumable(){
    this->isCarbonated = false;
}

Drink::Drink(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, int calories, bool isCarbonated)
    : Consumable(name, cost, supplier, discount_amount, packing_units, cost_per_unit, calories){
    this->isCarbonated = isCarbonated;
}

Drink::Drink(const Drink& other) : Consumable(other) {
    this->isCarbonated = other.isCarbonated;
}

std::string Drink::display_product_info(){
    return Consumable::display_product_info() + 
            "\nIs Carbonated: " + (isCarbonated ? "True" : "False");
}

// ========================================== PROTOBUFFERS
void Drink::copyToProto(PBStockItem* message){
    PBDrink* pbDrink = message->mutable_drink();
    pbDrink->set_iscarbonated(isCarbonated);

    PBConsumable* pbConsumable = pbDrink->mutable_consumable();
    pbConsumable->set_calories(calories);

    PBProduct* pbProduct = pbConsumable->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Drink::copyFromProto(const PBStockItem& message) {
    const PBDrink& pbDrink = message.drink();
    name = pbDrink.consumable().product().name();
    cost = pbDrink.consumable().product().cost();
    supplier = pbDrink.consumable().product().supplier();
    packaging.setUnits(pbDrink.consumable().product().packaging().units());
    packaging.setCost_Per_Unit(pbDrink.consumable().product().packaging().costperunit());
    calories = pbDrink.consumable().calories();
    isCarbonated = pbDrink.iscarbonated();
}