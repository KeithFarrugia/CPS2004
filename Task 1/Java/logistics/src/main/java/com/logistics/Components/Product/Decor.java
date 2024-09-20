package com.logistics.Components.Product;

public class Decor extends Furniture {

    private String style;

    public Decor() {
        super();
        style = "";
    }

    public Decor(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material, String style) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, material);
        this.style = style;
    }

    // Copy Constructor
    public Decor(Decor other) {
        super(other);
        this.style = other.style;
    }

    // Clone method
    @Override
    public Decor clone() {
        return new Decor(this);
    }

    // Getters
    public String getStyle() { return style; }

    // Setters
    public void setStyle(String style) { this.style = style; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nStyle: " + style;
    }
}
