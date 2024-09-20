package com.logistics.Components.Transport;

public class Transport {
    protected int code;
    protected float speed;
    protected float costPerMeter;
    protected String route;

    public Transport() {
        code = 0;
        speed = 0;
        costPerMeter = 0;
        route = "";
    }

    public Transport(int code, float speed, float costPerMeter, String route) {
        this.code = code;
        this.speed = speed;
        this.costPerMeter = costPerMeter;
        this.route = route;
    }

    // Copy Constructor
    public Transport(Transport other) {
        this.code = other.code;
        this.speed = other.speed;
        this.costPerMeter = other.costPerMeter;
        this.route = other.route;
    }

    // Clone method
    public Transport clone() {
        return new Transport(this);
    }

    // Getters
    public int getCode() {return code;}
    public float getSpeed() {return speed;}
    public float getCostPerMeter() {return costPerMeter;}
    public String getRoute() {return route;}

    // Setters
    public void setCode(int code) {this.code = code;}
    public void setSpeed(float speed) {this.speed = speed;}
    public void setCostPerMeter(float costPerMeter) {this.costPerMeter = costPerMeter;}
    public void setRoute(String route) {this.route = route;}

    public float estimateDeliveryTime(float distance) {
        return distance / speed;
    }

    public float calcPrice(float distance) {
        return distance * costPerMeter;
    }

    public String to_string() {
        return "Code: " + code +
                "\nSpeed: " + speed +
                "\nCost per Meter: " + costPerMeter +
                "\nRoute: " + route;
    }
}