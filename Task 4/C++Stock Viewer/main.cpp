
#include <iostream>
#include <fstream>
#include <vector>
#include "PBLogistics.pb.h"
#include "Stock.h"
#include <filesystem>

using namespace std;

// Will set current directory to the build directory;
std::filesystem::path getExecutableDirectory() {
    char result[1024];
    ssize_t count = readlink("/proc/self/exe", result, sizeof(result) - 1);
    if (count != -1) {
        result[count] = '\0';
        return std::filesystem::path(result).parent_path();
    } else {
        // Handle error
        std::cerr << "Error getting executable directory" << std::endl;
        return std::filesystem::current_path();
    }
}

int main(int, char**){
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    Stock stock;

    std::filesystem::path executableDir = getExecutableDirectory();

    // Set the working directory to the executable directory
    std::filesystem::current_path(executableDir);

    // Update the Directory to Java folder in Task 3 Folder
    std::filesystem::path stockFile = executableDir /".."/"..";
    std::filesystem::current_path(stockFile);

    PBStock protobufStock;


    std::filesystem::path currentPath = std::filesystem::current_path();
    std::string fileName = "stock.pb";
    std::filesystem::path filePath = currentPath / fileName;

    //------------------- LOADING -------------------------
    try {
        std::ifstream input(filePath, std::ios::binary);
    
        if (input.is_open()) {
            if (protobufStock.ParseFromIstream(&input)) {
                std::cout << "Protobuf data read from file: " << filePath << std::endl;
            } else {
                std::cerr << "Failed to parse protobuf data from file: " << filePath << std::endl;
            }
        } else {
            std::cerr << "Unable to open file for reading: " << filePath << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    //------------------- Convert To C++-------------------------
    stock.copyFromProto(protobufStock);


    stock.displayStock();
    google::protobuf::ShutdownProtobufLibrary();
}
