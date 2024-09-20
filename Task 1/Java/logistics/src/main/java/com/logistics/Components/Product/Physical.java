package com.logistics.Components.Product;

public class Physical extends Games {

    private int numberOfPlayers;

    public Physical() {
        super();
        numberOfPlayers = 0;
    }

    public Physical(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String genre, int numberOfPlayers) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, genre);
        this.numberOfPlayers = numberOfPlayers;
    }

    // Copy Constructor
    public Physical(Physical other) {
        super(other);
        this.numberOfPlayers = other.numberOfPlayers;
    }

    // Clone method
    @Override
    public Physical clone() {
        return new Physical(this);
    }

    // Getters
    public int getNumberOfPlayers() { return numberOfPlayers; }

    // Setters
    public void setNumberOfPlayers(int numberOfPlayers) { this.numberOfPlayers = numberOfPlayers; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nNumber of Players: " + numberOfPlayers;
    }
}
