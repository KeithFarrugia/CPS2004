package com.logistics.Components.Shipment;

public class GlobalDiscountDecorator extends ShipmentDecorator{
    private final float globalDiscount = 0.20f;

    public GlobalDiscountDecorator(IShipment wrapped) {
        this.wrapped = wrapped;
    }
    
    @Override
    public void updateCost() {
        if(wrapped.getIsDispatched()){
            float newCost = wrapped.getCost() * (1 - globalDiscount);
            wrapped.setCost(newCost);
        }else{
            System.out.println("ERROR: Cannnot change shipment since it has been dispatched");
        }
    }
}
