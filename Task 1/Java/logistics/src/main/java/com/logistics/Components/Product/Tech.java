package com.logistics.Components.Product;

public class Tech extends Electronics {

    private String type;

    public Tech() {
        super();
        type = "";
    }

    public Tech(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String manufacturer, String type) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, manufacturer);
        this.type = type;
    }

    // Copy Constructor
    public Tech(Tech other) {
        super(other);
        this.type = other.type;
    }

    // Clone method
    @Override
    public Tech clone() {
        return new Tech(this);
    }

    // Getters
    public String getType() { return type; }

    // Setters
    public void setType(String type) { this.type = type; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nType: " + type;
    }
}
