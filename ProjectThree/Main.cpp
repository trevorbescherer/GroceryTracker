#include <iostream>
#include <string>
#include "GroceryTracker.h"

// Helper: read a whole line and return it.
static std::string ReadLine(const std::string& prompt) {
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}

// Helper: print the main menu shown each loop iteration
static void ShowMenu() {
    std::cout << "\n----- Corner Grocer Item Tracker -----\n"
        << "1. Look up frequency of a specific item\n"
        << "2. Print frequency of all items\n"
        << "3. Print histogram of all items\n"
        << "4. Exit\n";
}

int main() {
    const std::string kInputFile = "CS210_Project_Three_Input_File.txt";

    GroceryTracker tracker;

    // Initialize tracker by reading the input file and writing frequency.dat
    if (!tracker.Init(kInputFile)) {
        std::cout << "Error: Could not open input file \"" << kInputFile << "\".\n"
            << "Make sure it is in the same folder as your program.\n";
        return 1;
    }

    bool running = true;

    // Main menu loop
    while (running) {
        ShowMenu();
        std::string choice = ReadLine("Select an option (1-4): ");

        if (choice == "1") {
            // Ask for item name and show its frequency
            std::string item = ReadLine("Enter the item name to look up: ");
            int count = tracker.GetCount(item);
            std::cout << "Frequency of \"" << item << "\": " << count << "\n";

        }
        else if (choice == "2") {
            // Print every item with its count (alphabetical)
            std::cout << "\nItem counts:\n";
            tracker.PrintAllCounts();

        }
        else if (choice == "3") {
            // Print the text-based histogram using asterisks
            std::cout << "\nItem histogram:\n";
            tracker.PrintHistogram('*');

        }
        else if (choice == "4") {
            // Exit program
            running = false;
            std::cout << "Exiting. Goodbye!\n";

        }
        else {
            // Input validation
            std::cout << "Invalid choice. Please enter 1, 2, 3, or 4.\n";
        }
    }

    return 0;
}
