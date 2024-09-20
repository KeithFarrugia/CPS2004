package com.logistics.Components.Shipment;

import com.logistics.Components.Stock;
import com.logistics.Components.TransportManager;
import com.logistics.Components.Transport.Transport;

public interface IShipment {
    void addProduct(Stock stockList, String stockname, int quantity);
    void deleteProduct(Stock stockList, String stockname);
    boolean configureTransport(TransportManager transportManager, int code);
    float calculateTime();
    void updateCost();
    void deleteShipment();

    // Getters
    int getID();
    String getCustomer();
    Transport getTransport();
    Stock getProductList();
    float getDistance();
    float getCost();
    boolean getIsDispatched();

    // Setters
    void setID(int id);
    void setCustomer(String customer);
    void setTransport(Transport transport);
    void setProductList(Stock productlist);
    void setDistance(float d);
    void setDispatched(boolean dispatched);
    void setCost(float cost);
}
