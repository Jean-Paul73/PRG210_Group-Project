#include "Course.h"
#include <iomanip>
#include <iostream>

Course::Course()
{
    courseNumber = "";
    courseName = "";
    schedule = "";
    price = 0.0;
}

Course::Course(const std::string& number,
               const std::string& name,
               const std::string& courseSchedule,
               double coursePrice)
{
    courseNumber = number;
    courseName = name;
    schedule = courseSchedule;
    price = coursePrice;
}

void Course::setCourseNumber(const std::string& number)
{
    courseNumber = number;
}

void Course::setCourseName(const std::string& name)
{
    courseName = name;
}

void Course::setSchedule(const std::string& courseSchedule)
{
    schedule = courseSchedule;
}

void Course::setPrice(double coursePrice)
{
    if (coursePrice >= 0.0)
    {
        price = coursePrice;
    }
}

std::string Course::getCourseNumber() const
{
    return courseNumber;
}

std::string Course::getCourseName() const
{
    return courseName;
}

std::string Course::getSchedule() const
{
    return schedule;
}

double Course::getPrice() const
{
    return price;
}

void Course::display() const
{
    std::cout << courseNumber << " | "
              << courseName << " | "
              << schedule << " | $"
              << std::fixed << std::setprecision(2)
              << price << '\n';
}
