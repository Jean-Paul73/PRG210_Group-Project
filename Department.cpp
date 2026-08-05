#include "Department.h"
#include <iostream>

using namespace std;

// Default constructor
Department::Department()
{
    departmentName = "";
}

// Constructor with department name
Department::Department(const string& name)
{
    departmentName = name;
}

// Set the department name
void Department::setDepartmentName(const string& name)
{
    departmentName = name;
}

// Return the department name
string Department::getDepartmentName() const
{
    return departmentName;
}

// Return the number of courses
int Department::getTotalCourses() const
{
    return courses.size();
}

// Add a course to the vector
void Department::addCourse(const Course& newCourse)
{
    courses.push_back(newCourse);
}

// Return a pointer to a course
Course* Department::getCourse(int index)
{
    // Check if the index is valid
    if (index < 0 || index >= (int)courses.size())
    {
        return nullptr;
    }

    return &courses[index];
}

// Return a const pointer to a course
const Course* Department::getCourse(int index) const
{
    // Check if the index is valid
    if (index < 0 || index >= (int)courses.size())
    {
        return nullptr;
    }

    return &courses[index];
}

// Display all courses in the department
void Department::displayCourses() const
{
    // Check if there are no courses
    if (courses.empty())
    {
        cout << "No courses are available in this department.\n";
        return;
    }

    // Display every course
    for (int i = 0; i < (int)courses.size(); i++)
    {
        cout << i + 1 << ". ";
        courses[i].display();
    }
}
