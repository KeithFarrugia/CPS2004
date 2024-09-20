package com.logistics.Components.Product;

public class Plants extends Flora {

    private boolean bearsFruit;

    public Plants() {
        super();
        bearsFruit = false;
    }

    public Plants(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, boolean isCultivated, boolean bearsFruit) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, isCultivated);
        this.bearsFruit = bearsFruit;
    }

    // Copy Constructor
    public Plants(Plants other) {
        super(other);
        this.bearsFruit = other.bearsFruit;
    }

    // Clone method
    @Override
    public Plants clone() {
        return new Plants(this);
    }

    // Getters
    public boolean getBearsFruit() { return bearsFruit; }

    // Setters
    public void setBearsFruit(boolean bearsFruit) { this.bearsFruit = bearsFruit; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nBears Fruit: " + bearsFruit;
    }
}
