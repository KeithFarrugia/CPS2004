package com.logistics.Components.Product;

public class Drink extends Consumable {

    private boolean isCarbonated;

    public Drink() {
        super();
        isCarbonated = false;
    }

    public Drink(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, int calories, boolean isCarbonated) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, calories);
        this.isCarbonated = isCarbonated;
    }

    // Copy Constructor
    public Drink(Drink other) {
        super(other);
        this.isCarbonated = other.isCarbonated;
    }

    // Clone method
    @Override
    public Drink clone() {
        return new Drink(this);
    }

    // Getters
    public boolean getIsCarbonated() { return isCarbonated; }

    // Setters
    public void setIsCarbonated(boolean isCarbonated) { this.isCarbonated = isCarbonated; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nCarbonated: " + isCarbonated;
    }
}
