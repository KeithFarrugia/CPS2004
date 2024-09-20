package com.logistics.Components.Product;

public class Accessory extends Apparel {

    private String brand;

    public Accessory() {
        super();
        brand = "";
    }

    public Accessory(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material, String brand) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, material);
        this.brand = brand;
    }

    public Accessory(Accessory other) {
        super(other);
        this.brand = other.brand;
    }

    @Override
    public Accessory clone() {
        return new Accessory(this);
    }

    // Getters
    public String getBrand() { return brand; }

    // Setters
    public void setBrand(String brand) { this.brand = brand; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nBrand: " + brand;
    }
}
