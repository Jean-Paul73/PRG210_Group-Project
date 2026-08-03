#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Course.h"

class Department
{
private:
    char departmentName[100];
    Course* courses;
    int totalCourses;

public:
    Department();
    Department(const char* name);

    // Needed because this class owns dynamic memory.
    Department(const Department& other);
    Department& operator=(const Department& other);

    ~Department();

    void setDepartmentName(const char* name); // Method to set the name of the department
    const char* getDepartmentName() const;

    int getTotalCourses() const; // Method to get the total number of courses in the department
    void addCourse(const Course& newCourse);

    Course* getCourse(int index); // Method to get a pointer to a course at a specific index in the department
    const Course* getCourse(int index) const;

    void displayCourses() const;
};

#endif
