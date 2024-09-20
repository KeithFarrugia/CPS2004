package com.logistics.Components.Product;

public class Clothing extends Apparel {

    private String style;

    public Clothing() {
        super();
        style = "";
    }

    public Clothing(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material, String style) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, material);
        this.style = style;
    }

    // Copy Constructor
    public Clothing(Clothing other) {
        super(other);
        this.style = other.style;
    }

    // Clone method
    @Override
    public Clothing clone() {
        return new Clothing(this);
    }

    // Getters
    public String getStyle() { return style; }

    // Setters
    public void setStyle(String style) { this.style = style; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + "\nStyle: " + style;
    }
}
