package com.logistics.Components.Product;

import java.util.Calendar;

public class Decor implements Furniture {
    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private String material;
    private String style;

    public Decor() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        material = "";
        style = "";
    }

    public Decor(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material, String style) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.material = material;
        this.style = style;
    }

    // Copy Constructor
    public Decor(Decor other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
        this.material = other.material;
        this.style = other.style;
    }

    // Clone method
    @Override public Decor clone() {
        return new Decor(this);
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
        return "\nName: " + name +
               "\nCost: " + cost +
               "\nSupplier: " + supplier +
               "\nDiscount Amount: " + calculateDiscount() +
               "\nPackaging Cost: " + getPackagingCost() + 
               "\nMaterial: " + material + 
               "\nStyle: " + style;
    }
}
