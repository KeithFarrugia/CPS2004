package com.logistics.GRPC;
import java.util.List;
import java.util.stream.Collectors;

import com.logistics.Components.Stock;
import com.logistics.Components.Shipment.Shipment;
import com.logistics.GRPC.Remotemap.PBProductItem;

import io.grpc.ManagedChannel;
public class CalculationsGrpcClient {
    private final PBCalculationsGrpc.PBCalculationsBlockingStub blockingStub;

    public CalculationsGrpcClient(ManagedChannel channel){
        blockingStub = PBCalculationsGrpc.newBlockingStub(channel);
    }

    public float calcCost(Shipment shipment){
        Remotemap.PBShipmentInfo.Builder shipmentInfo = Remotemap.PBShipmentInfo.newBuilder();
        shipmentInfo.setTransportCost(shipment.getTransport().calcPrice(shipment.getDistance()));
        List<Stock.stockItem_t> productlist = shipment.getProductList().getStockList();

        shipmentInfo.addAllStock(
            productlist.stream().map(product->{
                PBProductItem.Builder temp = PBProductItem.newBuilder();
                temp.setPrice(product.p.getCost());
                temp.setQuantity(product.q);
                temp.setPackagingCost(product.p.getPackagingCost());
                temp.setDiscount(product.p.calculateDiscount());
                return temp.build();
            }).collect(Collectors.toList())
        );

        return blockingStub.calcCost(shipmentInfo.build()).getResult();
    }
}
