#include "AdminInterface.h"
#include "DataManager.h"
#include "Department.h"
#include "Interface.h"
#include "StudentInterface.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Stores all departments in the program
vector<Department> StoreDepartments;

// Name of the CSV file
const char* csvFile = "courses.csv";

// Read the user's first menu choice
int readInitialChoice()
{
    while (true)
    {
        cout << "\nINITIAL MENU\n";
        cout << "1. Student\n";
        cout << "2. Admin\n";
        cout << "3. Exit\n";
        cout << "Enter your choice [1, 2, 3]: ";

        string input;
        getline(cin, input);

        stringstream stream(input);

        int choice;
        char extra;

        // Check that the user entered only 1, 2, or 3
        if ((stream >> choice) &&
            !(stream >> extra) &&
            choice >= 1 &&
            choice <= 3)
        {
            return choice;
        }

        cout << "Invalid input. Enter 1, 2, or 3.\n";
    }
}

// Main function
int main()
{
    // Load information from the CSV file
    if (loadDataFromCSV())
    {
        cout << "Course data loaded successfully.\n";
    }
    else
    {
        cout << "No valid CSV data was loaded.\n";
        cout << "The program will start with an empty store.\n";
    }

    while (true)
    {
        // Ask the user to choose Student, Admin, or Exit
        int roleChoice = readInitialChoice();

        Interface* userInterface = nullptr;

        if (roleChoice == 1)
        {
            // Create the student menu
            userInterface = new StudentInterface();
        }
        else if (roleChoice == 2)
        {
            // Create the admin menu
            userInterface = new AdminInterface();
        }
        else
        {
            // Close the program
            cout << "Program closed.\n";
            break;
        }

        // Use polymorphism to run the selected menu
        userInterface->run();

        // Delete the menu object
        delete userInterface;
    }

    return 0;
}
