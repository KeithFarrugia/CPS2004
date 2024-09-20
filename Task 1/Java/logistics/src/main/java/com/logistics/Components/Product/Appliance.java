package com.logistics.Components.Product;

public class Appliance extends Electronics {

    private String size;

    public Appliance() {
        super();
        size = "";
    }

    public Appliance(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String manufacturer, String size) {
        super(name, cost, supplier, discountAmount, packingUnits, costPerUnit, manufacturer);
        this.size = size;
    }

    // Copy Constructor
    public Appliance(Appliance other) {
        super(other);
        this.size = other.size;
    }

    // Clone method
    @Override
    public Appliance clone() {
        return new Appliance(this);
    }

    // Getter
    public String getSize() { return size; }

    // Setter
    public void setSize(String size) { this.size = size; }

    @Override
    public String display_product_info() {
        return super.display_product_info() + 
                "\nSize: " + size;
    }
}
