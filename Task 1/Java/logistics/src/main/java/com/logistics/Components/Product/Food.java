package com.logistics.Components.Product;

public class Food extends Consumable {

    private boolean isCanned;

    // Constructors
    public Food() {
        super();
        isCanned = false;
    }

    public Food(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, int calories, boolean isCanned) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, calories);
        this.isCanned = isCanned;
    }

    // Copy Constructor
    public Food(Food other) {
        super(other); // Call the copy constructor of the superclass (Consumable)
        this.isCanned = other.isCanned;
    }

    // Clone method
    @Override
    public Food clone() {
        return new Food(this);
    }

    // Getters
    public boolean getIsCanned() { return isCanned; }

    // Setters
    public void setIsCanned(boolean isCanned) { this.isCanned = isCanned; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nCanned: " + isCanned;
    }
}
