#include "Cart.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Cart::Cart()
{
    subtotal = 0.0;
}

// Add a course to the cart
void Cart::addCourse(const Course& course)
{
    // Add the course to the list
    courses.push_back(course);

    // Update the subtotal
    subtotal += course.getPrice();
}

// Display all courses in the cart
void Cart::listCourses() const
{
    // Check if the cart is empty
    if (courses.empty())
    {
        cout << "No courses in the cart.\n";
        return;
    }

    cout << "\nCourses in Cart\n";
    cout << "---------------------------------------------\n";

    int number = 1;

    // Display every course in the list
    for (const Course& course : courses)
    {
        cout << number << ". "
             << course.getCourseNumber() << " | "
             << course.getCourseName() << " | "
             << course.getSchedule() << " | $"
             << fixed << setprecision(2)
             << course.getPrice() << endl;

        number++;
    }

    cout << "---------------------------------------------\n";
    cout << "Subtotal: $" << fixed << setprecision(2)
         << getSubtotal() << endl;
    cout << "Tax (13%): $" << getTax() << endl;
    cout << "Total: $" << getTotalWithTax() << endl;
}

// Remove all courses from the cart
void Cart::clear()
{
    courses.clear();
    subtotal = 0.0;
}

// Check if the cart is empty
bool Cart::isEmpty() const
{
    return courses.empty();
}

// Return the number of courses
int Cart::getTotalCourses() const
{
    return courses.size();
}

// Return the subtotal
double Cart::getSubtotal() const
{
    return subtotal;
}

// Calculate the tax
double Cart::getTax() const
{
    return subtotal * 0.13;
}

// Return the total price with tax
double Cart::getTotalWithTax() const
{
    return subtotal + getTax();
}
