package com.logistics.Components.Transport;


public interface Transport{
    int getCode();
    float getSpeed();
    float getCostPerMeter();
    String getRoute();

    void setCode(int code);
    void setSpeed(float speed);
    void setCostPerMeter(float costPerMeter);
    void setRoute(String route);

    float estimateDeliveryTime(float distance);
    float calcPrice(float distance);


    Transport clone();

    String to_string();
}
