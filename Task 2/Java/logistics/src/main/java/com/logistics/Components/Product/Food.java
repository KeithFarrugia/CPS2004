package com.logistics.Components.Product;

import java.util.Calendar;

public class Food implements Consumable {

    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private int calories;
    private boolean isCanned;

    // Constructors
    public Food() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        calories = 0;
        isCanned = false;
    }

    public Food(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, int calories, boolean isCanned) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.calories = calories;
        this.isCanned = isCanned;
    }

    // Copy Constructor
    public Food(Food other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging); 
        this.calories = other.calories;
        this.isCanned = other.isCanned;
    }

    // Clone method
    @Override public Food clone() {
        return new Food(this);
    }

    // Getters
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public int getCalories() { return calories; }
    public boolean getIsCanned() { return isCanned; }

    // Setters
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setCalories(int calories) { this.calories = calories; }
    public void setIsCanned(boolean isCanned) { this.isCanned = isCanned; }

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
                "\nCalories: " + calories +
                "\nCanned: " + isCanned;
    }
}
