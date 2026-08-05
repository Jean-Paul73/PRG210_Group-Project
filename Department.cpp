#include "Department.h"
#include <cstring>   // strcpy, strlen
#include <iostream>

// ---------- private helper ----------
void Department::resize()
{
    int newCapacity = (capacity == 0) ? 4 : capacity * 2;
    Course* newArray = new Course[newCapacity];

    for (int i = 0; i < totalCourses; ++i)
        newArray[i] = courses[i];

    delete[] courses;
    courses  = newArray;
    capacity = newCapacity;
}

// ---------- constructors ----------
Department::Department()
    : courses(nullptr), totalCourses(0), capacity(0)
{
    departmentName[0] = '\0';
}

Department::Department(const char* name)
    : courses(nullptr), totalCourses(0), capacity(0)
{
    setDepartmentName(name);
}

// ---------- Rule of Three ----------
Department::Department(const Department& other)
    : courses(nullptr), totalCourses(0), capacity(0)
{
    setDepartmentName(other.departmentName);

    if (other.totalCourses > 0)
    {
        capacity     = other.capacity;
        totalCourses = other.totalCourses;
        courses      = new Course[capacity];
        for (int i = 0; i < totalCourses; ++i)
            courses[i] = other.courses[i];
    }
}

Department& Department::operator=(const Department& other)
{
    if (this == &other)
        return *this;

    // free existing memory
    delete[] courses;
    courses      = nullptr;
    totalCourses = 0;
    capacity     = 0;

    setDepartmentName(other.departmentName);

    if (other.totalCourses > 0)
    {
        capacity     = other.capacity;
        totalCourses = other.totalCourses;
        courses      = new Course[capacity];
        for (int i = 0; i < totalCourses; ++i)
            courses[i] = other.courses[i];
    }

    return *this;
}

Department::~Department()
{
    delete[] courses;
    courses = nullptr;
}

// ---------- name ----------
void Department::setDepartmentName(const char* name)
{
    if (name == nullptr)
    {
        departmentName[0] = '\0';
        return;
    }

    // safe copy – leave room for the null terminator
    std::strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
}

const char* Department::getDepartmentName() const
{
    return departmentName;
}

// ---------- course management ----------
int Department::getTotalCourses() const
{
    return totalCourses;
}

void Department::addCourse(const Course& newCourse)
{
    if (totalCourses == capacity)
        resize();

    courses[totalCourses] = newCourse;
    ++totalCourses;
}

Course* Department::getCourse(int index)
{
    if (index < 0 || index >= totalCourses)
        return nullptr;
    return &courses[index];
}

const Course* Department::getCourse(int index) const
{
    if (index < 0 || index >= totalCourses)
        return nullptr;
    return &courses[index];
}

void Department::displayCourses() const
{
    std::cout << "Department: " << departmentName
              << "  (" << totalCourses << " course"
              << (totalCourses == 1 ? "" : "s") << ")\n";

    if (totalCourses == 0)
    {
        std::cout << "  (no courses)\n";
        return;
    }

    for (int i = 0; i < totalCourses; ++i)
    {
        std::cout << "--- Course #" << (i + 1) << " ---\n";
        courses[i].display();
    }
}
