package com.logistics.Components.Transport;

import com.logistics.Serialization.PBLogistics.PBTransportItem;

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

    void copyToProto(PBTransportItem.Builder message);
    void copyFromProto(PBTransportItem message);
}
