cmake_minimum_required(VERSION 3.0.0)
project(Server VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(Protobuf REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(gRPC REQUIRED grpc++)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${PROTOBUF_INCLUDE_DIRS} ${GRPC_INCLUDE_DIRS})

set(SOURCE_FILES1 main.cpp remotemap.pb.cc remotemap.grpc.pb.cc)
add_executable(Calc_Server ${SOURCE_FILES1} )
target_link_libraries(Calc_Server ${PROTOBUF_LIBRARIES} ${GRPC_LIBRARIES} grpc++)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
