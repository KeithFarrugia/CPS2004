#include "CLI.h"

// ================================================================= MAIN MENU =================================================================

void CLI::MainMenu(ShipmentManager* shipmentManager, TransportManager* transportManager, Stock* stock){
    while(true){
        int option = Menu ((std::string)    "\n======Main Options====== " +
                                            "\n1. Stock \n2. Transport \n3. Shipment \n4. Quit", 4);
        try{
            switch (option){
            case 1:
                StockUtilityMenu(stock);
                break;
            case 2:
                TransportUtilityMenu(transportManager);
                break;
            case 3:
                ShipmentUtilityMenu(shipmentManager, transportManager, stock);
                break;
            case 4: // ------------------ QUIT
                return;
            default:
                break;
            }
        }catch(const std::exception& e){std::cerr << e.what() << '\n';}
                
    }
}


// ================================================================= Functions Relating to Transport =================================================================
void CLI::TransportUtilityMenu(TransportManager* transportManager){
    char temp_s[100];   int temp_i;
    while(true){
        
        int option = Menu ((std::string)    "\n======Transport Options====== " +
                                            "\n1. Add Transport \n2. Delete Transport \n3. Update Transport \n4. Print Transport \n5. Print All Transport \n6. Clear Transport \n7. Quit", 7);
        try{
            switch (option){
            
            case 1:{ // --------------------------- ADD TRANSPORT
                Transport* newTransport = TransportMenu();
                transportManager->addTransport(newTransport);
                break;
            }

            case 2:// --------------------------- DELETE TRANSPORT
                InputHandler::readInt("Input Code: ", &temp_i);
                transportManager->removeTransport(temp_i);
                break;
            

            case 3:{ // --------------------------- UPDATE TRANSPORT
            
                InputHandler::readInt("Input Code: ", &temp_i);
                Transport* newTransport = TransportMenu();
                transportManager->updateTransport(temp_i, newTransport);
                break;
            }

            case 4: // --------------------------- PRINT TRANSPORT
                InputHandler::readInt("Input Code: ", &temp_i);
                transportManager->displayTransports(temp_i);
                break;                

            case 5: // --------------------------- PRINT ALL TRANSPORT
                transportManager->displayTransports();
                break;

            case 6: // --------------------------- DELETE ALL TRANSPORT
                transportManager->clearTransport();
                break;
            case 7: // ------------------ QUIT
                return;
            default:
                break;
            }
        }catch(const std::exception& e){std::cerr << e.what() << '\n';}
    }
}





// ================================================================= Functions Relating to Shipments =================================================================
void CLI::ShipmentUtilityMenu(ShipmentManager* shipmentManager, TransportManager* transportManager, Stock* stock){
    int temp_i;
    float temp_f;
    char temp_s[100];
    while(true){
        int option = Menu((std::string)    "\n======Shipment Options====== " +
                                                    "\n1. Add Shipment \n2. Delete Shipment \n3. Edit Shipment \n4. Dispatch Shipment \n5. Print Shipment \n6. Print All Shipments \n7. Clear Shipments \n8. Quit", 8);
        try{
            switch (option){
            case 1:{ // ----------------- ADD SHIPMENT
                std::unique_ptr<Shipment> newShipment = std::make_unique<Shipment>();

                InputHandler::readString("Input Customer Name: ", temp_s);
                newShipment->setCustomer(temp_s);

                InputHandler::readInt("Input Transport Code: ", &temp_i);
                if(newShipment->ConfigureTransport(transportManager, temp_i) == false){break;} // unable to find transport to attach

                InputHandler::readFloat("Input Distance: ", &temp_f);
                newShipment->setDistance(temp_f);

                ShipmentAddProduct(newShipment.get(), stock);

                shipmentManager->addShipment(newShipment.release());
                break;
            }
            case 2: // ----------------- DELETE SHIPMENT
                InputHandler::readInt("Input Shipment ID: ", &temp_i);
                shipmentManager->deleteShipment(temp_i);
                break;

            case 3:{ // ----------------- EDIT SHIPMENT
                InputHandler::readInt("Input Shipment ID: ", &temp_i);
                Shipment* toEdit = shipmentManager->getShipment(temp_i);
                if(toEdit == nullptr){printf("ERROR: Shipment Not found\n");break;}
                ShipmentEdit(toEdit, transportManager, stock);
                break;
            }
            case 4: // ----------------- DISPATCH SHIPMENT
                InputHandler::readInt("Input Shipment ID: ", &temp_i);
                shipmentManager->dispatchShipment(temp_i);                
                break;

            case 5: // ----------------- PRINT SHIPMENT
                InputHandler::readInt("Input Shipment ID: ", &temp_i);
                shipmentManager->viewShipment(temp_i);
                break;

            case 6: // ----------------- PRINT ALL SHIPMENT
                shipmentManager->viewShipment();
                break;

            case 7: // ----------------- ClEAR ALL SHIPMENT
                shipmentManager->clearShipment();
                break;
            case 8: // ------------------ QUIT
                return;
            default:
                break;
            }
        }catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    }
}

