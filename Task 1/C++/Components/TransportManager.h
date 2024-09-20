#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include <vector>
#include <iostream>
#include "Transport_Include.h"

class TransportManager {
public:
    TransportManager();

    void addTransport(Transport* newTransport);
    void removeTransport(int transportCode);
    void updateTransport(int code, Transport* newTransport);
    Transport* getTransport(int Code);
    void displayTransports();
    void displayTransports(int Code);
    void clearTransport();

    ~TransportManager();
private:
    std::vector<Transport*> transportList;
};

#endif // TRANSPORTMANAGER_H