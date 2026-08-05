#ifndef CART_H
#define CART_H

#include "Course.h"
#include <list> // STL list to store courses

using namespace std;

class Cart
{
private:
    list<Course> courses;   // List to store all courses in the cart
    double subtotal;        // Total price before tax

public:
    // Default constructor
    Cart();

    // Add a course to the cart
    void addCourse(const Course& course);

    // Display all courses in the cart
    void listCourses() const;

    // Remove all courses from the cart
    void clear();

    // Check if the cart is empty
    bool isEmpty() const;

    // Return the number of courses in the cart
    int getTotalCourses() const;

    // Return the subtotal
    double getSubtotal() const;

    // Calculate 13% tax
    double getTax() const;

    // Return the total price including tax
    double getTotalWithTax() const;
};

#endif
