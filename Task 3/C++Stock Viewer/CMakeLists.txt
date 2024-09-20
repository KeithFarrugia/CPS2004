cmake_minimum_required(VERSION 3.0.0)
project(StockViewer VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


# Add header files
set(PRODUCT_HEADERS
    Product/Product.h
    Product/Packaging.h
    Product/Apparel.h
    Product/Clothing.h
    Product/Accessory.h
    Product/Electronics.h
    Product/Appliance.h
    Product/Tech.h
    Product/Consumable.h
    Product/Drink.h
    Product/Food.h
    Product/Furniture.h
    Product/Storage.h
    Product/Decor.h
    Product/Flora.h
    Product/Seeds.h
    Product/Plants.h
    Product/Games.h
    Product/Digital.h
    Product/Physical.h
)

# Add corresponding source files
set(PRODUCT_SOURCES
    Product/Product.cpp
    Product/Packaging.cpp
    Product/Apparel.cpp
    Product/Clothing.cpp
    Product/Accessory.cpp
    Product/Electronics.cpp
    Product/Appliance.cpp
    Product/Tech.cpp
    Product/Consumable.cpp
    Product/Drink.cpp
    Product/Food.cpp
    Product/Furniture.cpp
    Product/Storage.cpp
    Product/Decor.cpp
    Product/Flora.cpp
    Product/Seeds.cpp
    Product/Plants.cpp
    Product/Games.cpp
    Product/Digital.cpp
    Product/Physical.cpp
)

add_library(ProductLibrary ${PRODUCT_HEADERS} ${PRODUCT_SOURCES})

find_package(Protobuf REQUIRED)
set(SOURCE_FILES1 PBLogistics.pb.cc Stock.cpp)
add_executable(Viewer main.cpp ${SOURCE_FILES1})

target_link_libraries(Viewer ${PROTOBUF_LIBRARIES})
target_link_libraries(Viewer ProductLibrary)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
