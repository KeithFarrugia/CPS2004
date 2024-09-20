package com.logistics.Components.Transport;

public class SeaTransport implements Transport {
    private int code;
    private float speed;
    private float costPerMeter;
    private String route;
    private String shipName;

    public SeaTransport() {
        code = 0;
        speed = 0;
        costPerMeter = 0;
        route = "";
        shipName = "";
    }

    public SeaTransport(int code, int speed, int costPerMeter, String route, String shipName) {
        this.code = code;
        this.speed = speed;
        this.costPerMeter = costPerMeter;
        this.route = route;
        this.shipName = shipName;
    }

    // Copy Constructor
    public SeaTransport(SeaTransport other) {
        this.code = other.code;
        this.speed = other.speed;
        this.costPerMeter = other.costPerMeter;
        this.route = other.route;
        this.shipName = other.shipName;
    }

    // Clone method
    @Override
    public SeaTransport clone() {
        return new SeaTransport(this);
    }

    // Getters
    @Override public int getCode() {return code;}
    @Override public float getSpeed() {return speed;}
    @Override public float getCostPerMeter() {return costPerMeter;}
    @Override public String getRoute() {return route;}
    public String getShipName() { return shipName; }

    // Setters
    @Override public void setCode(int code) {this.code = code;}
    @Override public void setSpeed(float speed) {this.speed = speed;}
    @Override public void setCostPerMeter(float costPerMeter) {this.costPerMeter = costPerMeter;}
    @Override public void setRoute(String route) {this.route = route;}
    public void setShipName(String shipName) {this.shipName = shipName;}

    @Override public float estimateDeliveryTime(float distance) {
        return distance / speed;
    }

    @Override
    public float calcPrice(float distance) {
        return distance * costPerMeter;
    }


    @Override
    public String to_string() {
        return  "\nCode: " + code +
                "\nSpeed: " + speed +
                "\nCost per Meter: " + costPerMeter +
                "\nRoute: " + route +
                "\nShip Name: " + shipName;
    }
}
