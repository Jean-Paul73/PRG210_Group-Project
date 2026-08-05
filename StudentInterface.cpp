#include "StudentInterface.h"
#include "Department.h"
#include <iostream>

extern Department* StoreDepartments; // Pointer to the array of departments
extern int TotalDepartments;

void StudentInterface::run() // Override the run method from the Interface class
{
    while (true)
    {
        std::cout << "\nStudent Main Menu\n";
        std::cout << "1. Show Cart\n";
        std::cout << "2. Browse Departments\n";
        std::cout << "3. Exit\n";

        int choice = readIntInRange(
            "Enter your choice [1, 2, 3]: ",
            1,
            3);

        if (choice == 1)
        {
            showCartMenu();
        }
        else if (choice == 2)
        {
            browseDepartments();
        }
        else
        {
            return;
        }
    }
}

void StudentInterface::showCartMenu() // Method to display the cart menu and handle user interactions with the cart
{
    while (true)
    {
        std::cout << "\nShow Cart Menu\n";
        std::cout << "1. List Courses\n";
        std::cout << "2. Checkout\n";
        std::cout << "3. Return to Main Menu\n";

        int choice = readIntInRange(
            "Enter your choice [1, 2, 3]: ",
            1,
            3);

        if (choice == 1)
        {
            cart.listCourses();
        }
        else if (choice == 2)
        {
            if (cart.isEmpty())
            {
                std::cout << "No courses in the cart.\n";
            }
            else
            {
                cart.listCourses();
                std::cout << "Thank you for your purchase.\n";
                cart.clear();
                return;
            }
        }
        else
        {
            return;
        }
    }
}

void StudentInterface::browseDepartments() // Method to display the browse departments menu and handle user interactions with the departments
{
    while (true)
    {
        listDepartments();

        std::cout << "\nBrowse Departments Menu\n";
        std::cout << "1. List Courses of a Department\n";
        std::cout << "2. Go Back to Main Menu\n";

        int choice = readIntInRange(
            "Enter your choice [1, 2]: ",
            1,
            2);

        if (choice == 2)
        {
            return;
        }

        if (TotalDepartments == 0)
        {
            std::cout << "No departments are available.\n";
            continue;
        }

        int departmentNumber = readIntInRange(
            "Enter department number [0 to go back]: ",
            0,
            TotalDepartments);

        if (departmentNumber == 0)
        {
            continue;
        }

        showCoursesMenu(departmentNumber - 1);
    }
}

void StudentInterface::showCoursesMenu(int departmentIndex) // Method to display the courses menu for a specific department and handle user interactions with the courses
{
    Department& department =
        StoreDepartments[departmentIndex];

    while (true)
    {
        std::cout << "\nCourses in "
                  << department.getDepartmentName()
                  << '\n';

        department.displayCourses();

        std::cout << "\nCourses Menu\n";
        std::cout << "1. Add to Cart a Course\n";
        std::cout << "2. Go Back to Browse Departments Menu\n";

        int choice = readIntInRange(
            "Enter your choice [1, 2]: ",
            1,
            2);

        if (choice == 2)
        {
            return;
        }

        int numberOfCourses =
            department.getTotalCourses();

        if (numberOfCourses == 0)
        {
            std::cout << "No courses are available to add.\n";
            continue;
        }

        int courseNumber = readIntInRange(
            "Enter course number to buy [0 to go back]: ",
            0,
            numberOfCourses);

        if (courseNumber == 0)
        {
            continue;
        }

        const Course* selectedCourse =
            department.getCourse(courseNumber - 1);

        if (selectedCourse != nullptr)
        {
            cart.addCourse(*selectedCourse);
            std::cout << "Course added to cart.\n";
        }
    }
}
