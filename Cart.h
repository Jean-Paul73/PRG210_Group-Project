#ifndef CART_H
#define CART_H

#include "Course.h"
#include <string>

class Cart
{
private:
    Course* courses;
    std::string* schedules;
    int totalCourses;
    double subtotal;

public:
    Cart();
    ~Cart();

    void addCourse(const Course& course);
    void listCourses() const;
    void clear();

    bool isEmpty() const;
    int getTotalCourses() const;
    double getSubtotal() const;
    double getTax() const;
    double getTotalWithTax() const;
};

#endif
