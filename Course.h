#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course
{
private:
    string courseNumber;    // Stores the course number
    string courseName;      // Stores the course name
    string schedule;        // Stores the course schedule
    double price;           // Stores the course price

public:
    // Default constructor
    Course();

    // Constructor with values
    Course(const string& number,
           const string& name,
           const string& courseSchedule,
           double coursePrice);

    // Set the course number
    void setCourseNumber(const string& number);

    // Set the course name
    void setCourseName(const string& name);

    // Set the course schedule
    void setSchedule(const string& courseSchedule);

    // Set the course price
    void setPrice(double coursePrice);

    // Return the course number
    string getCourseNumber() const;

    // Return the course name
    string getCourseName() const;

    // Return the course schedule
    string getSchedule() const;

    // Return the course price
    double getPrice() const;

    // Display the course information
    void display() const;
};

#endif
