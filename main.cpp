#include "AdminInterface.h"
#include "DataManager.h"
#include "Department.h"
#include "Interface.h"
#include "StudentInterface.h"
#include <iostream>
#include <sstream>
#include <string>

// Global variables requested in the project instructions.
Department* StoreDepartments = nullptr; // Pointer to the array of departments
int TotalDepartments = 0;
const char* csvFile = "courses.csv"; // Path to the CSV file for storing department and course data

int readInitialChoice()  
{
    while (true)
    {
        std::cout << "\nInitial Menu\n";
        std::cout << "1. Student\n";
        std::cout << "2. Admin\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice [1, 2, 3]: ";

        std::string input;
        std::getline(std::cin, input);

        std::stringstream stream(input);
        int choice;
        char extra;

        if ((stream >> choice) &&
            !(stream >> extra) &&
            choice >= 1 &&
            choice <= 3)
        {
            return choice;
        }

        std::cout << "Invalid input. Enter 1, 2, or 3.\n";
    }
}

int main() // Main function to run the program
{
    if (loadDataFromCSV())
    {
        std::cout << "Course data loaded successfully.\n";
    }
    else
    {
        std::cout << "No valid CSV data was loaded. "
                  << "The program will start with an empty store.\n";
    }

    int roleChoice = readInitialChoice();

    Interface* userInterface = nullptr;

    if (roleChoice == 1)
    {
        userInterface = new StudentInterface();
    }
    else if (roleChoice == 2)
    {
        userInterface = new AdminInterface();
    }
    else
    {
        delete[] StoreDepartments;
        std::cout << "Program closed.\n";
        return 0;
    }

    // Polymorphism: the base pointer calls the derived run() function.
    userInterface->run();

    delete userInterface;
    delete[] StoreDepartments;

    std::cout << "Program closed.\n"; // Display a message indicating that the program has closed
    return 0;
}
