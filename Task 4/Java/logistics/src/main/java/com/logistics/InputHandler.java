package com.logistics;

import java.util.InputMismatchException;
import java.util.Scanner;

public class InputHandler {

    private static final Scanner scanner = new Scanner(System.in);

    public static int readInt() {
        try {
            return scanner.nextInt();
        } catch (InputMismatchException e) {
            clearInputBuffer();
            throw new IllegalArgumentException("Invalid input. Please enter a valid integer.");
        } finally {
            clearInputBuffer();
        }
    }

    public static float readFloat() {
        try {
            return scanner.nextFloat();
        } catch (InputMismatchException e) {
            clearInputBuffer();
            throw new IllegalArgumentException("Invalid input. Please enter a valid floating-point number.");
        } finally {
            clearInputBuffer();
        }
    }

    public static String readString() {
        try {
            return scanner.nextLine();
        } catch (InputMismatchException e) {
            clearInputBuffer();
            throw new IllegalArgumentException("Invalid input. Please enter a valid floating-point number.");
        }
    }

    public static boolean readBool() {
        char response = Character.toUpperCase(scanner.next().charAt(0));
        clearInputBuffer();

        if (response == 'Y') {
            return true;
        } else if (response == 'N') {
            return false;
        } else {
            throw new IllegalArgumentException("Invalid input. Please enter Y or N.");
        }
    }

    private static void clearInputBuffer() {
        scanner.nextLine(); // Consume the rest of the line
    }

    public static void closeScanner() {
        scanner.close();
    }
}
