package com.logistics.Components.Product;

public class Games extends Product {

    protected String genre;

    public Games() {
        super();
        genre = "";
    }

    public Games(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String genre) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit);
        this.genre = genre;
    }

    // Copy Constructor
    public Games(Games other) {
        super(other);
        this.genre = other.genre;
    }

    // Clone method
    @Override
    public Games clone() {
        return new Games(this);
    }

    // Getters
    public String getGenre() { return genre; }

    // Setters
    public void setGenre(String genre) { this.genre = genre; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nGenre: " + genre;
    }
}
