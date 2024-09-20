#include "Tech.h"

Tech::Tech() : Electronics(){
    type = "";
}

Tech::Tech(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string manufacturer, std::string type) 
            : Electronics(name, cost, supplier, discount_amount, packing_units, cost_per_unit, manufacturer){
    this->type = type;
};

Tech::Tech(const Tech& other) : Electronics(other) {
    this->type = other.type;
}

std::string Tech::display_product_info(){
    return Electronics::display_product_info()+
            "\nType: "+type;
}

// ========================================== PROTOBUFFERS
void Tech::copyToProto(PBStockItem* message){
    PBTech* pbTech = message->mutable_tech();
    pbTech->set_type(type);

    PBElectronics* pbElectronics = pbTech->mutable_electronics();
    pbElectronics->set_manufacturer(manufacturer);

    PBProduct* pbProduct = pbElectronics->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Tech::copyFromProto(const PBStockItem& message) {
    const PBTech& pbTech = message.tech();
    name = pbTech.electronics().product().name();
    cost = pbTech.electronics().product().cost();
    supplier = pbTech.electronics().product().supplier();
    packaging.setUnits(pbTech.electronics().product().packaging().units());
    packaging.setCost_Per_Unit(pbTech.electronics().product().packaging().costperunit());
    manufacturer = pbTech.electronics().manufacturer();
    type = pbTech.type();
}