// -------------------------- Editing Menu
void CLI::ShipmentEdit(Shipment* shipment, TransportManager* transportManager, Stock* stock){
    int option;
    int temp_i;
    char temp_s[100];
    option = Menu((std::string)    "\n====== Update Options====== " +
                                    "\n1. Add Product \n2. Remove Product \n3. Change Transport \n4. Quit", 4);
    try{
        switch (option){
        case 1: // ---------- Add more Products
            ShipmentAddProduct(shipment, stock);
            shipment->updateCost();
            break;
    
        case 2: // ---------- Delete Product
            InputHandler::readString("Input Product Name: ", temp_s);
            shipment->deleteProduct(stock, temp_s);
            shipment->updateCost();
            break;

        case 3:{ // ---------- Change Transport
            Transport tempTransporty = Transport(*shipment->getTransport());
            InputHandler::readInt("Input Transport Code: ", &temp_i);
            if(shipment->ConfigureTransport(transportManager, temp_i) == false){ shipment->setTransport(tempTransporty); break;} // Roll Back if error
            shipment->updateCost();
            break;
        }case 4: // ------------------ QUIT
            return;
        default:
            break;
        }
    }catch(const std::exception& e){std::cerr << e.what() << '\n';}

}

// ------------------------------ Adding Products to Shipment
void CLI::ShipmentAddProduct(Shipment* shipment, Stock* stock){
    int option;
    char temp_s[100];
    int temp_i;
    do{
        option = Menu((std::string)    "\n======Product Options====== " +
                                        "\n1. Add Product \n2. Quit", 2);
        try{
            switch (option){
            case 1:{
                InputHandler::readString("Input Product Name: ", temp_s);
                InputHandler::readInt("Input Quantity: ", &temp_i);
                shipment->addProduct(stock, temp_s, temp_i);
                break;
            }case 2: // ------------------ QUIT
                return;
            default:
                break;
            }
        }catch(const std::exception& e){std::cerr << e.what() << '\n';}
        
    }while(option != 2);
}

