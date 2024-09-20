package com.logistics;

import com.logistics.Components.ShipmentManager;
import com.logistics.Components.Stock;
import com.logistics.Components.TransportManager;

public class Main {

    public static void main(String[] args) {
        Stock stock = new Stock();
        ShipmentManager shipments = new ShipmentManager();
        TransportManager transports = new TransportManager();

        CLI.mainMenu(shipments, transports, stock);
    }
}