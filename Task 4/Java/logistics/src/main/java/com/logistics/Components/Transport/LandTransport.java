package com.logistics.Components.Transport;

import com.logistics.Serialization.PBLogistics.PBLandTransport;
import com.logistics.Serialization.PBLogistics.PBTransport;
import com.logistics.Serialization.PBLogistics.PBTransportItem;

public class LandTransport implements Transport {
    private int code;
    private float speed;
    private float costPerMeter;
    private String route;
    private String type;

    // Constructors
    public LandTransport() {
        code = 0;
        speed = 0;
        costPerMeter = 0;
        route = "";
        type = "";
    }

    public LandTransport(int code, int speed, int costPerMeter, String route, String type) {
        this.code = code;
        this.speed = speed;
        this.costPerMeter = costPerMeter;
        this.route = route;
        this.type = type;
    }

    // Copy Constructor
    public LandTransport(LandTransport other) {
        this.code = other.code;
        this.speed = other.speed;
        this.costPerMeter = other.costPerMeter;
        this.route = other.route;
        this.type = other.type;
    }

    // Clone method
    @Override
    public LandTransport clone() {
        return new LandTransport(this);
    }

    // Getters
    @Override public int getCode() {return code;}
    @Override public float getSpeed() {return speed;}
    @Override public float getCostPerMeter() {return costPerMeter;}
    @Override public String getRoute() {return route;}
    public String getType() {return type;}

    // Setters
    @Override public void setCode(int code) {this.code = code;}
    @Override public void setSpeed(float speed) {this.speed = speed;}
    @Override public void setCostPerMeter(float costPerMeter) {this.costPerMeter = costPerMeter;}
    @Override public void setRoute(String route) {this.route = route;}
    public void setType(String type) {this.type = type;}

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
                "\nType: " + type;
    }

    // ========================================== PROTOBUFFERS
    @Override public void copyToProto(PBTransportItem.Builder message){
        PBLandTransport.Builder pbLandTransport = PBLandTransport.newBuilder();
        pbLandTransport.setType(type);


        PBTransport.Builder pbTransport = pbLandTransport.getTransportBuilder();
        pbTransport.setCode(code);
        pbTransport.setSpeed(speed);
        pbTransport.setCostPerMeter(costPerMeter);
        pbTransport.setRoute(route);

        message.setLandTransport(pbLandTransport);

    };
    @Override public void copyFromProto(PBTransportItem message){
        PBLandTransport pbLandTransport = message.getLandTransport();
        code = pbLandTransport.getTransport().getCode();
        speed = pbLandTransport.getTransport().getSpeed();
        costPerMeter = pbLandTransport.getTransport().getCostPerMeter();
        route = pbLandTransport.getTransport().getRoute();
        type = pbLandTransport.getType();
    };
}
