package com.logistics.Components.Shipment;

import com.logistics.Components.Stock;
import com.logistics.Components.TransportManager;
import com.logistics.Components.Transport.Transport;

public abstract class ShipmentDecorator implements IShipment {
    protected IShipment wrapped;
    
    @Override public void addProduct(Stock stockList, String stockname, int quantity){wrapped.addProduct(stockList, stockname, quantity);};
    @Override public void deleteProduct(Stock stockList, String stockname){wrapped.deleteProduct(stockList, stockname);};
    @Override public boolean configureTransport(TransportManager transportManager, int code){return wrapped.configureTransport(transportManager, code);};
    @Override public float calculateTime(){return wrapped.calculateTime();};
    @Override public void updateCost(){wrapped.updateCost();};
    @Override public void deleteShipment(){wrapped.deleteShipment();};

    @Override public int getID() {return wrapped.getID();}
    @Override public String getCustomer() { return wrapped.getCustomer();}
    @Override public Transport getTransport() { return wrapped.getTransport();}
    @Override public Stock getProductList() { return wrapped.getProductList();}
    @Override public float getDistance() { return wrapped.getDistance(); }
    @Override public boolean getIsDispatched(){return wrapped.getIsDispatched();}
    @Override public float getCost() { return wrapped.getCost(); }
    
    @Override public void setID(int id){wrapped.setID(id);};
    @Override public void setCustomer(String customer){wrapped.setCustomer(customer);};
    @Override public void setTransport(Transport transport){wrapped.setTransport(transport);};
    @Override public void setProductList(Stock productlist){wrapped.setProductList(productlist);};
    @Override public void setDistance(float d){wrapped.setDistance(d);};
    @Override public void setDispatched(boolean dispatched){wrapped.setDispatched(dispatched);}
    @Override public void setCost(float cost){wrapped.setCost(cost);};

    public void setShipmentI(IShipment wrapper){this.wrapped = wrapper;};
}
