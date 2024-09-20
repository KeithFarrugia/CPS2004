package com.logistics.Components;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import com.logistics.Components.Product.Product;
import com.logistics.Serialization.PBLogistics.PBStock;
import com.logistics.Serialization.PBLogistics.PBStockItem;

public class Stock {
    public static class stockItem_t {
        public Product p;
        public int q;
        public stockItem_t(){this.p = null; this.q = 0;}
        public stockItem_t(Product p, int q){this.p = p; this.q = q;}
    }

    private List<stockItem_t> stockList;

    // Default constructor
    public Stock() {
        stockList = new ArrayList<>();
    }

    // Getter for the stock list
    public List<stockItem_t> getStockList() {return stockList;}

    // Adds a stock item to the stock list
    public void addStock(stockItem_t newStock) {
        if (newStock.p == null) {
            return;
        }

        // Check for duplication of item
        if (getStock(newStock.p.getName()) == null) {
            stockList.add(newStock);
            return;
        }

        System.out.println("ERROR: Item with the same name is already in stock");
    }

    // Removes a stock item from the stock list
    public void removeStock(String stockName) {
        // Search for the item to remove
        for (int i = 0; i < stockList.size(); i++) {
            if (stockList.get(i).p.getName().equals(stockName)) {
                stockList.remove(i);
                System.out.println("\nDeleted Successfully\n");
                return;
            }
        }
        System.out.println("\nERROR: Stock not found"); // not deleted
    }

    // Updates a stock item in the stock list
    public void updateStock(String stockName, stockItem_t newStock) {
        if (newStock.p == null) {
            return;
        }
        stockItem_t toUpdate = getStock(stockName);
        if (toUpdate != null) {
            // Check that the product either has the same name as the one being updated or a different name
            if (newStock.p.getName().equals(toUpdate.p.getName()) ||
               (!newStock.p.getName().equals(toUpdate.p.getName()) && getStock(newStock.p.getName()) == null)) {
                removeStock(stockName);
                addStock(newStock);
                System.out.println("\nStock Updated\n");
                return;
            }
            System.out.println("Stock was NOT Updated.\n");
        } else {
            System.out.println("Stock not found.\n");
        }
    }

    // Increases the quantity of a stock item in the stock list
    public void increaseStock(String stockName, int newQuantity) {
        // Search for the item to increase stock
        stockItem_t toIncrease = getStock(stockName);
        if (toIncrease != null) {
            toIncrease.q += newQuantity;
            return;
        }
        System.out.println("Stock not found.\n");
    }

    // Clears the stock list and manages memory
    public void clearStock() {
        // Memory Management
        for (stockItem_t item : stockList) {
            item.p = null;
        }
        stockList.clear();
    }

    // Retrieves a stock item from the stock list based on its name
    public stockItem_t getStock(String stockName) {
        for (stockItem_t stock : stockList) {
            if (stock.p.getName().equals(stockName)) {
                return stock;
            }
        }
        return null;
    }

    // Displays all stock items
    public void displayStock() {
        // Traverse and display
        System.out.println("Stock Items:");
        for (stockItem_t item : stockList) {
            System.out.printf("\n%s", item.p.display_product_info());
            System.out.printf("\nQuantity: %s\n", item.q);
        }
    }

    // Displays a specific stock item based on its name
    public void displayStock(String stockName) {
        // Traverse and display
        stockItem_t item = getStock(stockName);
        if (item != null) {
            System.out.printf("\n%s", item.p.display_product_info());
            System.out.printf("\nQuantity: %s\n", item.q);
            return;
        }
        System.out.println("\nERROR: Stock not found");
    }





    // ========================================== PROTOBUFFERS


    public void copyToProto(PBStock.Builder protobufStockList){
        protobufStockList.addAllStock(
            stockList.stream().map(stockItem -> {
                PBStockItem.Builder message = PBStockItem.newBuilder();
                stockItem.p.copyToProto(message);
                message.setQuantity(stockItem.q);
                return message.build();
            }).collect(Collectors.toList())
        );
    }


   public void copyFromProto(PBStock protobufStockList) {
        clearStock(); // Clear the existing stock

        // Iterate through protobuf stockitems and create corresponding Java StockItems objects
        for (PBStockItem message : protobufStockList.getStockList()) {

            if (message.hasAccessory()) {               // -------------------------------- ACCESSORY

                Product p = ProductFactory.createProduct("Accessory");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));

            } else if (message.hasClothing()) {         // -------------------------------- CLOTHING

                Product p = ProductFactory.createProduct("Clothing");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));

            } else if (message.hasFood()) {             // -------------------------------- FOOD

                Product p = ProductFactory.createProduct("Food");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else if (message.hasDrink()) {            // -------------------------------- DRINK

                Product p = ProductFactory.createProduct("Drink");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else if (message.hasTech()) {              // -------------------------------- TECH

                Product p = ProductFactory.createProduct("Tech");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else if (message.hasAppliance()) {        // -------------------------------- APPLIANCE

                Product p = ProductFactory.createProduct("Appliance");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else if (message.hasDecor()) {             // -------------------------------- DECOR

                Product p = ProductFactory.createProduct("Decor");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else if (message.hasStorage()) {           // -------------------------------- STORAGE

                Product p = ProductFactory.createProduct("Storage");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else if (message.hasDigital()) {           // -------------------------------- DIGITAL

                Product p = ProductFactory.createProduct("Digital");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else if (message.hasPhysical()) {         // --------------------------------  PHYSICAL

                Product p = ProductFactory.createProduct("Physical");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else if (message.hasPlants()) {           // -------------------------------- PLANTS

                Product p = ProductFactory.createProduct("Plants");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            }  else if (message.hasSeeds()) {           // -------------------------------- SEEDS

                Product p = ProductFactory.createProduct("Seeds");
                p.copyFromProto(message);
                addStock(new stockItem_t(p, message.getQuantity()));
                
            } else{
                System.out.println("ERROR: Loaded Invalid Item");
            }
        }
    }
}
     

