package com.logistics.Components.Product;

import java.util.Calendar;

import com.logistics.Serialization.PBLogistics.PBAccessory;
import com.logistics.Serialization.PBLogistics.PBApparel;
import com.logistics.Serialization.PBLogistics.PBPackage;
import com.logistics.Serialization.PBLogistics.PBProduct;
import com.logistics.Serialization.PBLogistics.PBStockItem;

public class Accessory implements Apparel {
    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private String material;
    private String brand;

    public Accessory() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        material = "";
        brand = "";
    }

    public Accessory(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material, String brand) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.material = material;
        this.brand = brand;
    }

    public Accessory(Accessory other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
        this.material = other.material;
        this.brand = other.brand;
    }

    @Override public Accessory clone() {
        return new Accessory(this);
    }

    // Getters
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public String getMaterial() { return material; }
    public String getBrand() { return brand; }

    // Setters
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setMaterial(String material) { this.material = material; }
    public void setBrand(String brand) { this.brand = brand; }

    @Override public float calculateDiscount() {
        // Get the current month
        int currentMonth = Calendar.getInstance().get(Calendar.MONTH);

        // Check if the current month is December 
        if (currentMonth == Calendar.DECEMBER && (discountAmount >= 0 && discountAmount <= 1)) {
            return (1 - discountAmount);
        } else {
            return 1;
        }
    }


    @Override public String display_product_info() {
        return  "\nName: " + name +
                "\nCost: " + cost +
                "\nSupplier: " + supplier +
                "\nDiscount Amount: " + calculateDiscount() +
                "\nPackaging Cost: " + getPackagingCost() + 
                "\nMaterial: " + material + 
                "\nBrand: " + brand;
    }



    // ========================================== PROTOBUFFERS
    @Override public void copyToProto(PBStockItem.Builder message){
        PBAccessory.Builder pbAccessory = PBAccessory.newBuilder();
        pbAccessory.setBrand(brand);

        PBApparel.Builder pbApparel = pbAccessory.getApparelBuilder();
        pbApparel.setMaterial(material);

        PBProduct.Builder pbProduct = pbApparel.getProductBuilder();
        pbProduct.setName(name);
        pbProduct.setCost(cost);
        pbProduct.setSupplier(supplier);

        PBPackage.Builder pbPackage = pbProduct.getPackagingBuilder();
        pbPackage.setUnits(packaging.getUnits());
        pbPackage.setCostPerUnit(packaging.getCostPerUnit());

        message.setAccessory(pbAccessory);

    };
    @Override public void copyFromProto(PBStockItem message){
        PBAccessory pbAccessory = message.getAccessory();
        name = pbAccessory.getApparel().getProduct().getName();
        cost = pbAccessory.getApparel().getProduct().getCost();
        supplier = pbAccessory.getApparel().getProduct().getSupplier();
        packaging.setUnits(pbAccessory.getApparel().getProduct().getPackaging().getUnits());
        packaging.setCostPerUnit(pbAccessory.getApparel().getProduct().getPackaging().getCostPerUnit());
        material = pbAccessory.getApparel().getMaterial();
        brand = pbAccessory.getBrand();
    };

}