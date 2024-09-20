package com.logistics.Components.Product;

public class Storage extends Furniture {

    private int capacity;

    public Storage() {
        super();
        capacity = 0;
    }

    public Storage(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String material, int capacity) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, material);
        this.capacity = capacity;
    }

    // Copy Constructor
    public Storage(Storage other) {
        super(other);
        this.capacity = other.capacity;
    }

    // Clone method
    @Override
    public Storage clone() {
        return new Storage(this);
    }

    // Getters
    public int getCapacity() { return capacity; }

    // Setters
    public void setCapacity(int capacity) { this.capacity = capacity; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nCapacity: " + capacity;
    }
}
