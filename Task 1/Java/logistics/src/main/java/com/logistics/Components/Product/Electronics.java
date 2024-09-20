package com.logistics.Components.Product;

public class Electronics extends Product {

    protected String manufacturer;

    public Electronics() {
        super();
        manufacturer = "";
    }

    public Electronics(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String manufacturer) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit);
        this.manufacturer = manufacturer;
    }

    // Copy Constructor
    public Electronics(Electronics other) {
        super(other);
        this.manufacturer = other.manufacturer;
    }

    // Clone method
    @Override
    public Electronics clone() {
        return new Electronics(this);
    }

    // Getters
    public String getManufacturer() { return manufacturer; }

    // Setters
    public void setManufacturer(String manufacturer) { this.manufacturer = manufacturer; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nManufacturer: " + manufacturer;
    }
}
