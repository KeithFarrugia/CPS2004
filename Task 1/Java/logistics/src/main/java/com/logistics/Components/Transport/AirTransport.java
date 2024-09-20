package com.logistics.Components.Transport;

public class AirTransport extends Transport {
    private String model;

    // Constructors
    public AirTransport() {
        super();
        model = "";
    }

    public AirTransport(int code, int speed, float costPerMeter, String route, String model) {
        super(code, speed, costPerMeter, route);
        this.model = model;
    }

    // Copy Constructor
    public AirTransport(AirTransport other) {
        super(other);
        this.model = other.model;
    }

    // Clone method
    @Override
    public AirTransport clone() {
        return new AirTransport(this);
    }

    // Getters
    public String getModel() { return model; }

    // Setters
    public void setModel(String model) { this.model = model; }

    @Override
    public String to_string() {
        return super.to_string() +
                "\nModel: " + model;
    }
}
