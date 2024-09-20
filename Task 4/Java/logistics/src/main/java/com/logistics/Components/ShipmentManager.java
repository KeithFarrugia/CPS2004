package com.logistics.Components;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import com.logistics.Components.Shipment.Shipment;
import com.logistics.Serialization.PBLogistics.PBShipment;
import com.logistics.Serialization.PBLogistics.PBShipmentList;

public class ShipmentManager {
    private List<Shipment> shipments;

    // Default constructor
    public ShipmentManager() {
        shipments = new ArrayList<>();
    }

    // Adds a shipment to the shipment list
    public void addShipment(Shipment newShipment) {
        // Check if shipment ID is already in use
        if (getShipment(newShipment.getID()) == null) {
            shipments.add(newShipment);
            System.out.println("\n------Shipment Added------");
            System.out.printf("--------Code: %d--------\n", newShipment.getID());
            newShipment.updateCost();
            return;
        }
        System.out.println("\nERROR: ID Already in Use");
    }

    // Deletes a shipment from the shipment list based on its ID
    public void deleteShipment(int ID) {
        for (int i = 0; i < shipments.size(); i++) {
            if (shipments.get(i).getID() == ID) {
                // Memory Management
                if(shipments.get(i).getIsDispatched() == false){
                    shipments.get(i).getProductList().clearStock();
                    shipments.remove(i);
                    System.out.println("\nDeleted Successfully");
                }
                System.out.println("ERROR: Cannnot change shipment since it has been dispatched");
                return;
            }
        }
        System.out.println("\nERROR: ID NOT found");
    }

    // Displays information about all shipments in the shipment list
    public void viewShipment() {
        for (Shipment shipment : shipments) {
            System.out.printf("\nID: %d\n", shipment.getID());
            System.out.printf("Customer: %s\n", shipment.getCustomer());
            System.out.printf("Distance: %f\n", shipment.getDistance());
            System.out.printf("Total Cost: %.2f\n", shipment.getCost());
            System.out.printf("Estimated Time: %.2f\n", shipment.calculateTime());
            System.out.printf("Is dispatched: %s\n", (shipment.getIsDispatched()));
            System.out.println("=============Transport============= \n" + shipment.getTransport().to_string());
            System.out.println("=============Stock=============\n");
            shipment.getProductList().displayStock();
        }
    }

    // Displays information about a specific shipment in the shipment list based on its ID
    public void viewShipment(int ID) {
        Shipment shipment = getShipment(ID);
        if (shipment != null) {
            System.out.printf("\nID: %d\n", shipment.getID());
            System.out.printf("Customer: %s\n", shipment.getCustomer());
            System.out.printf("Distance: %f\n", shipment.getDistance());
            System.out.printf("Total Cost: %.2f\n", shipment.getCost());
            System.out.printf("Estimated Time: %.2f\n", shipment.calculateTime());
            System.out.printf("Is dispatched: %s\n", (shipment.getIsDispatched()));
            System.out.println("=============Transport============= \n" + shipment.getTransport().to_string());
            System.out.println("=============Stock=============\n");
            shipment.getProductList().displayStock();
            return;
        }
        System.out.println("\nERROR: ID NOT found");
    }

    // Retrieves a shipment from the shipment list based on its ID
    public Shipment getShipment(int ID) {
        for (Shipment shipment : shipments) {
            if (shipment.getID() == ID) {
                return shipment;
            }
        }
        return null;
    }

    // Clears the shipment list and manages memory
    public void clearShipment() {
        for (Shipment s : shipments) {
            s.deleteShipment();
        }
        shipments.clear();
    }

    public void dispatchShipment(int ID){
        Shipment shipment = getShipment(ID);
        if(shipment != null){
            shipment.setDispatched(true);
            return;
        }
    }



    // ========================================== PROTOBUFFERS


    public void copyToProto(PBShipmentList.Builder protobufShipmentList){
        protobufShipmentList.addAllShipmentList(
            shipments.stream().map(shipmentItem -> {
                PBShipment.Builder message = PBShipment.newBuilder();
                shipmentItem.copyToProto(message); 
                return message.build();
            }).collect(Collectors.toList())
        );
    }


   public void copyFromProto(PBShipmentList protobufShipmentList) {
        clearShipment(); // Clear the existing stock

        // Iterate through protobuf stockitems and create corresponding Java StockItems objects
        for (PBShipment message : protobufShipmentList.getShipmentListList()) {
            Shipment s = new Shipment();
            s.copyFromProto(message);
            shipments.add(s);
        }
    }
}
