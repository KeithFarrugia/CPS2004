#include "Stock.h"

Stock::Stock(){}

void Stock::addStock(Stock::stockItem_t* NewStock){
    if(NewStock->p == nullptr){return;};

    // Check For duplication of item
    if(getStock(NewStock->p->getName()) == nullptr){
        stockList.push_back(NewStock);
        return;
    }

    printf("ERROR: Item with Same name is already in stock\n");
}

void Stock::removeStock(const std::string stockName){
    // Search for item to remove
    for(int i = 0; i<stockList.size(); i++){
        if(stockList[i]->p->getName() == stockName){
            delete stockList[i]->p;
            delete stockList[i];
            stockList.erase(stockList.begin()+i);
            printf("\nDeleted Successfully\n");
            return;
        }
    }
    printf("\nERROR: Stock not found\n"); // not deleted
}

void Stock::updateStock(const std::string stockName, Stock::stockItem_t* NewStock){
    if(NewStock->p == nullptr){return;}
    Stock::stockItem_t* toUpdate = getStock(stockName); 
    if(toUpdate != nullptr){

         // Check that Transport either has the same code as the one being updated or a different code
        if ((NewStock->p->getName() == toUpdate->p->getName()) ||
            (NewStock->p->getName() != toUpdate->p->getName() && getStock(NewStock->p->getName()) == nullptr)) {
            removeStock(stockName);
            addStock(NewStock);
            printf("\nStock Updated\n");
            return;
        }
        printf("Stock was NOT Updated.\n");
    } else {
        printf("Stock not found.\n");
    }
}

void Stock::increaseStock(const std::string stockName, int newQuantity){
    
    // Search for item to increase stock
    Stock::stockItem_t* toIncrease = getStock(stockName); 
    if(toIncrease != nullptr){
        toIncrease->q += newQuantity;
        return;
    }
    printf("Stock not found.\n");
}

void Stock::clearStock(){
    // Memory Management
    for (Stock::stockItem_t* item : stockList) {
        delete item->p;
        delete item;
    }
    stockList.clear();
}

Stock::stockItem_t* Stock::getStock(const std::string stockName){
    for(stockItem_t* stock : stockList){
        if(stock->p->getName() == stockName){
            return stock;
        }
    }
    return nullptr;
}

void Stock::displayStock(){
    // Traverse and display
    std::cout << "Stock Items:\n";
    for (Stock::stockItem_t* item : stockList) {
        printf("\n%s", item->p->display_product_info().c_str());
        printf("\nQuantity: %s\n", std::to_string(item->q).c_str());
    }
}
void Stock::displayStock(const std::string stockName){
    // Traverse and display
    Stock::stockItem_t* item = getStock(stockName);
    if(item != nullptr){
        printf("\n%s", item->p->display_product_info().c_str());
        printf("\nQuantity: %s\n", std::to_string(item->q).c_str());
        return;
    }
    printf("\nERROR: Stock not found\n");
}



// ========================================== PROTOBUFFERS

void Stock::copyToProto(PBStock protobufStockList) {
    for (stockItem_t* stock : stockList) {
        PBStockItem* message = protobufStockList.add_stock();
        stock->p->copyToProto(message);
        message->set_quantity(stock->q);
    }
}

void Stock::copyFromProto(PBStock protobufStockList) {
    clearStock(); // Clear the existing stock

    // Iterate through protobuf stock items and create corresponding Java StockItems objects
    for (const auto& message : protobufStockList.stock()) {
        if (message.has_accessory()) {               // -------------------------------- ACCESSORY
            Accessory* accessory = new Accessory();
            accessory->copyFromProto(message);
            addStock(new stockItem_t{accessory, message.quantity()});
        } else if (message.has_clothing()) {         // -------------------------------- CLOTHING
            Clothing* clothing = new Clothing();
            clothing->copyFromProto(message);
            addStock(new stockItem_t{clothing, message.quantity()});
        } else if (message.has_food()) {             // -------------------------------- FOOD
            Food* food = new Food();
            food->copyFromProto(message);
            addStock(new stockItem_t{food, message.quantity()});
        } else if (message.has_drink()) {            // -------------------------------- DRINK
            Drink* drink = new Drink();
            drink->copyFromProto(message);
            addStock(new stockItem_t{drink, message.quantity()});
        } else if (message.has_tech()) {              // -------------------------------- TECH
            Tech* tech = new Tech();
            tech->copyFromProto(message);
            addStock(new stockItem_t{tech, message.quantity()});
        } else if (message.has_appliance()) {        // -------------------------------- APPLIANCE
            Appliance* appliance = new Appliance();
            appliance->copyFromProto(message);
            addStock(new stockItem_t{appliance, message.quantity()});
        } else if (message.has_decor()) {             // -------------------------------- DECOR
            Decor* decor = new Decor();
            decor->copyFromProto(message);
            addStock(new stockItem_t{decor, message.quantity()});
        } else if (message.has_storage()) {           // -------------------------------- STORAGE
            Storage* storage = new Storage();
            storage->copyFromProto(message);
            addStock(new stockItem_t{storage, message.quantity()});
        } else if (message.has_digital()) {           // -------------------------------- DIGITAL
            Digital* digital = new Digital();
            digital->copyFromProto(message);
            addStock(new stockItem_t{digital, message.quantity()});
        } else if (message.has_physical()) {         // --------------------------------  PHYSICAL
            Physical* physical = new Physical();
            physical->copyFromProto(message);
            addStock(new stockItem_t{physical, message.quantity()});
        } else if (message.has_plants()) {           // -------------------------------- PLANTS
            Plants* plants = new Plants();
            plants->copyFromProto(message);
            addStock(new stockItem_t{plants, message.quantity()});
        } else if (message.has_seeds()) {           // -------------------------------- SEEDS
            Seeds* seeds = new Seeds();
            seeds->copyFromProto(message);
            addStock(new stockItem_t{seeds, message.quantity()});
        } else {
            std::cout << "ERROR: Loaded Invalid Item" << std::endl;
        }
    }
}

