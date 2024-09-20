#include "Decor.h"

Decor::Decor() : Furniture(){
    style = "";
}

Decor::Decor(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, std::string style)
        : Furniture(name, cost, supplier, discount_amount, packing_units, cost_per_unit, material){
    this->style = style;
}

Decor::Decor(const Decor& other) : Furniture(other) {
    this->style = other.style;
}


std::string Decor::display_product_info(){
    return Furniture::display_product_info() +
           "\nStyle: " + style;
}

// ========================================== PROTOBUFFERS
void Decor::copyToProto(PBStockItem* message){
    PBDecor* pbDecor = message->mutable_decor();
    pbDecor->set_style(style);

    PBFurniture* pbFurniture = pbDecor->mutable_furniture();
    pbFurniture->set_material(material);

    PBProduct* pbProduct = pbFurniture->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Decor::copyFromProto(const PBStockItem& message) {
    const PBDecor& pbDecor = message.decor();
    name = pbDecor.furniture().product().name();
    cost = pbDecor.furniture().product().cost();
    supplier = pbDecor.furniture().product().supplier();
    packaging.setUnits(pbDecor.furniture().product().packaging().units());
    packaging.setCost_Per_Unit(pbDecor.furniture().product().packaging().costperunit());
    material = pbDecor.furniture().material();
    style = pbDecor.style();
}