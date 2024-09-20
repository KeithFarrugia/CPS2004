#ifndef STOCK_H
#define STOCK_H

#include "Product_Include.h"

#include <iostream>
#include <vector>



class Stock {

public:
    
    typedef struct{
        Product* p;
        int q;
    }stockItem_t;

    Stock();

    std::vector<Stock::stockItem_t*>* getStockList(){return &stockList;};

    // Add Delete Update 
    void addStock(Stock::stockItem_t* NewStock);
    void removeStock(const std::string stockName);
    void updateStock(const std::string stockName, Stock::stockItem_t* NewStock);
    void increaseStock(const std::string, int newStock);

    void clearStock();
    stockItem_t* getStock(const std::string stockName);

    // Print
    void displayStock();
    void displayStock(const std::string stockName);

    ~Stock(){clearStock();};
private:
    std::vector<Stock::stockItem_t*> stockList;
};

#endif //STOCK_H