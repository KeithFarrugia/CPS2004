package com.logistics.Components.Product;

public class Packaging {

    private int units;
    private float costPerUnit;

    public Packaging() {
        units = 0;
        costPerUnit = 0;
    }

    public Packaging(int units, float costPerUnit) {
        this.units = units;
        this.costPerUnit = costPerUnit;
    }

    public Packaging(Packaging other) {
        this.units = other.units;
        this.costPerUnit = other.costPerUnit;
    }

    // Getters
    public int getUnits() { return units; }
    public float getCostPerUnit() { return costPerUnit; }

    // Setters
    public void setUnits(int units) { this.units = units; }
    public void setCostPerUnit(float costPerUnit) { this.costPerUnit = costPerUnit; }

    public float calculateTotalCost() {
        return units * costPerUnit;
    }

    public String display_product_info() {
        return "Packaging Units: " + units + 
                "\nCost Per Unit: " + costPerUnit;
    }
}
