#include "Department.h"
#include <cstring>
#include <iostream>

Department::Department() // Default constructor to initialize a Department object
{
    departmentName[0] = '\0';
    courses = nullptr;
    totalCourses = 0;
}

Department::Department(const char* name) // Parameterized constructor to initialize a Department object with a specific name
{
    courses = nullptr;
    totalCourses = 0;
    setDepartmentName(name);
}

Department::Department(const Department& other) // Copy constructor to create a new Department object as a copy of another
{
    std::strncpy(departmentName, other.departmentName, 99);
    departmentName[99] = '\0';

    totalCourses = other.totalCourses;

    if (totalCourses > 0)
    {
        courses = new Course[totalCourses];

        for (int i = 0; i < totalCourses; i++)
        {
            courses[i] = other.courses[i];
        }
    }
    else
    {
        courses = nullptr;
    }
}

Department& Department::operator=(const Department& other) // Assignment operator to assign one Department object to another
{
    if (this != &other)
    {
        delete[] courses;

        std::strncpy(departmentName, other.departmentName, 99);
        departmentName[99] = '\0';

        totalCourses = other.totalCourses;

        if (totalCourses > 0)
        {
            courses = new Course[totalCourses];

            for (int i = 0; i < totalCourses; i++)
            {
                courses[i] = other.courses[i];
            }
        }
        else
        {
            courses = nullptr;
        }
    }

    return *this;
}

Department::~Department()
{
    delete[] courses;
}

void Department::setDepartmentName(const char* name) // Method to set the name of the department
{
    if (name == nullptr)
    {
        departmentName[0] = '\0';
        return;
    }

    std::strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
}

const char* Department::getDepartmentName() const // Method to get the name of the department
{
    return departmentName;
}

int Department::getTotalCourses() const // Method to get the total number of courses in the department
{
    return totalCourses;
}

void Department::addCourse(const Course& newCourse) // Method to add a new course to the department
{
    Course* newArray = new Course[totalCourses + 1];

    for (int i = 0; i < totalCourses; i++)
    {
        newArray[i] = courses[i];
    }

    newArray[totalCourses] = newCourse;

    delete[] courses;
    courses = newArray;
    totalCourses++;
}

Course* Department::getCourse(int index) // Method to get a pointer to a course at a specific index in the department
{
    if (index < 0 || index >= totalCourses)
    {
        return nullptr;
    }

    return &courses[index];
}

const Course* Department::getCourse(int index) const // Method to get a const pointer to a course at a specific index in the department
{
    if (index < 0 || index >= totalCourses)
    {
        return nullptr;
    }

    return &courses[index];
}

void Department::displayCourses() const // Method to display the list of courses in the department
{
    if (totalCourses == 0)
    {
        std::cout << "No courses are available in this department.\n";
        return;
    }

    for (int i = 0; i < totalCourses; i++)
    {
        std::cout << i + 1 << ". ";
        courses[i].display();
    }
}
