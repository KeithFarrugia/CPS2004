package com.logistics.Components.Product;

public class Furniture extends Product {

    protected String material;

    public Furniture() {
        super();
        material = "";
    }

    public Furniture(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit);
        this.material = material;
    }

    // Copy Constructor
    public Furniture(Furniture other) {
        super(other);
        this.material = other.material;
    }

    // Clone method
    @Override
    public Furniture clone() {
        return new Furniture(this);
    }

    // Getters
    public String getMaterial() { return material; }

    // Setters
    public void setMaterial(String material) { this.material = material; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nMaterial: " + material;
    }
}
