package com.logistics.Components.Product;

import com.logistics.Serialization.PBLogistics.PBStockItem;

public interface Product{
    float getCost();
    String getName();
    String getSupplier();
    float getDiscountAmount();
    float getPackagingCost();

    void setCost(float cost);
    void setName(String name);
    void setSupplier(String supplier);
    void setDiscountAmount(float discountAmount);
    void setPackagingData(int packingUnits, float costPerUnit);

    Product clone();

    float calculateDiscount();

    String display_product_info();
    void copyToProto(PBStockItem.Builder message);
    void copyFromProto(PBStockItem message);
}
