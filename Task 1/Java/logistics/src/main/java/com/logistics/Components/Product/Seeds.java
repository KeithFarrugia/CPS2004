package com.logistics.Components.Product;

public class Seeds extends Flora {

    private int expirationDays;

    public Seeds() {
        super();
        expirationDays = 0;
    }

    public Seeds(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, boolean isCultivated, int expirationDays) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, isCultivated);
        this.expirationDays = expirationDays;
    }

    // Copy Constructor
    public Seeds(Seeds other) {
        super(other);
        this.expirationDays = other.expirationDays;
    }

    // Clone method
    @Override
    public Seeds clone() {
        return new Seeds(this);
    }

    // Getters
    public int getExpirationDays() { return expirationDays; }

    // Setters
    public void setExpirationDays(int expirationDays) { this.expirationDays = expirationDays; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nExpiration Days: " + expirationDays;
    }
}
