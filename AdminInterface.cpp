#include "AdminInterface.h"
#include "Course.h"
#include "DataManager.h"
#include "Department.h"

#include <iostream>
#include <vector>

using namespace std;

// This vector is created in main.cpp
extern vector<Department> StoreDepartments;

// This function displays the Admin menu
void AdminInterface::run()
{
    while (true)
    {
        cout << "\nADMIN MAIN MENU\n";
        cout << "1. List Departments\n";
        cout << "2. Add Department\n";
        cout << "3. Add Course to Department\n";
        cout << "4. Save Changes to CSV\n";
        cout << "5. Go Back\n";

        // Read a valid menu choice from 1 to 5
        int choice = readIntInRange(
            "Enter your choice [1, 2, 3, 4, 5]: ",
            1,
            5
        );

        if (choice == 1)
        {
            // Display all departments
            listDepartments();
        }
        else if (choice == 2)
        {
            // Add a new department
            addDepartment();
        }
        else if (choice == 3)
        {
            // Add a course to a department
            addCourseToDepartment();
        }
        else if (choice == 4)
        {
            // Save all information to the CSV file
            if (saveDataToCSV())
            {
                cout << "Changes saved successfully.\n";
            }
            else
            {
                cout << "Error: Changes could not be saved.\n";
            }
        }
        else if (choice == 5)
        {
            // Return to the main menu
            return;
        }
    }
}

// This function adds a new department
void AdminInterface::addDepartment()
{
    // Ask the user to enter a department name
    string name = readNonEmptyLine(
        "Enter department name: "
    );

    // Create a new Department object
    Department newDepartment(name);

    // Add the department to the vector
    StoreDepartments.push_back(newDepartment);

    cout << "Department added successfully.\n";
}

// This function adds a new course to a selected department
void AdminInterface::addCourseToDepartment()
{
    // Check if there are any departments
    if (StoreDepartments.empty())
    {
        cout << "No departments are available.\n";
        cout << "Add a department first.\n";
        return;
    }

    // Display all departments
    listDepartments();

    // Ask the user to choose a department
    int departmentNumber = readIntInRange(
        "Enter department number [0 to go back]: ",
        0,
        static_cast<int>(StoreDepartments.size())
    );

    // Return to the Admin menu if the user enters 0
    if (departmentNumber == 0)
    {
        return;
    }

    // Get the selected department
    Department& selectedDepartment =
        StoreDepartments[departmentNumber - 1];

    cout << "\nCourses in "
         << selectedDepartment.getDepartmentName()
         << "\n";

    // Display current courses in the department
    selectedDepartment.displayCourses();

    // Ask the user for the course information
    string courseNumber =
        readNonEmptyLine("Enter course number: ");

    string courseName =
        readNonEmptyLine("Enter course name: ");

    string schedule =
        readSchedule(
            "Enter course schedule [M/W, T/R, W/F]: "
        );

    double price =
        readPositiveDouble("Enter course price: ");

    // Create a new Course object
    Course newCourse(
        courseNumber,
        courseName,
        schedule,
        price
    );

    // Add the course to the selected department
    selectedDepartment.addCourse(newCourse);

    cout << "Course added successfully.\n";
}
