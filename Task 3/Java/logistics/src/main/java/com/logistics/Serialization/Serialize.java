package com.logistics.Serialization;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import com.logistics.Components.ShipmentManager;
import com.logistics.Components.Stock;
import com.logistics.Components.TransportManager;
import com.logistics.Serialization.PBLogistics.PBShipmentList;
import com.logistics.Serialization.PBLogistics.PBStock;
import com.logistics.Serialization.PBLogistics.PBTransportList;

public class Serialize {
    static final String stockFile = "stock.pb";
    static final String transportFile = "transport.pb";
    static final String shipmentFile = "shipment.pb";

    public static void save(ShipmentManager shipmentManager, TransportManager transportManager, Stock stock){

        //------------------- Convert To Protobuf -------------------------

        PBStock.Builder protobufStockBuilder = PBStock.newBuilder();
        stock.copyToProto(protobufStockBuilder);
        PBTransportList.Builder protobufTransportManagerBuilder = PBTransportList.newBuilder();
        transportManager.copyToProto(protobufTransportManagerBuilder);
        PBShipmentList.Builder protobufShipmentManagerBuilder = PBShipmentList.newBuilder();
        shipmentManager.copyToProto(protobufShipmentManagerBuilder);

        // Build builders
        PBStock protobufStock = protobufStockBuilder.build();
        PBTransportList protobufTransportManager = protobufTransportManagerBuilder.build();
        PBShipmentList protobufShipmentManager = protobufShipmentManagerBuilder.build();

        //------------------- SAVING -------------------------

        // SAVING STOCK
        try (FileOutputStream output = new FileOutputStream(stockFile)) {
            protobufStock.writeTo(output);
            System.out.println("Protobuf data saved to file: " + stockFile);
        } catch (IOException e) { System.err.println("Unable to open file for saving protobuf data: " + stockFile); }

        // SAVING TRANSPORT
        try (FileOutputStream output = new FileOutputStream(transportFile)) {
            protobufTransportManager.writeTo(output);
            System.out.println("Protobuf data saved to file: " + transportFile);
        } catch (IOException e) { System.err.println("Unable to open file for saving protobuf data: " + transportFile); }

        // SAVING SHIPMENTS
        try (FileOutputStream output = new FileOutputStream(shipmentFile)) {
            protobufShipmentManager.writeTo(output);
            System.out.println("Protobuf data saved to file: " + stockFile);
        } catch (IOException e) { System.err.println("Unable to open file for saving protobuf data: " + shipmentFile); }
    }





    public static void load(ShipmentManager shipmentManager, TransportManager transportManager, Stock stock){
        PBStock protobufStock = null;
        PBTransportList protobufTransportManager = null;
        PBShipmentList protobufShipmentManager = null;


        //------------------- LOADING -------------------------
        try (FileInputStream input = new FileInputStream(stockFile)) {
            protobufStock = PBStock.parseFrom(input);
            System.out.println("Protobuf data read from file: " + stockFile);
        }catch (IOException e) { System.err.println("Unable to open file for reading protobuf data: " + stockFile); }  


        try (FileInputStream input = new FileInputStream(transportFile)) {
            protobufTransportManager = PBTransportList.parseFrom(input);
            System.out.println("Protobuf data read from file: " + transportFile);
        }catch (IOException e) { System.err.println("Unable to open file for reading protobuf data: " + stockFile); } 


        try (FileInputStream input = new FileInputStream(shipmentFile)) {
            protobufShipmentManager = PBShipmentList.parseFrom(input);
            System.out.println("Protobuf data read from file: " + shipmentFile);
        }catch (IOException e) { System.err.println("Unable to open file for reading protobuf data: " + shipmentFile); } 


        //------------------- Convert To JAVA -------------------------
        if (protobufStock != null) {
            stock.copyFromProto(protobufStock);
        }
    
        if (protobufTransportManager != null) {
            transportManager.copyFromProto(protobufTransportManager);
        }
    
        if (protobufShipmentManager != null) {
            shipmentManager.copyFromProto(protobufShipmentManager);
        }
    }
}
