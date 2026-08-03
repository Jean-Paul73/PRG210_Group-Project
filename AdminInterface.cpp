#include "AdminInterface.h"
#include "Course.h"
#include "DataManager.h"
#include "Department.h"
#include <iostream>

extern Department* StoreDepartments; // Pointer to the array of departments
extern int TotalDepartments;

void AdminInterface::run() // Override the run method from the Interface class
{
    while (true)
    {
        std::cout << "\nAdmin Main Menu\n";
        std::cout << "1. List Departments\n";
        std::cout << "2. Add Department\n";
        std::cout << "3. Add Course to Department\n";
        std::cout << "4. Save Changes to CSV\n";
        std::cout << "5. Exit\n";

        int choice = readIntInRange( 
            "Enter your choice [1, 2, 3, 4, 5]: ",
            1,
            5);

        if (choice == 1)
        {
            listDepartments();
        }
        else if (choice == 2)
        {
            addDepartment();
        }
        else if (choice == 3)
        {
            addCourseToDepartment();
        }
        else if (choice == 4)
        {
            if (saveDataToCSV())
            {
                std::cout << "Changes saved successfully.\n";
            }
            else
            {
                std::cout << "Error: Changes could not be saved.\n";
            }
        }
        else
        {
            return;
        }
    }
}

void AdminInterface::addDepartment() // Method to add a new department
{
    std::string name =
        readNonEmptyLine("Enter department name: ");

    Department* newDepartments =
        new Department[TotalDepartments + 1]; // Create a new array with one additional department

    for (int i = 0; i < TotalDepartments; i++)
    {
        newDepartments[i] = StoreDepartments[i];
    }

    newDepartments[TotalDepartments].setDepartmentName( // Set the name of the new department
        name.c_str());

    delete[] StoreDepartments;
    StoreDepartments = newDepartments;
    TotalDepartments++; // Increment the total number of departments

    std::cout << "Department added successfully.\n";
}

void AdminInterface::addCourseToDepartment() // Method to add a new course to an existing department
{
    if (TotalDepartments == 0)
    {
        std::cout << "No departments are available. "
                  << "Add a department first.\n";
        return;
    }

    listDepartments(); // Display the list of departments

    int departmentNumber = readIntInRange(
        "Enter department number [0 to go back]: ",
        0,
        TotalDepartments);

    if (departmentNumber == 0)
    {
        return;
    }

    Department& selectedDepartment = // Reference to the selected department
        StoreDepartments[departmentNumber - 1];

    std::cout << "\nCourses in " 
              << selectedDepartment.getDepartmentName()
              << '\n';

    selectedDepartment.displayCourses(); 

    std::string courseNumber =
        readNonEmptyLine("Enter course number: ");

    std::string courseName =
        readNonEmptyLine("Enter course name: ");

    std::string schedule =
        readSchedule("Enter course schedule [M/W, T/R, W/F]: ");

    double price =
        readPositiveDouble("Enter course price: ");

    Course newCourse(courseNumber, // Create a new Course object
                     courseName,
                     schedule,
                     price);

    selectedDepartment.addCourse(newCourse); // Add the new course to the selected department

    std::cout << "Course added successfully.\n";
}
