package com.logistics.Components.Product;

import java.util.Calendar;

import com.logistics.Serialization.PBLogistics.PBDigital;
import com.logistics.Serialization.PBLogistics.PBGames;
import com.logistics.Serialization.PBLogistics.PBPackage;
import com.logistics.Serialization.PBLogistics.PBProduct;
import com.logistics.Serialization.PBLogistics.PBStockItem;

public class Digital implements Games {
    private float cost;
    private String name;
    private String supplier;
    private float discountAmount;
    private Packaging packaging;
    private String genre;
    private String developer;

    public Digital() {
        cost = 0;
        name = "";
        supplier = "";
        discountAmount = 1;
        packaging = new Packaging(0, 0);
        genre = "";
        developer = "";
    }

    public Digital(String name, float cost, String supplier, float discountAmount, int packingUnits, float costPerUnit, String genre, String developer) {
        this.name = name;
        this.cost = cost;
        this.supplier = supplier;
        this.discountAmount = discountAmount;
        this.packaging = new Packaging(packingUnits, costPerUnit);
        this.genre = genre;
        this.developer = developer;
    }

    // Copy Constructor
    public Digital(Digital other) {
        this.name = other.name;
        this.cost = other.cost;
        this.supplier = other.supplier;
        this.discountAmount = other.discountAmount;
        this.packaging = new Packaging(other.packaging);
        this.genre = other.genre;
        this.developer = other.developer;
    }

    // Clone method
    @Override public Digital clone() {
        return new Digital(this);
    }

    // Getters
    @Override public float getCost() { return cost; }
    @Override public String getName() { return name; }
    @Override public String getSupplier() { return supplier; }
    @Override public float getDiscountAmount(){return discountAmount;}
    @Override public float getPackagingCost() { return packaging.calculateTotalCost(); }
    @Override public String getGenre() { return genre; }
    public String getDeveloper() { return developer; }

    // Setters
    @Override public void setCost(float cost) { this.cost = cost; }
    @Override public void setName(String name) { this.name = name; }
    @Override public void setSupplier(String supplier) { this.supplier = supplier; }
    @Override public void setDiscountAmount(float discountAmount){this.discountAmount = discountAmount;}
    @Override public void setPackagingData(int packingUnits, float costPerUnit) { this.packaging = new Packaging(packingUnits, costPerUnit); }
    @Override public void setGenre(String genre) { this.genre = genre; }
    public void setDeveloper(String developer) { this.developer = developer; }

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
                "\nDeveloper: " + developer;
    }

    // ========================================== PROTOBUFFERS
    @Override public void copyToProto(PBStockItem.Builder message){
        PBDigital.Builder pbDigital = PBDigital.newBuilder();
        pbDigital.setDeveloper(developer);

        PBGames.Builder pbGames = pbDigital.getGamesBuilder();
        pbGames.setGenre(genre);

        PBProduct.Builder pbProduct = pbGames.getProductBuilder();
        pbProduct.setName(name);
        pbProduct.setCost(cost);
        pbProduct.setSupplier(supplier);

        PBPackage.Builder pbPackage = pbProduct.getPackagingBuilder();
        pbPackage.setUnits(packaging.getUnits());
        pbPackage.setCostPerUnit(packaging.getCostPerUnit());

        message.setDigital(pbDigital);

    };
    @Override public void copyFromProto(PBStockItem message){
        PBDigital pbDigital = message.getDigital();
        name = pbDigital.getGames().getProduct().getName();
        cost = pbDigital.getGames().getProduct().getCost();
        supplier = pbDigital.getGames().getProduct().getSupplier();
        packaging.setUnits(pbDigital.getGames().getProduct().getPackaging().getUnits());
        packaging.setCostPerUnit(pbDigital.getGames().getProduct().getPackaging().getCostPerUnit());
        genre = pbDigital.getGames().getGenre();
        developer = pbDigital.getDeveloper();
    };
}
