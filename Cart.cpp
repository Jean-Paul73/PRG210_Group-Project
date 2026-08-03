#include "Cart.h"
#include <iomanip>
#include <iostream>

Cart::Cart()
{
    courses = nullptr;
    schedules = nullptr;
    totalCourses = 0;
    subtotal = 0.0;
}

Cart::~Cart()
{
    delete[] courses;
    delete[] schedules;
}

void Cart::addCourse(const Course& course)
{
    Course* newCourses = new Course[totalCourses + 1];
    std::string* newSchedules = new std::string[totalCourses + 1];

    for (int i = 0; i < totalCourses; i++)
    {
        newCourses[i] = courses[i];
        newSchedules[i] = schedules[i];
    }

    newCourses[totalCourses] = course;
    newSchedules[totalCourses] = course.getSchedule();

    delete[] courses;
    delete[] schedules;

    courses = newCourses;
    schedules = newSchedules;

    subtotal += course.getPrice();
    totalCourses++;
}

void Cart::listCourses() const
{
    if (isEmpty())
    {
        std::cout << "No courses in the cart.\n";
        return;
    }

    std::cout << "\nCourses in Cart\n";
    std::cout << "------------------------------\n";

    for (int i = 0; i < totalCourses; i++)
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

void Cart::clear()
{
    delete[] courses;
    delete[] schedules;

    courses = nullptr;
    schedules = nullptr;
    totalCourses = 0;
    subtotal = 0.0;
}

bool Cart::isEmpty() const
{
    return totalCourses == 0;
}

int Cart::getTotalCourses() const
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
