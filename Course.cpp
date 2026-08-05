#include "Course.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Course::Course()
{
    courseNumber = "";
    courseName = "";
    schedule = "";
    price = 0.0;
}

// Constructor with values
Course::Course(const string& number,
               const string& name,
               const string& courseSchedule,
               double coursePrice)
{
    courseNumber = number;
    courseName = name;
    schedule = courseSchedule;
    price = coursePrice;
}

// Set the course number
void Course::setCourseNumber(const string& number)
{
    courseNumber = number;
}

// Set the course name
void Course::setCourseName(const string& name)
{
    courseName = name;
}

// Set the course schedule
void Course::setSchedule(const string& courseSchedule)
{
    schedule = courseSchedule;
}

// Set the course price
void Course::setPrice(double coursePrice)
{
    if (coursePrice >= 0)
    {
        price = coursePrice;
    }
}

// Return the course number
string Course::getCourseNumber() const
{
    return courseNumber;
}

// Return the course name
string Course::getCourseName() const
{
    return courseName;
}

// Return the course schedule
string Course::getSchedule() const
{
    return schedule;
}

// Return the course price
double Course::getPrice() const
{
    return price;
}

// Display the course information
void Course::display() const
{
    cout << courseNumber << " | "
         << courseName << " | "
         << schedule << " | $"
         << fixed << setprecision(2)
         << price << endl;
}
