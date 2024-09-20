package com.logistics.Components;

import com.logistics.Components.Product.Accessory;
import com.logistics.Components.Product.Appliance;
import com.logistics.Components.Product.Clothing;
import com.logistics.Components.Product.Decor;
import com.logistics.Components.Product.Digital;
import com.logistics.Components.Product.Drink;
import com.logistics.Components.Product.Food;
import com.logistics.Components.Product.Physical;
import com.logistics.Components.Product.Plants;
import com.logistics.Components.Product.Product;
import com.logistics.Components.Product.Seeds;
import com.logistics.Components.Product.Storage;
import com.logistics.Components.Product.Tech;

public class ProductFactory {

    public static Product createProduct(String type){
        // ============ Apparel ============
        if(type.equalsIgnoreCase("Accessory")){         // ------------- Accessory
            return new Accessory();
        }else if(type.equalsIgnoreCase("Clothing")){    // ------------- Clothing
            return new Clothing();
        }
        // ============ Consumable ============
        else if(type.equalsIgnoreCase("Food")){         // ------------- Food
            return new Food();
        }else if(type.equalsIgnoreCase("Drink")){       // ------------- Drink
            return new Drink();
        }
        // ============ Electronics ============
        else if(type.equalsIgnoreCase("Tech")){         // ------------- Tech
            return new Tech();
        }else if(type.equalsIgnoreCase("Appliance")){   // ------------- Appliance
            return new Appliance();
        }
        // ============ Furniture ============
        else if(type.equalsIgnoreCase("Decor")){         // ------------- Decor
            return new Decor();
        }else if(type.equalsIgnoreCase("Storage")){       // ------------- Storage
            return new Storage();
        }
        // ============ Games ============
        else if(type.equalsIgnoreCase("Digital")){         // ------------- Digital
            return new Digital();
        }else if(type.equalsIgnoreCase("Physical")){       // ------------- Physical
            return new Physical();
        }
        // ============ Flora ============
        else if(type.equalsIgnoreCase("Plants")){         // ------------- Plants
            return new Plants();
        }else if(type.equalsIgnoreCase("Seeds")){       // ------------- Seeds
            return new Seeds();
        }else{
            throw new IllegalArgumentException("Invalid Product type: " + type);
        }
    } 
}