// ================================================================= Functions Relating to Product =================================================================
void CLI::StockUtilityMenu(Stock* stock){
    while(true){
        std::string productName;
        char temp_s[100];
        int temp_i;
        int option = Menu ((std::string)    "\n======Stock Options====== " +
                                                "\n1. Add Product \n2. Delete Product \n3. Update Product \n4. Increase Stock \n5. Print Product \n6. Print Stock \n7. Delete Stock \n8. Quit", 8);
        try{
            switch (option){
            case 1: {// ------------------ ADD  PRODUCT
                std::unique_ptr<Stock::stockItem_t> NewStock = std::make_unique<Stock::stockItem_t>();
                NewStock->p = ProductMenu();
                if(NewStock->p != nullptr){
                    InputHandler::readInt("Enter quantity: ", &temp_i);
                    NewStock->q = temp_i;
                }
                stock->addStock(NewStock.release());
                break;
            }
            case 2: // ------------------ DELETE  PRODUCT
                InputHandler::readString("Enter the name of the product to delete: ", temp_s);
                stock->removeStock(temp_s);
                break;

            case 3:{ // ------------------ UPDATE  PRODUCT
                InputHandler::readString("Enter the name of the product to update: ", temp_s);
                std::unique_ptr<Stock::stockItem_t> NewStock = std::make_unique<Stock::stockItem_t>();
                NewStock->p = ProductMenu();
                InputHandler::readInt("Enter quantity: ", &temp_i);
                NewStock->q = temp_i;
                stock->updateStock(temp_s, NewStock.release());
                break;
            }
            case 4: // ------------------ INCREASE STOCK
                InputHandler::readString("Enter the name of the product to increase the stock of: ", temp_s);
                InputHandler::readInt("Enter amount to increase by: ", &temp_i);
                stock->increaseStock(temp_s, temp_i);
                break;

            case 5: // ------------------ PRINT STOCK
                InputHandler::readString("Enter the name of the product to print: ", temp_s);
                stock->displayStock(temp_s);
                break;

            case 6: // ------------------ PRINT ALL STOCK
                stock->displayStock();
                break;
            case 7: // ------------------ DELETE STOCK
                stock->clearStock();
                break;
            case 8: // ------------------ QUIT
                return;
            default:
                break;
            }
        }catch(const std::exception& e){std::cerr << e.what() << '\n';}
    }
}
// ================================================================= Hidden Utility Methods =================================================================


