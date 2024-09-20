package com.logistics;

import com.logistics.Components.ProductFactory;
import com.logistics.Components.ShipmentManager;
import com.logistics.Components.Stock;
import com.logistics.Components.TransportFactory;
import com.logistics.Components.TransportManager;
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
import com.logistics.Components.Shipment.ExpressDeliveryDecorator;
import com.logistics.Components.Shipment.GlobalDiscountDecorator;
import com.logistics.Components.Shipment.Shipment;
import com.logistics.Components.Transport.AirTransport;
import com.logistics.Components.Transport.LandTransport;
import com.logistics.Components.Transport.SeaTransport;
import com.logistics.Components.Transport.Transport;
import com.logistics.Serialization.Serialize;


public class CLI {
    
    private static int menu(String menu, int rangeOptions) {
        System.out.println(menu);

        while (true) {
            try {
                System.out.print("\n\nInput Option: ");
                int option = InputHandler.readInt();

                if (option >= 1 && option <= rangeOptions) {
                    return option;
                } else {
                    System.out.println("ERROR: Input out of range");
                }
            } catch (IllegalArgumentException e) {
                System.err.println(e.getMessage());
            }
        }
    }


    // ============================================================================ ITEM CREATION MENUS ============================================================================
    // ---------------------------------- CREATING A PRODUCT
    private static int createProduct(Product p) {
    
        try {
            System.out.print("\nInput Product Name: ");
            String name = InputHandler.readString();
            p.setName(name);
    
            System.out.print("Input Product Supplier: ");
            String supplier = InputHandler.readString();
            p.setSupplier(supplier);
    
            System.out.print("Input Cost: ");
            float cost = InputHandler.readFloat();
            p.setCost(cost);
    
            System.out.print("Input Discount Amount: ");
            float discountAmount = InputHandler.readFloat();
            p.setDiscountAmount(discountAmount);
    
            System.out.print("Input Packaging Units: ");
            int packagingUnits = InputHandler.readInt();
    
            System.out.print("Input Packaging Cost (per unit): ");
            float packagingCostPerUnit = InputHandler.readFloat();
    
            p.setPackagingData(packagingUnits, packagingCostPerUnit);
            
            return 0;
    
        } catch (Exception e) {
            System.err.println(e.getMessage());
            return -1;
        }
    }

