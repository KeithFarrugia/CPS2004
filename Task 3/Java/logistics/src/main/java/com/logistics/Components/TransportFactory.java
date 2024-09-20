package com.logistics.Components;

import com.logistics.Components.Transport.AirTransport;
import com.logistics.Components.Transport.LandTransport;
import com.logistics.Components.Transport.SeaTransport;
import com.logistics.Components.Transport.Transport;

public class TransportFactory {
    
    public static Transport createTransport(String type){

        // ============ Transport ============
        if(type.equalsIgnoreCase("AirTransport")){         // ------------- AirTransport
            return new AirTransport();
        }else if(type.equalsIgnoreCase("LandTransport")){    // ------------- LandTransport
            return new LandTransport();
        }else if(type.equalsIgnoreCase("SeaTransport")){         // ------------- SeaTransport
            return new SeaTransport();
        }else{
            throw new IllegalArgumentException("Invalid Transport type: " + type);
        }
    }
}
