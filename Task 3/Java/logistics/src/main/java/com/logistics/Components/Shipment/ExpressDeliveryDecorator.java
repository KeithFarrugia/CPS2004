package com.logistics.Components.Shipment;

public class ExpressDeliveryDecorator extends ShipmentDecorator {
    private final float ExpressFee = 0.30f;

    public ExpressDeliveryDecorator(IShipment wrapped) {
        this.wrapped = wrapped;
    }

    @Override
    public void updateCost() {
        if(wrapped.getIsDispatched()){
            float newCost = wrapped.getCost() * (ExpressFee);
            wrapped.setCost(newCost);
        }else{
            System.out.println("ERROR: Cannnot change shipment since it has been dispatched");
        }
    }
}
