#include "Clothing.h"

Clothing::Clothing() : Apparel(){
    style = "";
}

Clothing::Clothing(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string style) 
            : Apparel(name, cost, supplier, discount_amount, packing_units, cost_per_unit, material){
    this->style = style;
}

Clothing::Clothing(const Clothing& other) : Apparel(other) {
    this->style = other.style;
}

std::string Clothing::display_product_info(){
    return Apparel::display_product_info() +
            "\nStyle: " +style;
}


// ========================================== PROTOBUFFERS
void Clothing::copyToProto(PBStockItem* message){
    PBClothing* pbClothing = message->mutable_clothing();
    pbClothing->set_style(style);

    PBApparel* pbApparel = pbClothing->mutable_apparel();
    pbApparel->set_material(material);

    PBProduct* pbProduct = pbApparel->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Clothing::copyFromProto(const PBStockItem& message) {
    const PBClothing& pbClothing = message.clothing();
    name = pbClothing.apparel().product().name();
    cost = pbClothing.apparel().product().cost();
    supplier = pbClothing.apparel().product().supplier();
    packaging.setUnits(pbClothing.apparel().product().packaging().units());
    packaging.setCost_Per_Unit(pbClothing.apparel().product().packaging().costperunit());
    material = pbClothing.apparel().material();
    style = pbClothing.style();
}