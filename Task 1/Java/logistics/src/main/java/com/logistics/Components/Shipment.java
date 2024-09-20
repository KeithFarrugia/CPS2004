package com.logistics.Components;

import java.util.List;

import com.logistics.Components.Transport.Transport;

public class Shipment {
    private static int GlobalId = 0;

    private int ID;
    private String customer;
    private Transport transport;
    private Stock productlist = new Stock();
    private float distance;
    private float cost;
    private boolean dispatched;

    // Default constructor, automatically increments ID
    public Shipment() {
        this.ID = GlobalId++;
        this.customer = "";
        this.transport = null;
        this.distance = 0;
        dispatched = false;
    }

    // Parameterized constructor
    public Shipment(int ID, String customer, Transport transport, float distance) {
        this.ID = ID;
        this.customer = customer;
        this.transport = transport.clone(); // Using clone to create a deep copy
        this.distance = distance;
        dispatched = false;
    }

    // Adds a product to the shipment
    public void addProduct(Stock stockList, String stockname, int quantity) {
        if(dispatched == false){ // check if dispatched
            Stock.stockItem_t stock = stockList.getStock(stockname);

            if (stock == null) {
                System.out.println("ERROR: Stock not found");
                return;
            } else {
                if (stock.q >= quantity) {
                    // Create a new stock item for the shipment
                    Stock.stockItem_t newStock = new Stock.stockItem_t(stock.p.clone(), quantity);
                    stock.q -= quantity;
                    productlist.addStock(newStock);
                    System.out.println("\n--Product Added--\n");
                    return;
                }
                System.out.println("ERROR: Cannot take more than what currently is in stock");
            }
        }else{
            System.out.println("ERROR: Cannnot change shipment since it has been dispatched");
        }
    }

    // Deletes a product from the shipment
    public void deleteProduct(Stock stockList, String stockname) {
        if(dispatched == false){ // check if dispatched
            Stock.stockItem_t stock = stockList.getStock(stockname);
            Stock.stockItem_t toDelete = productlist.getStock(stockname);

            if (stock != null && toDelete != null) {
                // Return the quantity to the stock since the order was canceled
                stock.q += toDelete.q;
            }
            productlist.removeStock(stockname);
        }else{
            System.out.println("ERROR: Cannnot change shipment since it has been dispatched");
        }
    }

    // Configures the transport for the shipment
    public boolean configureTransport(TransportManager transportManager, int code) {
        if(dispatched == false){// check if dispatched
            Transport newTransport = transportManager.getTransport(code);

            if (newTransport == null) {
                System.out.println("ERROR: Transport not found");
                return false;
            } else {
                // Use clone to create a deep copy of the new transport
                transport = newTransport.clone();
                return true;
            }
        }else{
            System.out.println("ERROR: Cannnot change shipment since it has been dispatched");
            return false;
        }
    }

    // Calculates the total cost of the shipment
    private float calculateTotalCost() {
        float totalCost = 0;

        List<Stock.stockItem_t> stockList = productlist.getStockList();

        for (Stock.stockItem_t product : stockList) {
            // Add cost of item for each item ordered
            totalCost += product.p.getCost() * product.p.calculateDiscount() * product.q;
            // Add the cost of packaging for each item
            totalCost += product.p.getPackagingCost() * product.q;
        }

        // Add transportation cost
        totalCost += transport.calcPrice(distance);

        return totalCost;
    }

    // Estimates the delivery time for the shipment
    public float calculateTime() {
        return transport.estimateDeliveryTime(distance);
    }

    // Updates the cost of the shipment
    public void updateCost() {
        if(dispatched == false){// check if dispatched
            cost = (int) calculateTotalCost();
        }
    }

    // Deletes the shipment, freeing resources
    public void deleteShipment() {
        if (transport != null) {
            transport = null;
        }
        productlist.clearStock();
    }

    // Getters
    public int getID() {return ID;}
    public String getCustomer() {return customer;}
    public Transport getTransport() {return transport;}
    public Stock getProductList() {return productlist;}
    public float getDistance() {return distance;}
    public float getCost() {return cost;}
    public boolean getIsDispatched(){return dispatched;}

    // Setters
    public void setID(int id) {ID = id;}
    public void setCustomer(String customer) {this.customer = customer; }
    public void setTransport(Transport transport) {this.transport = transport.clone(); }// Using clone to create a deep copy
    public void setProductList(Stock productlist) {this.productlist = productlist; }
    public void setDistance(float d) {distance = d;}
    public void setDispatched(boolean dispatched){this.dispatched = dispatched;}
    public void setCost(float cost){this.cost = cost;};
}
