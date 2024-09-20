package com.logistics.Components.Product;

import java.util.Calendar;

public class Tech implements Electronics {
    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private String manufacturer;
    private String type;

    public Tech() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        manufacturer = "";
        type = "";
    }

    public Tech(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String manufacturer, String type) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.manufacturer = manufacturer;
        this.type = type;
    }

    // Copy Constructor
    public Tech(Tech other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
        this.manufacturer = other.manufacturer;
        this.type = other.type;
    }

    // Clone method
    @Override public Tech clone() {
        return new Tech(this);
    }

    // Getters
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public String getManufacturer() { return manufacturer; }
    public String getType() { return type; }

    // Setters
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setManufacturer(String manufacturer) { this.manufacturer = manufacturer; }
    public void setType(String type) { this.type = type; }

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
                "\nManufacturer: " + manufacturer +
                "\nType: " + type;
    }
}
