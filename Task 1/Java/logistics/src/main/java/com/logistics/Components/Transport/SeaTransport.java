package com.logistics.Components.Transport;

public class SeaTransport extends Transport {
    private String shipName;

    public SeaTransport() {
        super();
        shipName = "";
    }

    public SeaTransport(int code, int speed, int costPerMeter, String route, String shipName) {
        super(code, speed, costPerMeter, route);
        this.shipName = shipName;
    }

    // Copy Constructor
    public SeaTransport(SeaTransport other) {
        super(other);
        this.shipName = other.shipName;
    }

    // Clone method
    @Override
    public SeaTransport clone() {
        return new SeaTransport(this);
    }

    // Getters
    public String getShipName() {
        return shipName;
    }

    // Setters
    public void setShipName(String shipName) {
        this.shipName = shipName;
    }

    @Override
    public String to_string() {
        return super.to_string() +
                "\nShip Name: " + shipName;
    }
}
