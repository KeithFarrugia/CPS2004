#include "Shipment.h"

int Shipment::GlobalId = 0; // Used to Auto ID

Shipment::Shipment(){
    ID = GlobalId++;
    customer = "";
    transport = nullptr;
    distance = 0;
    dispatched = false;
}
Shipment::Shipment(int ID, std::string customer, Transport& transport, float distance){
    this->ID;
    this->customer = customer;
    this->transport = new Transport(transport);
    this->distance = distance;
    dispatched = false;
}

void Shipment::addProduct(Stock* stockList, std::string stockname, int quantity) {
    if(dispatched == false){// check if dispatched
        Stock::stockItem_t* stock = stockList->getStock(stockname); // Check if stock being bought is indeed in warehouse
        if (stock == nullptr){
            printf("ERROR: Stock not found\n"); // Stock does not exist
            return;
        }else{
            if(stock->q >= quantity){ // Check if quantity in stock is enough for the order
                // Create a copy of the stock to have as a record in the shipment
                std::unique_ptr<Stock::stockItem_t> NewStock = std::make_unique<Stock::stockItem_t>();
                NewStock->p =  stock->p->clone();
                NewStock->q = quantity;
                stock->q -= quantity;
                productlist.addStock(NewStock.release());
                printf("\n--Product Added--\n");
                return;
            }
            printf("ERROR: Cannnot take more then what currently is in stock\n");
        }
    }else{
        printf("ERROR: Cannnot change shipment since it has been dispatched\n");
    }
    
}

void Shipment::deleteProduct(Stock* stockList, std::string stockname){
    if(dispatched == false){// check if dispatched
        Stock::stockItem_t* stock = stockList->getStock(stockname);
        Stock::stockItem_t* toDelete = productlist.getStock(stockname);
        if(stock != nullptr && toDelete != nullptr){ // check if valid
            stock->q += toDelete->q; // Re-add quantity to stock since order was cancled
        }

        (productlist.removeStock(stockname));
    }else{
        printf("ERROR: Cannnot change shipment since it has been dispatched\n");
    }    
}

bool Shipment::ConfigureTransport(TransportManager* transportManager, int code){
    if(dispatched == false){// check if dispatched
        Transport* Newtransport = transportManager->getTransport(code);
        if (Newtransport == nullptr){ // Check if transport exists in list before using it
            printf("ERROR: Transport not found\n");
            return false;
        }else{
            delete this->transport; // remove current transport
            Transport* copyTransport = Newtransport->clone();
            this->transport = copyTransport;
            return true;
        }
    }else{
        printf("ERROR: Cannnot change shipment since it has been dispatched\n");
        return false;
    }
}
void Shipment::updateCost(){
    if(dispatched == false){// check if dispatched
        cost = calculateTotalCost();// Updated only when shipment is created or updated due to the discount needing to be kept from on creation
    }
}

float Shipment::calculateTotalCost(){
    float totalCost;

    std::vector<Stock::stockItem_t*>& stockList = *(productlist.getStockList());
    for (Stock::stockItem_t* product : stockList) {
        // Add cost of item for each item ordered
        totalCost += product->p->getCost()*product->p->calculate_discount()*product->q;
        // Add the cost of packaging for each item
        totalCost += product->p->getPackagingCost()*product->q;
    }
    totalCost += transport->calcPrice(distance);

    return totalCost;
}

float Shipment::calculateTime(){
    return transport->estimateDeliveryTime(distance);
}

void Shipment::deleteShipment(){
    delete transport;
    productlist.clearStock();
}