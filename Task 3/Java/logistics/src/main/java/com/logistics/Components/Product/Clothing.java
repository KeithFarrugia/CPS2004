package com.logistics.Components.Product;

import java.util.Calendar;

import com.logistics.Serialization.PBLogistics.PBApparel;
import com.logistics.Serialization.PBLogistics.PBClothing;
import com.logistics.Serialization.PBLogistics.PBPackage;
import com.logistics.Serialization.PBLogistics.PBProduct;
import com.logistics.Serialization.PBLogistics.PBStockItem;

public class Clothing implements Apparel {
    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private String material;
    private String style;

    public Clothing() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        material = "";
        style = "";
    }

    public Clothing(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material, String style) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.material = material;
        this.style = style;
    }

    // Copy Constructor
    public Clothing(Clothing other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
        this.material = other.material;
        this.style = other.style;
    }

    // Clone method
    @Override public Clothing clone() {
        return new Clothing(this);
    }

    // Getters
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public String getMaterial() { return material; }
    public String getStyle() { return style; }

    // Setters
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setMaterial(String material) { this.material = material; }
    public void setStyle(String style) { this.style = style; }

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
                "\nStyle: " + style;
    }

    // ========================================== PROTOBUFFERS
    @Override public void copyToProto(PBStockItem.Builder message){
        PBClothing.Builder pbClothing = PBClothing.newBuilder();
        pbClothing.setStyle(style);

        PBApparel.Builder pbApparel = pbClothing.getApparelBuilder();
        pbApparel.setMaterial(material);

        PBProduct.Builder pbProduct = pbApparel.getProductBuilder();
        pbProduct.setName(name);
        pbProduct.setCost(cost);
        pbProduct.setSupplier(supplier);

        PBPackage.Builder pbPackage = pbProduct.getPackagingBuilder();
        pbPackage.setUnits(packaging.getUnits());
        pbPackage.setCostPerUnit(packaging.getCostPerUnit());

        message.setClothing(pbClothing);

    };
    @Override public void copyFromProto(PBStockItem message){
        PBClothing pbClothing = message.getClothing();
        name = pbClothing.getApparel().getProduct().getName();
        cost = pbClothing.getApparel().getProduct().getCost();
        supplier = pbClothing.getApparel().getProduct().getSupplier();
        packaging.setUnits(pbClothing.getApparel().getProduct().getPackaging().getUnits());
        packaging.setCostPerUnit(pbClothing.getApparel().getProduct().getPackaging().getCostPerUnit());
        material = pbClothing.getApparel().getMaterial();
        style = pbClothing.getStyle();
    };
}
