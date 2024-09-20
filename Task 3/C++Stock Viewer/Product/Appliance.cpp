#include "Appliance.h"

Appliance::Appliance() : Electronics(){
    size = "";
}


Appliance::Appliance(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string manufacturer, std::string size) 
            : Electronics(name, cost, supplier, discount_amount, packing_units, cost_per_unit, manufacturer){
    this->size = size;
}

Appliance::Appliance(const Appliance& other) : Electronics(other) {
    this->size = other.size;
}

std::string Appliance::display_product_info(){
    return Electronics::display_product_info() + 
            "\nSize: "+size;
}


// ========================================== PROTOBUFFERS
void Appliance::copyToProto(PBStockItem* message){
    PBAppliance* pbAppliance = message->mutable_appliance();
    pbAppliance->set_size(size);

    PBElectronics* pbElectronics = pbAppliance->mutable_electronics();
    pbElectronics->set_manufacturer(manufacturer);

    PBProduct* pbProduct = pbElectronics->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Appliance::copyFromProto(const PBStockItem& message) {
    const PBAppliance& pbAppliance = message.appliance();
    name = pbAppliance.electronics().product().name();
    cost = pbAppliance.electronics().product().cost();
    supplier = pbAppliance.electronics().product().supplier();
    packaging.setUnits(pbAppliance.electronics().product().packaging().units());
    packaging.setCost_Per_Unit(pbAppliance.electronics().product().packaging().costperunit());
    manufacturer = pbAppliance.electronics().manufacturer();
    size = pbAppliance.size();
}