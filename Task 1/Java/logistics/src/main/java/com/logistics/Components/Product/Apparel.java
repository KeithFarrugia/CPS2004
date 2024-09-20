package com.logistics.Components.Product;

public class Apparel extends Product {

    protected String material;

    public Apparel() {
        super();
        material = "";
    }

    public Apparel(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit);
        this.material = material;
    }

    public Apparel(Apparel other) {
        super(other);
        this.material = other.material;
    }

    @Override
    public Apparel clone() {
        return new Apparel(this);
    }

    //Getters
    public String getMaterial() { return material; }
    //Setters
    public void setMaterial(String material) { this.material = material; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nMaterial: " + material;
    }
}
