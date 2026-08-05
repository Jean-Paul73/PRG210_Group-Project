#include "StudentInterface.h"
#include "Department.h"

#include <iostream>
#include <vector>

using namespace std;

// The vector is created in main.cpp
extern vector<Department> StoreDepartments;

// Student main menu
void StudentInterface::run()
{
    while (true)
    {
        cout << "\nSTUDENT MAIN MENU\n";
        cout << "1. Show Cart\n";
        cout << "2. Browse Departments\n";
        cout << "3. Go Back\n";

        // Read the user's choice
        int choice = readIntInRange(
            "Enter your choice [1, 2, 3]: ",
            1,
            3
        );

        // Open the cart menu
        if (choice == 1)
        {
            showCartMenu();
        }
        // Browse the departments
        else if (choice == 2)
        {
            browseDepartments();
        }
        // Return to the main menu
        else
        {
            return;
        }
    }
}

// Display the cart menu
void StudentInterface::showCartMenu()
{
    while (true)
    {
        cout << "\nCART MENU\n";
        cout << "1. View Cart\n";
        cout << "2. Checkout\n";
        cout << "3. Go Back\n";

        // Read the user's choice
        int choice = readIntInRange(
            "Enter your choice [1, 2, 3]: ",
            1,
            3
        );

        // Show all courses in the cart
        if (choice == 1)
        {
            cart.listCourses();
        }
        // Checkout
        else if (choice == 2)
        {
            if (cart.isEmpty())
            {
                cout << "Your cart is empty.\n";
            }
            else
            {
                cart.listCourses();
                cout << "Thank you for your purchase.\n";
                cart.clear();
            }
        }
        // Return to the student menu
        else
        {
            return;
        }
    }
}

// Show all departments
void StudentInterface::browseDepartments()
{
    // Check if there are any departments
    if (StoreDepartments.empty())
    {
        cout << "No departments available.\n";
        return;
    }

    // Display all departments
    listDepartments();

    // Ask the user to choose a department
    int departmentNumber = readIntInRange(
        "Choose a department [0 to go back]: ",
        0,
        StoreDepartments.size()
    );

    // Return if the user enters 0
    if (departmentNumber == 0)
    {
        return;
    }

    // Open the selected department
    showCoursesMenu(departmentNumber - 1);
}

// Show all courses in one department
void StudentInterface::showCoursesMenu(int departmentIndex)
{
    // Get the selected department
    Department& department = StoreDepartments[departmentIndex];

    while (true)
    {
        cout << "\nCourses in "
             << department.getDepartmentName()
             << endl;

        // Display all courses
        department.displayCourses();

        cout << "\n1. Add Course to Cart\n";
        cout << "2. Go Back\n";

        // Read the user's choice
        int choice = readIntInRange(
            "Enter your choice [1, 2]: ",
            1,
            2
        );

        // Return to the department menu
        if (choice == 2)
        {
            return;
        }

        // Check if there are any courses
        if (department.getTotalCourses() == 0)
        {
            cout << "No courses available.\n";
            continue;
        }

        // Ask the user to choose a course
        int courseNumber = readIntInRange(
            "Enter course number [0 to go back]: ",
            0,
            department.getTotalCourses()
        );

        // Return if the user enters 0
        if (courseNumber == 0)
        {
            continue;
        }

        // Get the selected course
        Course* course = department.getCourse(courseNumber - 1);

        // Add the course to the cart
        if (course != nullptr)
        {
            cart.addCourse(*course);
            cout << "Course added to cart.\n";
        }
    }
}
