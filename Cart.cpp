#include "Cart.h"
#include <iomanip>
#include <iostream>

Cart::Cart() // Constructor to initialize the cart
{
    courses = nullptr;
    schedules = nullptr;
    totalCourses = 0;
    subtotal = 0.0;
}

Cart::~Cart() // Destructor to clean up dynamically allocated memory
{
    delete[] courses;
    delete[] schedules;
}

void Cart::addCourse(const Course& course) // Method to add a course to the cart    
{
    Course* newCourses = new Course[totalCourses + 1];
    std::string* newSchedules = new std::string[totalCourses + 1];

    for (int i = 0; i < totalCourses; i++)
    {
        newCourses[i] = courses[i]; // Copy existing courses to the new array
        newSchedules[i] = schedules[i];
    }

    newCourses[totalCourses] = course;
    newSchedules[totalCourses] = course.getSchedule(); // Store the schedule of the added course

    delete[] courses;
    delete[] schedules;

    courses = newCourses;
    schedules = newSchedules;

    subtotal += course.getPrice(); // Update the subtotal with the price of the added course
    totalCourses++;
}

void Cart::listCourses() const // Method to list all courses in the cart
{
    if (isEmpty())
    {
        std::cout << "No courses in the cart.\n";
        return;
    }

    std::cout << "\nCourses in Cart\n";
    std::cout << "------------------------------\n";

    for (int i = 0; i < totalCourses; i++) // Loop through the courses in the cart and display their details
    {
        std::cout << i + 1 << ". " 
                  << courses[i].getCourseNumber() << " | "
                  << courses[i].getCourseName() << " | "
                  << schedules[i] << " | $"
                  << std::fixed << std::setprecision(2)
                  << courses[i].getPrice() << '\n';
    }

    std::cout << "------------------------------\n";
    std::cout << "Subtotal: $" << std::fixed << std::setprecision(2)
              << getSubtotal() << '\n';
    std::cout << "Tax (13%): $" << getTax() << '\n';
    std::cout << "Total: $" << getTotalWithTax() << '\n';
}

void Cart::clear() // Method to clear the cart and reset its state
{
    delete[] courses;
    delete[] schedules;

    courses = nullptr;
    schedules = nullptr;
    totalCourses = 0;
    subtotal = 0.0;
}

bool Cart::isEmpty() const // Method to check if the cart is empty
{
    return totalCourses == 0;
}

int Cart::getTotalCourses() const // Method to get the total number of courses in the cart
{
    return totalCourses;
}

double Cart::getSubtotal() const
{
    return subtotal;
}

double Cart::getTax() const
{
    return subtotal * 0.13;
}

double Cart::getTotalWithTax() const
{
    return subtotal + getTax();
}
