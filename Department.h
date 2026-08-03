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

    void setDepartmentName(const char* name);
    const char* getDepartmentName() const;

    int getTotalCourses() const;
    void addCourse(const Course& newCourse);

    Course* getCourse(int index);
    const Course* getCourse(int index) const;

    void displayCourses() const;
};

#endif
