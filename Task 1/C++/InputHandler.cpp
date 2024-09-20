#include "InputHandler.h"
#include <cstdio>
#include <cstring>

void InputHandler::readInt(const char* promptMessage, int* result) {
    printMessage(promptMessage);
    if (scanf("%d", result) != 1) {
        clearInputBuffer();
        throw std::invalid_argument("Invalid input. Please enter a valid integer.");
    }
    clearInputBuffer();
}

void InputHandler::readFloat(const char* promptMessage, float* result) {
    printMessage(promptMessage);
    if (scanf("%f", result) != 1) {
        clearInputBuffer();
        throw std::invalid_argument("Invalid input. Please enter a valid floating-point number.");
    }
    clearInputBuffer();
}

void InputHandler::readString(const char* promptMessage, char result[100]) {
    printMessage(promptMessage);
    if (scanf(" %99[^\n]", result) != 1) {
        clearInputBuffer();
        throw std::invalid_argument("Invalid input. Please enter a valid string.");
    }
    clearInputBuffer();
}

void InputHandler::readBool(const char* promptMessage, bool* result) {
    char response;
    while (true) {
        printMessage(promptMessage);
        if (scanf("%c", &response) != 1) {
            clearInputBuffer();
            throw std::invalid_argument("Invalid input. Please enter Y or N.");
        }
        clearInputBuffer();
        response = std::toupper(response);

        if (response == 'Y') {
            *result = true;
            return;
        }
        if (response == 'N') {
            *result = false;
            return;
        }

        throw std::invalid_argument("Invalid input. Please enter Y or N.");
    }
}

void InputHandler::printMessage(const char* promptMessage) {
    printf("%s", promptMessage);
}

void InputHandler::clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
