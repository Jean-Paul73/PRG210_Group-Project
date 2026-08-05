#include "Interface.h"
#include "Department.h"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// The vector is created in main.cpp
extern vector<Department> StoreDepartments;

// Destructor for the Interface class
Interface::~Interface()
{
}

// Read an integer between a minimum and maximum value
int Interface::readIntInRange(const string& prompt,
                              int minimum,
                              int maximum) const
{
    while (true)
    {
        cout << prompt;

        string input;
        getline(cin, input);

        stringstream stream(input);

        int value;
        char extra;

        // Check that the user entered only one valid number
        if ((stream >> value) &&
            !(stream >> extra) &&
            value >= minimum &&
            value <= maximum)
        {
            return value;
        }

        cout << "Invalid input. Enter a number from "
             << minimum << " to "
             << maximum << ".\n";
    }
}

// Read a positive price from the user
double Interface::readPositiveDouble(const string& prompt) const
{
    while (true)
    {
        cout << prompt;

        string input;
        getline(cin, input);

        stringstream stream(input);

        double value;
        char extra;

        // Check that the price is a positive number
        if ((stream >> value) &&
            !(stream >> extra) &&
            value > 0)
        {
            return value;
        }

        cout << "Invalid price. Enter a positive number.\n";
    }
}

// Read a line that is not empty
string Interface::readNonEmptyLine(const string& prompt) const
{
    while (true)
    {
        cout << prompt;

        string value;
        getline(cin, value);

        // Return the value if it is not empty
        if (!value.empty())
        {
            return value;
        }

        cout << "Input cannot be empty.\n";
    }
}

// Read a valid course schedule
string Interface::readSchedule(const string& prompt) const
{
    while (true)
    {
        string schedule = readNonEmptyLine(prompt);

        // Check if the schedule is valid
        if (schedule == "M/W" ||
            schedule == "T/R" ||
            schedule == "W/F")
        {
            return schedule;
        }

        cout << "Invalid schedule. Enter M/W, T/R, or W/F.\n";
    }
}

// Display all departments
void Interface::listDepartments() const
{
    // Check if the department vector is empty
    if (StoreDepartments.empty())
    {
        cout << "No departments are available.\n";
        return;
    }

    cout << "\nDepartments\n";
    cout << "------------------------------\n";

    // Display every department in the vector
    for (int i = 0;
         i < static_cast<int>(StoreDepartments.size());
         i++)
    {
        cout << i + 1 << ". "
             << StoreDepartments[i].getDepartmentName()
             << endl;
    }
}
