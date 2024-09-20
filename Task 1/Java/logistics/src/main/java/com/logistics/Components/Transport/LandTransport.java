package com.logistics.Components.Transport;

public class LandTransport extends Transport {
    private String type;

    // Constructors
    public LandTransport() {
        super();
        type = "";
    }

    public LandTransport(int code, int speed, int costPerMeter, String route, String type) {
        super(code, speed, costPerMeter, route);
        this.type = type;
    }

    // Copy Constructor
    public LandTransport(LandTransport other) {
        super(other); // Call the copy constructor of the superclass (Transport)
        this.type = other.type;
    }

    // Clone method
    @Override
    public LandTransport clone() {
        return new LandTransport(this);
    }

    // Getters
    public String getType() {return type;}

    // Setters
    public void setType(String type) {this.type = type;}

    @Override
    public String to_string() {
        return super.to_string() +
                "\nType: " + type;
    }
}
