#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Course.h"

class Department
{
private:
    char departmentName[100];
    Course* courses;          // dynamic array (NO std::vector / std::list)
    int totalCourses;
    int capacity;             // current allocated size of the array

    // Grow the dynamic array when full (doubles capacity)
    void resize();

public:
    // Constructors
    Department();
    Department(const char* name);

    // Rule of Three – required because the class owns dynamic memory
    Department(const Department& other);
    Department& operator=(const Department& other);
    ~Department();

    // Department name
    void setDepartmentName(const char* name);
    const char* getDepartmentName() const;

    // Course management
    int getTotalCourses() const;
    void addCourse(const Course& newCourse);

    Course* getCourse(int index);
    const Course* getCourse(int index) const;

    void displayCourses() const;
};

#endif
