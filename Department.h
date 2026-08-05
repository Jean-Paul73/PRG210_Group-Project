#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Course.h"
#include <string>
#include <vector>

using namespace std;

class Department
{
private:
    string departmentName;       // Stores the department name
    vector<Course> courses;      // Stores the courses

public:
    // Default constructor
    Department();

    // Constructor with department name
    Department(const string& name);

    // Set the department name
    void setDepartmentName(const string& name);

    // Return the department name
    string getDepartmentName() const;

    // Return the number of courses
    int getTotalCourses() const;

    // Add a new course
    void addCourse(const Course& newCourse);

    // Return a pointer to a course
    Course* getCourse(int index);

    // Return a const pointer to a course
    const Course* getCourse(int index) const;

    // Display all courses
    void displayCourses() const;
};

#endif
