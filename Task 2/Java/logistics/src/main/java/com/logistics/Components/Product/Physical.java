package com.logistics.Components.Product;

import java.util.Calendar;

public class Physical implements Games {
    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private String genre;
    private int numberOfPlayers;

    public Physical() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        genre = "";
        numberOfPlayers = 0;
    }

    public Physical(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String genre, int numberOfPlayers) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.genre = genre;
        this.numberOfPlayers = numberOfPlayers;
    }

    // Copy Constructor
    public Physical(Physical other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
        this.genre = other.genre;
        this.numberOfPlayers = other.numberOfPlayers;
    }

    // Clone method
    @Override public Physical clone() {
        return new Physical(this);
    }

    // Getters
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public String getGenre() { return genre; }
    public int getNumberOfPlayers() { return numberOfPlayers; }

    // Setters
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setGenre(String genre) { this.genre = genre; }
    public void setNumberOfPlayers(int numberOfPlayers) { this.numberOfPlayers = numberOfPlayers; }
    
    @Override public float calculateDiscount() {
        // Get the current month
        int currentMonth = Calendar.getInstance().get(Calendar.MONTH);

        // Check if the current month is December 
        if (currentMonth == Calendar.DECEMBER && (discountAmount >= 0 && discountAmount <= 1)) {
            return (1 - discountAmount);
        } else {
            return 1;
        }
    }

    @Override public String display_product_info() {
        return  "\nName: " + name +
                "\nCost: " + cost +
                "\nSupplier: " + supplier +
                "\nDiscount Amount: " + calculateDiscount() +
                "\nPackaging Cost: " + getPackagingCost() +
                "\nGenre: " + genre + 
                "\nNumber of Players: " + numberOfPlayers;
    }
}
