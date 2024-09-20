cmake_minimum_required(VERSION 3.0.0)
project(Logistics_Part1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Add header files
set(PRODUCT_HEADERS
    Components/Product/Product.h
    Components/Product/Packaging.h
    Components/Product/Apparel.h
    Components/Product/Clothing.h
    Components/Product/Accessory.h
    Components/Product/Electronics.h
    Components/Product/Appliance.h
    Components/Product/Tech.h
    Components/Product/Consumable.h
    Components/Product/Drink.h
    Components/Product/Food.h
    Components/Product/Furniture.h
    Components/Product/Storage.h
    Components/Product/Decor.h
    Components/Product/Flora.h
    Components/Product/Seeds.h
    Components/Product/Plants.h
    Components/Product/Games.h
    Components/Product/Digital.h
    Components/Product/Physical.h
)

# Add corresponding source files
set(PRODUCT_SOURCES
    Components/Product/Product.cpp
    Components/Product/Packaging.cpp
    Components/Product/Apparel.cpp
    Components/Product/Clothing.cpp
    Components/Product/Accessory.cpp
    Components/Product/Electronics.cpp
    Components/Product/Appliance.cpp
    Components/Product/Tech.cpp
    Components/Product/Consumable.cpp
    Components/Product/Drink.cpp
    Components/Product/Food.cpp
    Components/Product/Furniture.cpp
    Components/Product/Storage.cpp
    Components/Product/Decor.cpp
    Components/Product/Flora.cpp
    Components/Product/Seeds.cpp
    Components/Product/Plants.cpp
    Components/Product/Games.cpp
    Components/Product/Digital.cpp
    Components/Product/Physical.cpp
)

set(TRANSPORT_HEADERS
    Components/Transport/Transport.h
    Components/Transport/AirTransport.h
    Components/Transport/LandTransport.h
    Components/Transport/SeaTransport.h
)
set(TRANSPORT_SOURCE
    Components/Transport/Transport.cpp
    Components/Transport/AirTransport.cpp
    Components/Transport/LandTransport.cpp
    Components/Transport/SeaTransport.cpp
)

# Add library target
add_library(ProductLibrary ${PRODUCT_HEADERS} ${PRODUCT_SOURCES})
add_library(TransportLibrary ${TRANSPORT_HEADERS} ${TRANSPORT_SOURCE})

# Set source files for the executable, including Accessories.cpp
set(SOURCE_FILES1 main.cpp CLI.cpp InputHandler.cpp   
    Components/Shipment.cpp Components/Stock.cpp Components/ShipmentManager.cpp Components/TransportManager.cpp)

# Add the executable and link it with the ProductLibrary
add_executable(Main ${SOURCE_FILES1})
target_link_libraries(Main ProductLibrary)
target_link_libraries(Main TransportLibrary)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
