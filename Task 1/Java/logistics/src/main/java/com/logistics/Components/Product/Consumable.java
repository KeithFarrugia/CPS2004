package com.logistics.Components.Product;

public class Consumable extends Product {

    protected int calories;

    public Consumable() {
        super();
        calories = 0;
    }

    public Consumable(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, int calories) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit);
        this.calories = calories;
    }

    // Copy Constructor
    public Consumable(Consumable other) {
        super(other);
        this.calories = other.calories;
    }

    // Clone method
    @Override
    public Consumable clone() {
        return new Consumable(this);
    }

    // Getters
    public int getCalories() { return calories; }

    // Setters
    public void setCalories(int calories) { this.calories = calories; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + "\nCalories: " + calories;
    }
}
