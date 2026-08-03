#include "Department.h"
#include <cstring>
#include <iostream>

Department::Department()
{
    departmentName[0] = '\0';
    courses = nullptr;
    totalCourses = 0;
}

Department::Department(const char* name)
{
    courses = nullptr;
    totalCourses = 0;
    setDepartmentName(name);
}

Department::Department(const Department& other)
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

Department& Department::operator=(const Department& other)
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

void Department::setDepartmentName(const char* name)
{
    if (name == nullptr)
    {
        departmentName[0] = '\0';
        return;
    }

    std::strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
}

const char* Department::getDepartmentName() const
{
    return departmentName;
}

int Department::getTotalCourses() const
{
    return totalCourses;
}

void Department::addCourse(const Course& newCourse)
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

Course* Department::getCourse(int index)
{
    if (index < 0 || index >= totalCourses)
    {
        return nullptr;
    }

    return &courses[index];
}

const Course* Department::getCourse(int index) const
{
    if (index < 0 || index >= totalCourses)
    {
        return nullptr;
    }

    return &courses[index];
}

void Department::displayCourses() const
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
