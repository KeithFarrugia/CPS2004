package com.logistics.Components.Product;

import java.util.Calendar;

import com.logistics.Serialization.PBLogistics.PBConsumable;
import com.logistics.Serialization.PBLogistics.PBDrink;
import com.logistics.Serialization.PBLogistics.PBPackage;
import com.logistics.Serialization.PBLogistics.PBProduct;
import com.logistics.Serialization.PBLogistics.PBStockItem;

public class Drink implements Consumable {
    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private int calories;
    private boolean isCarbonated;

    public Drink() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        calories = 0;
        isCarbonated = false;
    }

    public Drink(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, int calories, boolean isCarbonated) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.calories = calories;
        this.isCarbonated = isCarbonated;
    }

    // Copy Constructor
    public Drink(Drink other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging); 
        this.calories = other.calories;
        this.isCarbonated = other.isCarbonated;
    }

    // Clone method
    @Override  public Drink clone() {
        return new Drink(this);
    }

    // Getters
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public int getCalories() { return calories; }
    public boolean getIsCarbonated() { return isCarbonated; }

    // Setters
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setCalories(int calories) { this.calories = calories; }
    public void setIsCarbonated(boolean isCarbonated) { this.isCarbonated = isCarbonated; }
    
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
                "\nCalories: " + calories +
                "\nCarbonated: " + isCarbonated;
    }

    // ========================================== PROTOBUFFERS
    @Override public void copyToProto(PBStockItem.Builder message){
        PBDrink.Builder pbDrink = PBDrink.newBuilder();
        pbDrink.setIsCarbonated(isCarbonated);

        PBConsumable.Builder pbConsumable = pbDrink.getConsumableBuilder();
        pbConsumable.setCalories(calories);

        PBProduct.Builder pbProduct = pbConsumable.getProductBuilder();
        pbProduct.setName(name);
        pbProduct.setCost(cost);
        pbProduct.setSupplier(supplier);

        PBPackage.Builder pbPackage = pbProduct.getPackagingBuilder();
        pbPackage.setUnits(packaging.getUnits());
        pbPackage.setCostPerUnit(packaging.getCostPerUnit());

        message.setDrink(pbDrink);

    };
    @Override public void copyFromProto(PBStockItem message){
        PBDrink pbDrink = message.getDrink();
        name = pbDrink.getConsumable().getProduct().getName();
        cost = pbDrink.getConsumable().getProduct().getCost();
        supplier = pbDrink.getConsumable().getProduct().getSupplier();
        packaging.setUnits(pbDrink.getConsumable().getProduct().getPackaging().getUnits());
        packaging.setCostPerUnit(pbDrink.getConsumable().getProduct().getPackaging().getCostPerUnit());
        calories = pbDrink.getConsumable().getCalories();
        isCarbonated = pbDrink.getIsCarbonated();
    };
}
