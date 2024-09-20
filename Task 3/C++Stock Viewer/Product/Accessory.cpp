#include "Accessory.h"

Accessory::Accessory() : Apparel(){
    brand = "";
}

Accessory::Accessory(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string brand) 
            : Apparel(name, cost, supplier, discount_amount, packing_units, cost_per_unit, material){
    this->brand = brand;
}

Accessory::Accessory(const Accessory& other) : Apparel(other) {
    this->brand = other.brand;
}

std::string Accessory::display_product_info(){
    return Apparel::display_product_info() 
            +"\nBrand: " +brand;
}

// ========================================== PROTOBUFFERS
void Accessory::copyToProto(PBStockItem* message){
    PBAccessory* pbAccessory = message->mutable_accessory();
    pbAccessory->set_brand(brand);

    PBApparel* pbApparel = pbAccessory->mutable_apparel();
    pbApparel->set_material(material);

    PBProduct* pbProduct = pbApparel->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Accessory::copyFromProto(const PBStockItem& message) {
    const PBAccessory& pbAccessory = message.accessory();
    name = pbAccessory.apparel().product().name();
    cost = pbAccessory.apparel().product().cost();
    supplier = pbAccessory.apparel().product().supplier();
    packaging.setUnits(pbAccessory.apparel().product().packaging().units());
    packaging.setCost_Per_Unit(pbAccessory.apparel().product().packaging().costperunit());
    material = pbAccessory.apparel().material();
    brand = pbAccessory.brand();
}