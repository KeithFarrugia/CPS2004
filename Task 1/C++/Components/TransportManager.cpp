#include "TransportManager.h"

TransportManager::TransportManager() {}

void TransportManager::addTransport(Transport* newTransport) {
    if(newTransport == nullptr){return;}

    if(getTransport(newTransport->getCode()) == nullptr){ // check if created properly and not duplicate
        transportList.push_back(newTransport);
        printf("\nTransport Added\n");
        return;
    }
    printf("\nERROR: Code Already in Use\n");
}

void TransportManager::removeTransport(int code) {
    for(int i = 0; i < transportList.size(); i++){

        if(transportList[i]->getCode() == code){
            delete transportList[i];
            transportList.erase(transportList.begin()+i);
            printf("\nDeleted Successfully\n");
            return;
        }
    }
    printf("\nERROR: Code not found\n");
}

void TransportManager::updateTransport(int code, Transport* newTransport){
    if(newTransport == nullptr){return;}

    Transport* toUpdate = getTransport(code);
    if (toUpdate != nullptr) {

        // Check that Transport either has the same code as the one being updated or a different code
        if ((newTransport->getCode() == toUpdate->getCode()) || 
            (newTransport->getCode() != toUpdate->getCode() && getTransport(newTransport->getCode()) == nullptr)) {

            removeTransport(code);
            addTransport(newTransport);
            printf("\nTransport Updated\n");
            return;
        }
        printf("Transport was NOT Updated.\n");
    } else {
        printf("Transport not found in Transport list.\n");
    }
}


Transport* TransportManager::getTransport(int code){
    for(Transport* t : transportList){
        if(t->getCode() == code){
            return t;
        };
    }
    return nullptr;
}


void TransportManager::displayTransports(){
    printf("\n===========Transport List===========\n");
    for (Transport* transport : transportList) {
        printf("\n%s",transport->to_string().c_str());
    }
}
void TransportManager::displayTransports(int code){
    Transport* transport = getTransport(code);
    if(transport != nullptr){
        printf("\n%s",transport->to_string().c_str());
        return;
    }
    printf("\nERROR: Code not found\n");
}

void TransportManager::clearTransport(){
    for (Transport* transport : transportList) {
        delete transport;
    }
    transportList.clear();
}


TransportManager::~TransportManager() {
    clearTransport();
}
