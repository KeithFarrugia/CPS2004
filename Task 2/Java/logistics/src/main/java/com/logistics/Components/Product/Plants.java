package com.logistics.Components.Product;

import java.util.Calendar;

public class Plants implements Flora {
    protected float cost;
    protected String name;
    protected String supplier;
    protected float discountAmount;
    protected Packaging packaging;
    protected boolean isCultivated;
    private boolean bearsFruit;

    public Plants() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        isCultivated = false;
        bearsFruit = false;
    }

    public Plants(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, boolean isCultivated, boolean bearsFruit) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.isCultivated = isCultivated;
        this.bearsFruit = bearsFruit;
    }

    // Copy Constructor
    public Plants(Plants other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
        this.isCultivated = other.isCultivated;
        this.bearsFruit = other.bearsFruit;
    }

    // Clone method
    @Override public Plants clone() {
        return new Plants(this);
    }

    // Getters
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public boolean getIsCultivated() { return isCultivated; }
    public boolean getBearsFruit() { return bearsFruit; }

    // Setters
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setIsCultivated(boolean isCultivated) { this.isCultivated = isCultivated; }
    public void setBearsFruit(boolean bearsFruit) { this.bearsFruit = bearsFruit; }

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
                "\nCultivated: " + isCultivated +
                "\nBears Fruit: " + bearsFruit;
    }
}
