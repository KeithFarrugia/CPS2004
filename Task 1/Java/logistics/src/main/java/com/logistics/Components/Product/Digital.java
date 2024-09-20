package com.logistics.Components.Product;

public class Digital extends Games {

    private String developer;

    public Digital() {
        super();
        developer = "";
    }

    public Digital(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String genre, String developer) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, genre);
        this.developer = developer;
    }

    // Copy Constructor
    public Digital(Digital other) {
        super(other);
        this.developer = other.developer;
    }

    // Clone method
    @Override
    public Digital clone() {
        return new Digital(this);
    }

    // Getters
    public String getDeveloper() { return developer; }

    // Setters
    public void setDeveloper(String developer) { this.developer = developer; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + "\nDeveloper: " + developer;
    }
}
