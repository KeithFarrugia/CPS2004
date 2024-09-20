#include "Seeds.h"
Seeds::Seeds() : Flora(){
    expirationDays = 0;
}

Seeds::Seeds(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, bool isCultivated, int expirationDays) 
        : Flora(name, cost, supplier, discount_amount, packing_units, cost_per_unit, isCultivated){
    this->expirationDays = expirationDays;
}

Seeds::Seeds(const Seeds& other) : Flora(other) {
    this->expirationDays = other.expirationDays;
}

std::string Seeds::display_product_info(){
    return Flora::display_product_info()+
            "\nExpiration Days: " + std::to_string(expirationDays);
}

// ========================================== PROTOBUFFERS
void Seeds::copyToProto(PBStockItem* message){
    PBSeeds* pbSeeds = message->mutable_seeds();
    pbSeeds->set_expirationdays(expirationDays);

    PBFlora* pbFlora = pbSeeds->mutable_flora();
    pbFlora->set_iscultivated(isCultivated);

    PBProduct* pbProduct = pbFlora->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Seeds::copyFromProto(const PBStockItem& message) {
    const PBSeeds& pbSeeds = message.seeds();
    name = pbSeeds.flora().product().name();
    cost = pbSeeds.flora().product().cost();
    supplier = pbSeeds.flora().product().supplier();
    packaging.setUnits(pbSeeds.flora().product().packaging().units());
    packaging.setCost_Per_Unit(pbSeeds.flora().product().packaging().costperunit());
    isCultivated = pbSeeds.flora().iscultivated();
    expirationDays = pbSeeds.expirationdays();
}