    // ---------------------------------- PRODUCT SUB CLASS MENU
    private static Product productMenu() {
        int temp_i;
        String temp_s;
        boolean temp_b;

        int option = menu("\n======Product List====== " +
                            "\n\nApparel    \n 1.  Accessories    \n 2.  Clothing" +
                            "\n\nConsumable \n 3.  Food           \n 4.  Drink" +
                            "\n\nElectronics\n 5.  Tech           \n 6.  Appliance" +
                            "\n\nFurniture  \n 7.  Decor          \n 8.  Storage" +
                            "\n\nGames      \n 9.  Digital        \n 10. Physical" +
                            "\n\nFlora      \n 11. Plants         \n 12. Seeds" +
                            "\n\n13. Quit"
                            , 13);

        try {
            switch (option) {

                // ============ Apparel ============
                case 1: { // ------------- Accessory
                    Accessory p = (Accessory) ProductFactory.createProduct("Accessory");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Material: ");
                    temp_s = InputHandler.readString();
                    p.setMaterial(temp_s);
                    System.out.print("Input Accessory Brand: ");
                    temp_s = InputHandler.readString();
                    p.setBrand(temp_s);

                    
                    return p;
                }
                case 2: { // ------------- Clothing
                    Clothing p = (Clothing) ProductFactory.createProduct("Clothing");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Material: ");
                    temp_s = InputHandler.readString();
                    p.setMaterial(temp_s);
                    System.out.print("Input Accessory Style: ");
                    temp_s = InputHandler.readString();
                    p.setStyle(temp_s);

                    
                    return p;
                }

                // ============ Consumable ============
                case 3: { // ------------- Food
                    Food p = (Food) ProductFactory.createProduct("Food");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Calories: ");
                    temp_i = InputHandler.readInt();
                    p.setCalories(temp_i);
                    System.out.print("Is it Canned Y/n: ");
                    temp_b = InputHandler.readBool();
                    p.setIsCanned(temp_b);

                    
                    return p;
                }
                case 4: { // ------------- Drink
                    Drink p = (Drink) ProductFactory.createProduct("Drink");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Calories: ");
                    temp_i = InputHandler.readInt();
                    p.setCalories(temp_i);
                    System.out.print("Is it Carbonated Y/n: ");
                    temp_b = InputHandler.readBool();
                    p.setIsCarbonated(temp_b);

                    
                    return p;
                }

                // ============ Electronics ============
                case 5: { // ------------- Tech
                    Tech p = (Tech) ProductFactory.createProduct("Tech");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Manufacturer: ");
                    temp_s = InputHandler.readString();
                    p.setManufacturer(temp_s);
                    System.out.print("Input Type: ");
                    temp_s = InputHandler.readString();
                    p.setType(temp_s);

                    
                    return p;
                }
                case 6: { // ------------- Appliance
                    Appliance p = (Appliance) ProductFactory.createProduct("Appliance");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Manufacturer: ");
                    temp_s = InputHandler.readString();
                    p.setManufacturer(temp_s);
                    System.out.print("Input Size: ");
                    temp_s = InputHandler.readString();
                    p.setSize(temp_s);

                    
                    return p;
                }

                // ============ Furniture ============
                case 7: { // ------------- Decor
                    Decor p = (Decor) ProductFactory.createProduct("Decor");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Material: ");
                    temp_s = InputHandler.readString();
                    p.setMaterial(temp_s);
                    System.out.print("Input Style: ");
                    temp_s = InputHandler.readString();
                    p.setStyle(temp_s);

                    
                    return p;
                }
                case 8: { // ------------- Storage
                    Storage p = (Storage) ProductFactory.createProduct("Storage");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Material: ");
                    temp_s = InputHandler.readString();
                    p.setMaterial(temp_s);
                    System.out.print("Input Capacity: ");
                    temp_i = InputHandler.readInt();
                    p.setCapacity(temp_i);

                    
                    return p;
                }

                // ============ Games ============
                case 9: { // ------------- Digital
                    Digital p = (Digital) ProductFactory.createProduct("Digital");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Genre: ");
                    temp_s = InputHandler.readString();
                    p.setGenre(temp_s);
                    System.out.print("Input Developer: ");
                    temp_s = InputHandler.readString();
                    p.setDeveloper(temp_s);

                    
                    return p;
                }
                case 10: { // ------------- Physical
                    Physical p = (Physical) ProductFactory.createProduct("Physical");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Input Genre: ");
                    temp_s = InputHandler.readString();
                    p.setGenre(temp_s);
                    System.out.print("Input Number of Players: ");
                    temp_i = InputHandler.readInt();
                    p.setNumberOfPlayers(temp_i);

                    
                    return p;
                }

                // ============ Flora ============
                case 11: { // ------------- Plants
                    Plants p = (Plants) ProductFactory.createProduct("Plants");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Is it Cultivated Y/n: ");
                    temp_b = InputHandler.readBool();
                    p.setIsCultivated(temp_b);
                    System.out.print("Does it Bear Fruit Y/n: ");
                    temp_b = InputHandler.readBool();
                    p.setBearsFruit(temp_b);

                    
                    return p;
                }
                case 12: { // ------------- Seeds
                    Seeds p = (Seeds) ProductFactory.createProduct("Seeds");
                    if (createProduct(p) == -1) return null;

                    System.out.print("Is it Cultivated Y/n: ");
                    temp_b = InputHandler.readBool();
                    p.setIsCultivated(temp_b);
                    System.out.print("Input Number of Days before Expiration: ");
                    temp_i = InputHandler.readInt();
                    p.setExpirationDays(temp_i);

                    
                    return p;
                }
                case 13:
                    return null;
                // ============ Default ============
                default:
                    return null;
            }

        } catch (Exception e) {
            System.err.println(e.getMessage());
            return null;
        }
    }


