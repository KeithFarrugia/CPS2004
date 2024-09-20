package com.logistics.Components.Product;

public class Flora extends Product {

    protected boolean isCultivated;

    public Flora() {
        super();
        isCultivated = false;
    }

    public Flora(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, boolean isCultivated) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit);
        this.isCultivated = isCultivated;
    }

    // Copy Constructor
    public Flora(Flora other) {
        super(other);
        this.isCultivated = other.isCultivated;
    }

    // Clone method
    @Override
    public Flora clone() {
        return new Flora(this);
    }

    // Getters
    public boolean getIsCultivated() { return isCultivated; }

    // Setters
    public void setIsCultivated(boolean isCultivated) { this.isCultivated = isCultivated; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nCultivated: " + isCultivated;
    }
}
