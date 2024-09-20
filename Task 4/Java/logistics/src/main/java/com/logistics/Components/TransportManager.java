package com.logistics.Components;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import com.logistics.Components.Transport.Transport;
import com.logistics.Serialization.PBLogistics.PBTransportItem;
import com.logistics.Serialization.PBLogistics.PBTransportList;

public class TransportManager {
    private List<Transport> transportList;

    // Default constructor
    public TransportManager() {
        transportList = new ArrayList<>();
    }

    // Adds a new transport to the transport list
    public void addTransport(Transport newTransport) {
        if (newTransport == null) {
            return;
        }

        if (getTransport(newTransport.getCode()) == null) {
            transportList.add(newTransport);
            System.out.println("\nTransport Added\n");
            return;
        }

        System.out.println("\nERROR: Code Already in Use\n");
    }

    // Removes a transport from the transport list based on its code
    public void removeTransport(int code) {
        for (int i = 0; i < transportList.size(); i++) {
            if (transportList.get(i).getCode() == code) {
                transportList.remove(i);
                System.out.println("\nDeleted Successfully\n");
                return;
            }
        }
        System.out.println("\nERROR: Code not found\n");
    }

    // Updates a transport in the transport list based on its code
    public void updateTransport(int code, Transport newTransport) {
        if (newTransport == null) {
            return;
        }

        Transport toUpdate = getTransport(code);
        if (toUpdate != null) {
            // Check that the transport either has the same code as the one being updated or a different code
            if (newTransport.getCode() == toUpdate.getCode() ||
                    (newTransport.getCode() != toUpdate.getCode() && getTransport(newTransport.getCode()) == null)) {
                removeTransport(code);
                addTransport(newTransport);
                System.out.println("\nTransport Updated\n");
                return;
            }
            System.out.println("Transport was NOT Updated.\n");
        } else {
            System.out.println("Transport not found in Transport list.\n");
        }
    }

    // Retrieves a transport from the transport list based on its code
    public Transport getTransport(int code) {
        for (Transport t : transportList) {
            if (t.getCode() == code) {
                return t;
            }
        }
        return null;
    }

    // Displays all transports in the transport list
    public void displayTransports() {
        System.out.println("\n===========Transport List===========\n");
        for (Transport transport : transportList) {
            System.out.println("\n" + transport.to_string());
        }
    }

    // Displays a specific transport from the transport list based on its code
    public void displayTransports(int code) {
        Transport transport = getTransport(code);
        if (transport != null) {
            System.out.println("\n" + transport.to_string());
            return;
        }
        System.out.println("\nERROR: Code not found\n");
    }

    // Clears the transport list and manages memory
    public void clearTransport() {
        transportList.clear();
    }



    
    // ========================================== PROTOBUFFERS


    public void copyToProto(PBTransportList.Builder protobufTransportList){
        protobufTransportList.addAllTransportList(
            transportList.stream().map(transportItem -> {
                PBTransportItem.Builder message = PBTransportItem.newBuilder();
                transportItem.copyToProto(message); 
                return message.build();
            }).collect(Collectors.toList())
        );
    }


   public void copyFromProto(PBTransportList protobufTransportList) {
        clearTransport(); // Clear the existing stock

        // Iterate through protobuf stockitems and create corresponding Java StockItems objects
        for (PBTransportItem message : protobufTransportList.getTransportListList()) {

            if(message.hasAirTransport()){        // ----------------- AIR TRANSPORT
                Transport transport = TransportFactory.createTransport("AirTransport");
                transport.copyFromProto(message);
                transportList.add(transport);

            }else if(message.hasLandTransport()){ // ----------------- LAND TRANSPORT
                Transport transport = TransportFactory.createTransport("LandTransport");
                transport.copyFromProto(message);
                transportList.add(transport);

            }else if(message.hasLandTransport()){ // ----------------- SEA TRANSPORT
                Transport transport = TransportFactory.createTransport("SeaTransport");
                transport.copyFromProto(message);  
                transportList.add(transport);   

            }else{
                System.out.println("ERROR: Loaded Invalid Item");
            }
        }
    }
}
