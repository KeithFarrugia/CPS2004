#include "Storage.h"

Storage::Storage() :Furniture(){
    capacity = 0;
}

Storage::Storage(std::string name, float cost, std::string supplier, float discount_amount, int packing_units, float cost_per_unit, std::string material, int capacity)
      : Furniture(name, cost, supplier, discount_amount, packing_units, cost_per_unit, material){
    this->capacity = capacity;
}

Storage::Storage(const Storage& other) : Furniture(other) {
    this->capacity = other.capacity;
}

std::string Storage::display_product_info(){
    return Furniture::display_product_info() +
           "\nStorage Capacity: " + std::to_string(capacity) + " units";
}

// ========================================== PROTOBUFFERS
void Storage::copyToProto(PBStockItem* message){
    PBStorage* pbStorage = message->mutable_storage();
    pbStorage->set_capacity(capacity);

    PBFurniture* pbFurniture = pbStorage->mutable_furniture();
    pbFurniture->set_material(material);

    PBProduct* pbProduct = pbFurniture->mutable_product();
    pbProduct->set_name(name);
    pbProduct->set_cost(cost);
    pbProduct->set_supplier(supplier);

    PBPackage* pbPackage = pbProduct->mutable_packaging();
    pbPackage->set_units(packaging.getUnits());
    pbPackage->set_costperunit(packaging.getCost_Per_Unit());
}

void Storage::copyFromProto(const PBStockItem& message) {
    const PBStorage& pbStorage = message.storage();
    name = pbStorage.furniture().product().name();
    cost = pbStorage.furniture().product().cost();
    supplier = pbStorage.furniture().product().supplier();
    packaging.setUnits(pbStorage.furniture().product().packaging().units());
    packaging.setCost_Per_Unit(pbStorage.furniture().product().packaging().costperunit());
    material = pbStorage.furniture().material();
    capacity = pbStorage.capacity();
}