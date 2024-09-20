package com.logistics.Components.Transport;

public class AirTransport implements Transport {
    private int code;
    private float speed;
    private float costPerMeter;
    private String route;
    private String model;

    public AirTransport() {
        code = 0;
        speed = 0;
        costPerMeter = 0;
        route = "";
        model = "";
    }

    public AirTransport(int code, float speed, float costPerMeter, String route, String model) {
        this.code = code;
        this.speed = speed;
        this.costPerMeter = costPerMeter;
        this.route = route;
        this.model = model;
    }

    // Copy Constructor
    public AirTransport(AirTransport other) {
        this.code = other.code;
        this.speed = other.speed;
        this.costPerMeter = other.costPerMeter;
        this.route = other.route;
        this.model = other.model;
    }

    // Clone method
    @Override
    public AirTransport clone() {
        return new AirTransport(this);
    }

    // Getters
    @Override public int getCode() {return code;}
    @Override public float getSpeed() {return speed;}
    @Override public float getCostPerMeter() {return costPerMeter;}
    @Override public String getRoute() {return route;}
    public String getModel() {return model;}

    // Setters
    @Override public void setCode(int code) {this.code = code;}
    @Override public void setSpeed(float speed) {this.speed = speed;}
    @Override public void setCostPerMeter(float costPerMeter) {this.costPerMeter = costPerMeter;}
    @Override public void setRoute(String route) {this.route = route;}
    public void setModel(String model) {this.model = model;}


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
                "\nModel: " + model;
    }
}
