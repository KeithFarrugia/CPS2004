package com.logistics.GRPC;

import static io.grpc.MethodDescriptor.generateFullMethodName;

/**
 */
@javax.annotation.Generated(
    value = "by gRPC proto compiler (version 1.57.2)",
    comments = "Source: remotemap.proto")
@io.grpc.stub.annotations.GrpcGenerated
public final class PBCalculationsGrpc {

  private PBCalculationsGrpc() {}

  public static final java.lang.String SERVICE_NAME = "remotemap.PBCalculations";

  // Static method descriptors that strictly reflect the proto.
  private static volatile io.grpc.MethodDescriptor<com.logistics.GRPC.Remotemap.PBShipmentInfo,
      com.logistics.GRPC.Remotemap.Float> getCalcCostMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "calcCost",
      requestType = com.logistics.GRPC.Remotemap.PBShipmentInfo.class,
      responseType = com.logistics.GRPC.Remotemap.Float.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<com.logistics.GRPC.Remotemap.PBShipmentInfo,
      com.logistics.GRPC.Remotemap.Float> getCalcCostMethod() {
    io.grpc.MethodDescriptor<com.logistics.GRPC.Remotemap.PBShipmentInfo, com.logistics.GRPC.Remotemap.Float> getCalcCostMethod;
    if ((getCalcCostMethod = PBCalculationsGrpc.getCalcCostMethod) == null) {
      synchronized (PBCalculationsGrpc.class) {
        if ((getCalcCostMethod = PBCalculationsGrpc.getCalcCostMethod) == null) {
          PBCalculationsGrpc.getCalcCostMethod = getCalcCostMethod =
              io.grpc.MethodDescriptor.<com.logistics.GRPC.Remotemap.PBShipmentInfo, com.logistics.GRPC.Remotemap.Float>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(SERVICE_NAME, "calcCost"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  com.logistics.GRPC.Remotemap.PBShipmentInfo.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  com.logistics.GRPC.Remotemap.Float.getDefaultInstance()))
              .setSchemaDescriptor(new PBCalculationsMethodDescriptorSupplier("calcCost"))
              .build();
        }
      }
    }
    return getCalcCostMethod;
  }

  /**
   * Creates a new async stub that supports all call types for the service
   */
  public static PBCalculationsStub newStub(io.grpc.Channel channel) {
    io.grpc.stub.AbstractStub.StubFactory<PBCalculationsStub> factory =
      new io.grpc.stub.AbstractStub.StubFactory<PBCalculationsStub>() {
        @java.lang.Override
        public PBCalculationsStub newStub(io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
          return new PBCalculationsStub(channel, callOptions);
        }
      };
    return PBCalculationsStub.newStub(factory, channel);
  }

  /**
   * Creates a new blocking-style stub that supports unary and streaming output calls on the service
   */
  public static PBCalculationsBlockingStub newBlockingStub(
      io.grpc.Channel channel) {
    io.grpc.stub.AbstractStub.StubFactory<PBCalculationsBlockingStub> factory =
      new io.grpc.stub.AbstractStub.StubFactory<PBCalculationsBlockingStub>() {
        @java.lang.Override
        public PBCalculationsBlockingStub newStub(io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
          return new PBCalculationsBlockingStub(channel, callOptions);
        }
      };
    return PBCalculationsBlockingStub.newStub(factory, channel);
  }

  /**
   * Creates a new ListenableFuture-style stub that supports unary calls on the service
   */
  public static PBCalculationsFutureStub newFutureStub(
      io.grpc.Channel channel) {
    io.grpc.stub.AbstractStub.StubFactory<PBCalculationsFutureStub> factory =
      new io.grpc.stub.AbstractStub.StubFactory<PBCalculationsFutureStub>() {
        @java.lang.Override
        public PBCalculationsFutureStub newStub(io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
          return new PBCalculationsFutureStub(channel, callOptions);
        }
      };
    return PBCalculationsFutureStub.newStub(factory, channel);
  }

  /**
   */
  public interface AsyncService {

    /**
     */
    default void calcCost(com.logistics.GRPC.Remotemap.PBShipmentInfo request,
        io.grpc.stub.StreamObserver<com.logistics.GRPC.Remotemap.Float> responseObserver) {
      io.grpc.stub.ServerCalls.asyncUnimplementedUnaryCall(getCalcCostMethod(), responseObserver);
    }
  }

  /**
   * Base class for the server implementation of the service PBCalculations.
   */
  public static abstract class PBCalculationsImplBase
      implements io.grpc.BindableService, AsyncService {

    @java.lang.Override public final io.grpc.ServerServiceDefinition bindService() {
      return PBCalculationsGrpc.bindService(this);
    }
  }

  /**
   * A stub to allow clients to do asynchronous rpc calls to service PBCalculations.
   */
  public static final class PBCalculationsStub
      extends io.grpc.stub.AbstractAsyncStub<PBCalculationsStub> {
    private PBCalculationsStub(
        io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected PBCalculationsStub build(
        io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
      return new PBCalculationsStub(channel, callOptions);
    }

    /**
     */
    public void calcCost(com.logistics.GRPC.Remotemap.PBShipmentInfo request,
        io.grpc.stub.StreamObserver<com.logistics.GRPC.Remotemap.Float> responseObserver) {
      io.grpc.stub.ClientCalls.asyncUnaryCall(
          getChannel().newCall(getCalcCostMethod(), getCallOptions()), request, responseObserver);
    }
  }

  /**
   * A stub to allow clients to do synchronous rpc calls to service PBCalculations.
   */
  public static final class PBCalculationsBlockingStub
      extends io.grpc.stub.AbstractBlockingStub<PBCalculationsBlockingStub> {
    private PBCalculationsBlockingStub(
        io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected PBCalculationsBlockingStub build(
        io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
      return new PBCalculationsBlockingStub(channel, callOptions);
    }

    /**
     */
    public com.logistics.GRPC.Remotemap.Float calcCost(com.logistics.GRPC.Remotemap.PBShipmentInfo request) {
      return io.grpc.stub.ClientCalls.blockingUnaryCall(
          getChannel(), getCalcCostMethod(), getCallOptions(), request);
    }
  }

  /**
   * A stub to allow clients to do ListenableFuture-style rpc calls to service PBCalculations.
   */
  public static final class PBCalculationsFutureStub
      extends io.grpc.stub.AbstractFutureStub<PBCalculationsFutureStub> {
    private PBCalculationsFutureStub(
        io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected PBCalculationsFutureStub build(
        io.grpc.Channel channel, io.grpc.CallOptions callOptions) {
      return new PBCalculationsFutureStub(channel, callOptions);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<com.logistics.GRPC.Remotemap.Float> calcCost(
        com.logistics.GRPC.Remotemap.PBShipmentInfo request) {
      return io.grpc.stub.ClientCalls.futureUnaryCall(
          getChannel().newCall(getCalcCostMethod(), getCallOptions()), request);
    }
  }

  private static final int METHODID_CALC_COST = 0;

  private static final class MethodHandlers<Req, Resp> implements
      io.grpc.stub.ServerCalls.UnaryMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ServerStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ClientStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.BidiStreamingMethod<Req, Resp> {
    private final AsyncService serviceImpl;
    private final int methodId;

    MethodHandlers(AsyncService serviceImpl, int methodId) {
      this.serviceImpl = serviceImpl;
      this.methodId = methodId;
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public void invoke(Req request, io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        case METHODID_CALC_COST:
          serviceImpl.calcCost((com.logistics.GRPC.Remotemap.PBShipmentInfo) request,
              (io.grpc.stub.StreamObserver<com.logistics.GRPC.Remotemap.Float>) responseObserver);
          break;
        default:
          throw new AssertionError();
      }
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public io.grpc.stub.StreamObserver<Req> invoke(
        io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        default:
          throw new AssertionError();
      }
    }
  }

  public static final io.grpc.ServerServiceDefinition bindService(AsyncService service) {
    return io.grpc.ServerServiceDefinition.builder(getServiceDescriptor())
        .addMethod(
          getCalcCostMethod(),
          io.grpc.stub.ServerCalls.asyncUnaryCall(
            new MethodHandlers<
              com.logistics.GRPC.Remotemap.PBShipmentInfo,
              com.logistics.GRPC.Remotemap.Float>(
                service, METHODID_CALC_COST)))
        .build();
  }

  private static abstract class PBCalculationsBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoFileDescriptorSupplier, io.grpc.protobuf.ProtoServiceDescriptorSupplier {
    PBCalculationsBaseDescriptorSupplier() {}

    @java.lang.Override
    public com.google.protobuf.Descriptors.FileDescriptor getFileDescriptor() {
      return com.logistics.GRPC.Remotemap.getDescriptor();
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.ServiceDescriptor getServiceDescriptor() {
      return getFileDescriptor().findServiceByName("PBCalculations");
    }
  }

  private static final class PBCalculationsFileDescriptorSupplier
      extends PBCalculationsBaseDescriptorSupplier {
    PBCalculationsFileDescriptorSupplier() {}
  }

  private static final class PBCalculationsMethodDescriptorSupplier
      extends PBCalculationsBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoMethodDescriptorSupplier {
    private final java.lang.String methodName;

    PBCalculationsMethodDescriptorSupplier(java.lang.String methodName) {
      this.methodName = methodName;
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.MethodDescriptor getMethodDescriptor() {
      return getServiceDescriptor().findMethodByName(methodName);
    }
  }

  private static volatile io.grpc.ServiceDescriptor serviceDescriptor;

  public static io.grpc.ServiceDescriptor getServiceDescriptor() {
    io.grpc.ServiceDescriptor result = serviceDescriptor;
    if (result == null) {
      synchronized (PBCalculationsGrpc.class) {
        result = serviceDescriptor;
        if (result == null) {
          serviceDescriptor = result = io.grpc.ServiceDescriptor.newBuilder(SERVICE_NAME)
              .setSchemaDescriptor(new PBCalculationsFileDescriptorSupplier())
              .addMethod(getCalcCostMethod())
              .build();
        }
      }
    }
    return result;
  }
}
