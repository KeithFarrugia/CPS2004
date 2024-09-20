#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <stdexcept>

class InputHandler {
public:
    static void readInt(const char* promptMessage, int* result);
    static void readFloat(const char* promptMessage, float* result);
    static void readString(const char* promptMessage, char result[100]);
    static void readBool(const char* promptMessage, bool* result);

private:
    static void printMessage(const char* promptMessage);
    static void clearInputBuffer();
};

#endif // INPUT_HANDLER_H
