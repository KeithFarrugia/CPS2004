package com.logistics.Components.Product;

import java.util.Calendar;

public class Product {
    protected float cost;
    protected String name;
    protected String supplier;
    protected float discountAmount;
    protected Packaging packaging;

    public Product() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
    }

    public Product(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
    }

    public Product(Product other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
    }

    // Getters
    public float getCost() { return cost; }
    public String getName() { return name; }
    public String getSupplier() { return supplier; }
    public float getDiscountAmount(){return discountAmount;}
    public float getPackagingCost() { return packaging.calculateTotalCost(); }

    // Setters
    public void setCost(float cost) { this.cost = cost; }
    public void setName(String name) { this.name = name; }
    public void setSupplier(String supplier) { this.supplier = supplier; }
    public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }

    // Clone method
    public Product clone() {
        return new Product(this);
    }

    public float calculateDiscount() {
        // Get the current month
        int currentMonth = Calendar.getInstance().get(Calendar.MONTH);

        // Check if the current month is December 
        if (currentMonth == Calendar.DECEMBER && (discountAmount >= 0 && discountAmount <= 1)) {
            return (1 - discountAmount);
        } else {
            return 1;
        }
    }

    public String display_product_info() {
        return "\nName: " + name +
               "\nCost: " + cost +
               "\nSupplier: " + supplier +
               "\nDiscount Amount: " + calculateDiscount() +
               "\nPackaging Cost: " + getPackagingCost();
    }
}