int CLI::Menu(std::string menu, int rangeOptions){
    printf("%s", menu.c_str());
    
    while (true) {
        try {
            int option;
            printf("\n\nInput Option: ");
            if (scanf("%d", &option) == 1) {
                // Successful input
                if (option >= 1 && option <= rangeOptions) {
                    return option;
                } else {
                    printf("ERROR: Input out of range\n");
                }
            } else {
                // Failed to read an integer
                printf("ERROR: Invalid input. Please enter a number.\n");
                scanf("%*s");  // Clear the invalid input from the buffer
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}

// ============================================================================ ITEM CREATION MENUS ============================================================================

// ------------------------------- TRANSPORT SUBCLASS MENU
Transport* CLI::TransportMenu(){
    int temp_i;
    float temp_f;
    char temp_s[100];
    int option = Menu((std::string)    "\n======Transport List====== " +
                                            "\n1. Air Transport    \n2. Land Transport    \n3. Sea Transport" +
                                            "\n4. Quit"
                            , 4);
    // Encapsulate in try catch in order to prevent errors caused by input
    try{
        switch (option){
        case 1:{
            std::unique_ptr<AirTransport> t = std::make_unique<AirTransport>();

            InputHandler::readInt("\nInput Code: ", &temp_i);
            t->setCode(temp_i);
            InputHandler::readFloat("Input Speed: ", &temp_f);
            t->setSpeed(temp_f);
            InputHandler::readFloat("Input Cost Per Meter: ", &temp_f);
            t->setCostPerMeter(temp_f);
            InputHandler::readString("Input Route: ", temp_s);
            t->setRoute(temp_s);
            
            InputHandler::readString("Input Model: ", temp_s);
            t->setModel(temp_s);
            
            return t.release();
            break;
        }case 2:{
            std::unique_ptr<LandTransport> t = std::make_unique<LandTransport>();

            InputHandler::readInt("\nInput Code: ", &temp_i);
            t->setCode(temp_i);
            InputHandler::readFloat("Input Speed: ", &temp_f);
            t->setSpeed(temp_f);
            InputHandler::readFloat("Input Cost Per Meter: ", &temp_f);
            t->setCostPerMeter(temp_f);
            InputHandler::readString("Input Route: ", temp_s);
            t->setRoute(temp_s);
            
            InputHandler::readString("Input Type: ", temp_s);
            t->setType(temp_s);

            return t.release();
            break;
        }case 3:{
            std::unique_ptr<SeaTransport> t = std::make_unique<SeaTransport>();

            InputHandler::readInt("\nInput Code: ", &temp_i);
            t->setCode(temp_i);
            InputHandler::readFloat("Input Speed: ", &temp_f);
            t->setSpeed(temp_f);
            InputHandler::readFloat("Input Cost Per Meter: ", &temp_f);
            t->setCostPerMeter(temp_f);
            InputHandler::readString("Input Route: ", temp_s);
            t->setRoute(temp_s);
            
            InputHandler::readString("Input Ship Name: ", temp_s);
            t->setShipName(temp_s);
            
            return t.release();
            break;
        }case 4: // ------------------ QUIT
            return nullptr;
        
        default:
            break;
        }
    }catch(const std::exception& e){std::cerr << e.what() << '\n'; return nullptr;}
    return nullptr;
}

// ---------------------------------- CREATING A PRODUCT

int CLI::createProduct(Product* p){
    int temp_i;
    float temp_f;
    char temp_s[100];

    // Encapsulate in try catch in order to prevent errors caused by input
    try{
        InputHandler::readString("\nInput Product Name: ", temp_s);
        p->setName(std::string(temp_s));
        InputHandler::readString("Input Product Supplier: ", temp_s);
        p->setSupplier(std::string(temp_s));
        InputHandler::readFloat("Input Cost: ", &temp_f);
        p->setCost(temp_f);
        InputHandler::readFloat("Input Discount Ammount: ", &temp_f);
        p->setDiscountAmount(temp_f);

        InputHandler::readInt("Input Packaging Units: ", &temp_i);
        InputHandler::readFloat("Input Packaging Cost (per unit): ", &temp_f);
        p->setPackagingData(temp_i, temp_f);
        return 0;
       
    }catch(const std::exception& e){std::cerr << e.what() << '\n'; return -1;}
    
    
}  


// ---------------------------------- PRODUCT SUB CLASS MENU

Product* CLI::ProductMenu(){
    int temp_i;
    float temp_f;
    char temp_s[100];
    bool temp_b;

    int option = Menu((std::string)    "\n======Product List====== " +
                                        "\n\nApparel    \n 1.  Accessories    \n 2.  Clothing" +
                                        "\n\nConsumable \n 3.  Food           \n 4.  Drink"    +
                                        "\n\nElectronics\n 5.  Tech           \n 6.  Appliance"+
                                        "\n\nFurniture  \n 7.  Decor          \n 8.  Storage"  + 
                                        "\n\nGames      \n 9.  Digital        \n 10. Physical" +
                                        "\n\nFlora      \n 11. Plants         \n 12. Seeds" +
                                        "\n\n13. Quit"
                                        , 13);
    try{
        switch (option){

        // ============ Apparel ============ 
        case 1:{ // ------------- Accessory
            std::unique_ptr<Accessory> p = std::make_unique<Accessory>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readString("Input Material: ", temp_s);
            p->setMaterial(std::string(temp_s));
            InputHandler::readString("Input Accessory Brand: ", temp_s);
            p->setBrand(std::string(temp_s));

            return p.release();
            break;
        }case 2:{ // ------------- Clothing
            std::unique_ptr<Clothing> p = std::make_unique<Clothing>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readString("Input Material: ", temp_s);
            p->setMaterial(std::string(temp_s));
            InputHandler::readString("Input Accessory Style: ", temp_s);
            p->setStyle(std::string(temp_s));

            return p.release();
            break;
        }

        // ============ Consumable ============ 
        case 3:{ // ------------- Food
            std::unique_ptr<Food> p = std::make_unique<Food>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readInt("Input Calories: ", &temp_i);
            p->setCalories(temp_i);
            InputHandler::readBool("Is it Canned Y/n: ", &temp_b);
            p->setIsCanned(temp_b);

            return p.release();
            break;
        }case 4:{ // ------------- Drink
            std::unique_ptr<Drink> p = std::make_unique<Drink>(); 
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readInt("Input Calories: ", &temp_i);
            p->setCalories(temp_i);
            InputHandler::readBool("Is it Carbonated Y/n: ", &temp_b);
            p->setIsCarbonated(temp_b);

            return p.release();
            break;

        // ============ Electronics ============ 
        }case 5:{ // ------------- Tech
            std::unique_ptr<Tech> p = std::make_unique<Tech>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};
            
            InputHandler::readString("Input Manufacturer: ", temp_s);
            p->setManufacturer(std::string(temp_s));
            InputHandler::readString("Input Type: ", temp_s);
            p->setType(std::string(temp_s));

            return p.release();
            break;
        }case 6:{ // ------------- Appliance
            std::unique_ptr<Appliance> p = std::make_unique<Appliance>(); 
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readString("Input Manufacturer: ", temp_s);
            p->setManufacturer(std::string(temp_s));
            InputHandler::readString("Input Size: ", temp_s);
            p->setSize(std::string(temp_s));

            return p.release();
            break;
        
        // ============ Furniture ============ 
        }case 7:{ // ------------- Decor
            std::unique_ptr<Decor> p = std::make_unique<Decor>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readString("Input Material: ", temp_s);
            p->setMaterial(std::string(temp_s));
             InputHandler::readString("Input Style: ", temp_s);
            p->setStyle(std::string(temp_s));

            return p.release();
            break;
        }case 8:{ // ------------- Storage
            std::unique_ptr<Storage> p = std::make_unique<Storage>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readString("Input Material: ", temp_s);
            p->setMaterial(std::string(temp_s));
            InputHandler::readInt("Input Capacity: ", &temp_i);
            p->setCapacity(temp_i);

            return p.release();
            break;

        // ============ Games ============ 
        }case 9:{ // ------------- Digital
            std::unique_ptr<Digital> p = std::make_unique<Digital>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readString("Input Genre: ", temp_s);
            p->setGenre(std::string(temp_s));
            InputHandler::readString("Input Developer: ", temp_s);
            p->setDeveloper(std::string(temp_s));

            return p.release();
            break;
        }case 10:{ // ------------- Physical
            std::unique_ptr<Physical> p = std::make_unique<Physical>(); 
            if(CLI::createProduct(p.get()) == -1){return nullptr;};
            
            InputHandler::readString("Input Genre: ", temp_s);
            p->setGenre(std::string(temp_s));
            InputHandler::readInt("Input Number of Players: ", &temp_i);
            p->setNumber_of_Players(temp_i);

            return p.release();
            break;
        
        // ============ Flora ============ 
        }case 11:{ // ------------- Plants
            std::unique_ptr<Plants> p = std::make_unique<Plants>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readBool("Is it Cultiated Y/n: ", &temp_b);
            p->setIsCultivated(temp_b);
            InputHandler::readBool("Does it Bear Fruit Y/n: ", &temp_b);
            p->setBearsFruit(temp_b);

            return p.release();
            break;
        }case 12:{ // ------------- Seeds
            std::unique_ptr<Seeds> p = std::make_unique<Seeds>();
            if(CLI::createProduct(p.get()) == -1){return nullptr;};

            InputHandler::readBool("Is it Cultiated Y/n: ", &temp_b);
            p->setIsCultivated(temp_b);
            InputHandler::readInt("Input Number of Days before Expiration: ", &temp_i);
            p->setExpirationDays(temp_i);

            return p.release();
            break;
        }
        // ============ Default ============ 
        default:
            return nullptr;
            break;
        }
        
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n'; return nullptr;
    }
    return nullptr;
}

