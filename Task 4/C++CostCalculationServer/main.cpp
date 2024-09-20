#include <iostream>
#include <memory>
#include <unordered_map>
#include <grpcpp/grpcpp.h>
#include "remotemap.pb.h"
#include "remotemap.grpc.pb.h"

using namespace grpc;
using namespace remotemap;

class CalcSeverImpl final : public PBCalculations::Service{
public:
    Status calcCost(ServerContext* context, const PBShipmentInfo* request, Float* response)override{

        float total = 0;

        for (const PBProductItem& p : request->stock()) {
            // Add cost of item for each item ordered
            total += p.price() * p.discount() * p.quantity();
            // Add the cost of packaging for each item
            total += p.packagingcost() * p.quantity();
        }
        total += request->transportcost();
        printf("COST: %f\n",total);
        response->set_result(total);
        return Status::OK;
    }
private:

};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    CalcSeverImpl service;

    ServerBuilder builder;

    //TODO: ADD SECURITY
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int, char**){
    RunServer();
    return 0;
}
