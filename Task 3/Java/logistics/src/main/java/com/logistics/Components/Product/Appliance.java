package com.logistics.Components.Product;

import java.util.Calendar;

import com.logistics.Serialization.PBLogistics.PBAppliance;
import com.logistics.Serialization.PBLogistics.PBElectronics;
import com.logistics.Serialization.PBLogistics.PBPackage;
import com.logistics.Serialization.PBLogistics.PBProduct;
import com.logistics.Serialization.PBLogistics.PBStockItem;

public class Appliance implements Electronics {
    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private String manufacturer;
    private String size;

    public Appliance() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        manufacturer = "";
        size = "";
    }

    public Appliance(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String manufacturer, String size) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.manufacturer = manufacturer;
        this.size = size;
    }

    // Copy Constructor
    public Appliance(Appliance other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
        this.manufacturer = other.manufacturer;
        this.size = other.size;
    }

    // Clone method
    @Override  public Appliance clone() {
        return new Appliance(this);
    }

    // Getter
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public String getManufacturer() { return manufacturer; }
    public String getSize() { return size; }

    // Setter
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setManufacturer(String manufacturer) { this.manufacturer = manufacturer; }
    public void setSize(String size) { this.size = size; }


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
                "\nManufacturer: " + manufacturer +
                "\nSize: " + size;
    }

    
    // ========================================== PROTOBUFFERS
    @Override public void copyToProto(PBStockItem.Builder message){
        PBAppliance.Builder pbAppliance = PBAppliance.newBuilder();
        pbAppliance.setSize(size);

        PBElectronics.Builder pbElectronics = pbAppliance.getElectronicsBuilder();
        pbElectronics.setManufacturer(manufacturer);

        PBProduct.Builder pbProduct = pbElectronics.getProductBuilder();
        pbProduct.setName(name);
        pbProduct.setCost(cost);
        pbProduct.setSupplier(supplier);

        PBPackage.Builder pbPackage = pbProduct.getPackagingBuilder();
        pbPackage.setUnits(packaging.getUnits());
        pbPackage.setCostPerUnit(packaging.getCostPerUnit());

        message.setAppliance(pbAppliance);

    };
    @Override public void copyFromProto(PBStockItem message){
        PBAppliance pbAppliance = message.getAppliance();
        name = pbAppliance.getElectronics().getProduct().getName();
        cost = pbAppliance.getElectronics().getProduct().getCost();
        supplier = pbAppliance.getElectronics().getProduct().getSupplier();
        packaging.setUnits(pbAppliance.getElectronics().getProduct().getPackaging().getUnits());
        packaging.setCostPerUnit(pbAppliance.getElectronics().getProduct().getPackaging().getCostPerUnit());
        manufacturer = pbAppliance.getElectronics().getManufacturer();
        size = pbAppliance.getSize();
    };


}