    // ------------------------------- TRANSPORT SUBCLASS MENU
    private static Transport transportMenu() {
        try {
            int option = menu("\n======Transport List====== " +
                                "\n1. Air Transport    \n2. Land Transport    \n3. Sea Transport" +
                                "\n4. Quit", 4);

            switch (option) {
                case 1: {
                    AirTransport t = (AirTransport) TransportFactory.createTransport("AirTransport");

                    System.out.print("\nInput Code: ");
                    t.setCode(InputHandler.readInt());
                    System.out.print("Input Speed: ");
                    t.setSpeed(InputHandler.readFloat());
                    System.out.print("Input Cost Per Meter: ");
                    t.setCostPerMeter(InputHandler.readFloat());
                    System.out.print("Input Route: ");
                    t.setRoute(InputHandler.readString());

                    System.out.print("Input Model: ");
                    t.setModel(InputHandler.readString());

                    
                    return t;
                }
                case 2: {
                    LandTransport t = (LandTransport) TransportFactory.createTransport("LandTransport");

                    System.out.print("\nInput Code: ");
                    t.setCode(InputHandler.readInt());
                    System.out.print("Input Speed: ");
                    t.setSpeed(InputHandler.readFloat());
                    System.out.print("Input Cost Per Meter: ");
                    t.setCostPerMeter(InputHandler.readFloat());
                    System.out.print("Input Route: ");
                    t.setRoute(InputHandler.readString());

                    System.out.print("Input Type: ");
                    t.setType(InputHandler.readString());

                    
                    return t;
                }
                case 3: {
                    SeaTransport t = (SeaTransport) TransportFactory.createTransport("SeaTransport");

                    System.out.print("\nInput Code: ");
                    t.setCode(InputHandler.readInt());
                    System.out.print("Input Speed: ");
                    t.setSpeed(InputHandler.readFloat());
                    System.out.print("Input Cost Per Meter: ");
                    t.setCostPerMeter(InputHandler.readFloat());
                    System.out.print("Input Route: ");
                    t.setRoute(InputHandler.readString());

                    System.out.print("Input Ship Name: ");
                    t.setShipName(InputHandler.readString());

                    
                    return t;
                }
                case 4: // ------------------ QUIT
                    
                    return null;

                default:
                    break;
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            return null;
        }
        return null;
    }

    // ================================================================= Functions Relating to Product =================================================================

    private static void stockUtilityMenu(Stock stock) {
        while (true) {
            String productName;
            int temp_i;
            int option = menu("\n======Stock Options====== " +
                    "\n1. Add Product \n2. Delete Product \n3. Update Product \n4. Increase Stock \n5. Print Product \n6. Print Stock \n7. Delete Stock \n8. Quit", 8);

            try{
                switch (option) {
                    case 1: // ------------------ ADD  PRODUCT
                        Stock.stockItem_t newItem = new Stock.stockItem_t();
                        newItem.p = productMenu();
                        if(newItem.p != null){
                            System.out.print("Enter quantity: ");
                            newItem.q = InputHandler.readInt();
                        }
                        stock.addStock(newItem);
                        break;

                    case 2: // ------------------ DELETE  PRODUCT
                        System.out.print("Enter the name of the product to delete: ");
                        productName = InputHandler.readString();
                        stock.removeStock(productName);
                        break;

                    case 3: // ------------------ UPDATE  PRODUCT
                        System.out.print("Enter the name of the product to update: ");
                        productName = InputHandler.readString();
                        Stock.stockItem_t updatedItem = new Stock.stockItem_t();
                        updatedItem.p = productMenu();
                        System.out.print("Enter quantity: ");
                        updatedItem.q = InputHandler.readInt();
                        stock.updateStock(productName, updatedItem);
                        break;

                    case 4: // ------------------ INCREASE STOCK
                        System.out.print("Enter the name of the product to increase the stock of: ");
                        productName = InputHandler.readString();
                        System.out.print("Enter amount to increase by: ");
                        temp_i = InputHandler.readInt();
                        stock.increaseStock(productName, temp_i);
                        break;

                    case 5: // ------------------ PRINT STOCK
                        System.out.print("Enter the name of the product to print: ");
                        productName = InputHandler.readString();
                        stock.displayStock(productName);
                        break;

                    case 6: // ------------------ PRINT ALL STOCK
                        stock.displayStock();
                        break;

                    case 7: // ------------------ DELETE STOCK
                        stock.clearStock();
                        break;

                    case 8: // ------------------ QUIT
                        
                        return;

                    default:
                        break;
                }
            } catch (Exception e) {
                System.err.println("Error: " + e.getMessage());
            }
        }
    }

    // ================================================================= Functions Relating to Shipments =================================================================
    
    // ------------------------------ Adding Products to Shipment
    private static void shipmentAddProduct(Shipment shipment, Stock stock) {
        int option;
        String temp_s;
        int temp_i;

        do {
            option = menu("\n======Product Options====== " +
                            "\n1. Add Product \n2. Quit", 2);

            try{
                switch (option) {
                    case 1:
                        System.out.print("Input Product Name: ");
                        temp_s = InputHandler.readString();
                        System.out.print("Input Quantity: ");
                        temp_i = InputHandler.readInt();
                        shipment.addProduct(stock, temp_s, temp_i);
                        break;

                    case 2: // ------------------ QUIT
                        
                        return;

                    default:
                        break;
                }
            } catch (Exception e) {
                System.err.println("Error: " + e.getMessage());
            }

        } while (option != 2);
    }


    // -------------------------- Editing Menu
    private static void shipmentEdit(Shipment shipment, TransportManager transportManager, Stock stock) {
        
        int option;
        int temp_i;
        String temp_s;

        option = menu("\n====== Update Options====== " +
                       "\n1. Add Product \n2. Remove Product \n3. Change Transport \n4. Quit", 4);
        try{
            switch (option) {
                case 1: // ---------- Add more Products
                    shipmentAddProduct(shipment, stock);
                    shipment.updateCost();
                    break;

                case 2: // ---------- Delete Product
                    System.out.print("Input Product Name: ");
                    temp_s = InputHandler.readString();
                    shipment.deleteProduct(stock, temp_s);
                    shipment.updateCost();
                    break;

                case 3: // ---------- Change Transport
                    Transport tempTransport = shipment.getTransport().clone();
                    System.out.print("Input Transport Code: ");
                    temp_i = InputHandler.readInt();
                    if (!shipment.configureTransport(transportManager, temp_i)) {
                        shipment.setTransport(tempTransport);
                        break; // Roll Back if error
                    }
                    shipment.updateCost();
                    break;

                case 4: // ------------------ QUIT
                    
                    return;

                default:
                    break;
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    private static void shipmentUtilityMenu(ShipmentManager shipmentManager, TransportManager transportManager, Stock stock) {
        int temp_i;
        float temp_f;
        String temp_s;

        while (true) {
            int option = menu("\n======Shipment Options====== " +
            "\n1. Add Shipment \n2. Delete Shipment \n3. Edit Shipment \n4. Dispatch Shipment \n5. Print Shipment \n6. Print All Shipments \n7. Clear Shipments \n8. Apply Coupon \n9. Express Delivery \n10. Quit", 10);

            try{
                switch (option) {
                    case 1: // ----------------- ADD SHIPMENT
                        Shipment newShipment = new Shipment();

                        System.out.print("Input Customer Name: ");
                        temp_s = InputHandler.readString();
                        newShipment.setCustomer(temp_s);

                        System.out.print("Input Transport Code: ");
                        temp_i = InputHandler.readInt();
                        if (!newShipment.configureTransport(transportManager, temp_i)) {
                            break; // unable to find transport to attach
                        }

                        System.out.print("Input Distance: ");
                        temp_f = InputHandler.readFloat();
                        newShipment.setDistance(temp_f);

                        shipmentAddProduct(newShipment, stock);

                        shipmentManager.addShipment(newShipment);
                        break;

                    case 2: // ----------------- DELETE SHIPMENT
                        System.out.print("Input Shipment ID: ");
                        temp_i = InputHandler.readInt();
                        shipmentManager.deleteShipment(temp_i);
                        break;

                    case 3: // ----------------- EDIT SHIPMENT
                        System.out.print("Input Shipment ID: ");
                        temp_i = InputHandler.readInt();
                        Shipment toEdit = shipmentManager.getShipment(temp_i);
                        if (toEdit == null) {
                            System.out.println("ERROR: Shipment Not found\n");
                            break;
                        }
                        shipmentEdit(toEdit, transportManager, stock);
                        break;
                    case 4: // ----------------- DISPATCH SHIPMENT
                        System.out.print("Input Shipment ID: ");
                        temp_i = InputHandler.readInt();
                        shipmentManager.dispatchShipment(temp_i);
                        break;
                    case 5: // ----------------- PRINT SHIPMENT
                        System.out.print("Input Shipment ID: ");
                        temp_i = InputHandler.readInt();
                        shipmentManager.viewShipment(temp_i);
                        break;

                    case 6: // ----------------- PRINT ALL SHIPMENT
                        shipmentManager.viewShipment();
                        break;

                    case 7: // ----------------- CLEAR ALL SHIPMENT
                        shipmentManager.clearShipment();
                        break;

                    case 8:{ // ------------------ GLOBAL DISCOUNT
                        System.out.print("Input Shipment ID: ");
                        temp_i = InputHandler.readInt();
                        Shipment toDiscount = shipmentManager.getShipment(temp_i);
                        if (toDiscount == null) {
                            System.out.println("ERROR: Shipment Not found\n");
                            break;
                        }
                        GlobalDiscountDecorator decorator = new GlobalDiscountDecorator(toDiscount);
                        decorator.updateCost();
                        break;
                    }
                    case 9:{ // ------------------ EXPRESS SHIPPING
                        System.out.print("Input Shipment ID: ");
                        temp_i = InputHandler.readInt();
                        Shipment toDiscount = shipmentManager.getShipment(temp_i);
                        if (toDiscount == null) {
                            System.out.println("ERROR: Shipment Not found\n");
                            break;
                        }
                        ExpressDeliveryDecorator decorator = new ExpressDeliveryDecorator(toDiscount);
                        decorator.updateCost();
                        break;
                    }
                    case 10: // ------------------ QUIT
                        
                        return;    
                    default:
                        break;
                }
            } catch (Exception e) {
                System.err.println("Error: " + e.getMessage());
            }
        }
    }

    // ================================================================= Functions Relating to Transport =================================================================
    private static void transportUtilityMenu(TransportManager transportManager) {
        int temp_i;

        while (true) {
            int option = menu("\n======Transport Options====== " +
                    "\n1. Add Transport \n2. Delete Transport \n3. Update Transport \n4. Print Transport \n5. Print All Transport \n6. Clear Transport \n7. Quit", 7);

            try{
                switch (option) {

                    case 1: // --------------------------- ADD TRANSPORT
                        Transport newTransport = transportMenu();
                        transportManager.addTransport(newTransport);
                        break;

                    case 2: // --------------------------- DELETE TRANSPORT
                        System.out.print("Input Code: ");
                        temp_i = InputHandler.readInt();
                        transportManager.removeTransport(temp_i);
                        break;

                    case 3: // --------------------------- UPDATE TRANSPORT
                        System.out.print("Input Code: ");
                        temp_i = InputHandler.readInt();
                        Transport updatedTransport = transportMenu();
                        transportManager.updateTransport(temp_i, updatedTransport);
                        break;

                    case 4: // --------------------------- PRINT TRANSPORT
                        System.out.print("Input Code: ");
                        temp_i = InputHandler.readInt();
                        transportManager.displayTransports(temp_i);
                        break;

                    case 5: // --------------------------- PRINT ALL TRANSPORT
                        transportManager.displayTransports();
                        break;

                    case 6: // --------------------------- DELETE ALL TRANSPORT
                        transportManager.clearTransport();
                        break;

                    case 7: // ------------------ QUIT
                        
                        return;

                    default:
                        break;
                }
            } catch (Exception e) {
                System.err.println("Error: " + e.getMessage());
            }
        }
    }
    
    
    // ================================================================= MAIN MENU =================================================================

    public static void mainMenu(ShipmentManager shipmentManager, TransportManager transportManager, Stock stock) {

        while (true) {
            int option = menu("\n======Main Options====== " +
                    "\n1. Stock \n2. Transport \n3. Shipment \n4. Save \n5. Load \n6. Quit", 6);

            try{
                switch (option) {
                    case 1:
                        stockUtilityMenu(stock);
                        break;
                    case 2:
                        transportUtilityMenu(transportManager);
                        break;
                    case 3:
                        shipmentUtilityMenu(shipmentManager, transportManager, stock);
                        break;
                    case 4:
                        Serialize.save(shipmentManager, transportManager, stock);
                        break;
                    case 5:
                        Serialize.load(shipmentManager, transportManager, stock);
                        break;
                    case 6: // ------------------ QUIT
                        
                        return;
                    default:
                        break;
                }
            } catch (Exception e) {
                System.err.println("Error: " + e.getMessage());
            }
        }
    }

}