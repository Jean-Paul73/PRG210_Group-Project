#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course
{
private:
    std::string courseNumber;
    std::string courseName;
    std::string schedule;
    double price;

public:
    // Default constructor
    Course();

    // Parameterized constructor
    Course(const std::string& number,
           const std::string& name,
           const std::string& courseSchedule,
           double coursePrice);

    // Setters
    void setCourseNumber(const std::string& number);
    void setCourseName(const std::string& name);
    void setSchedule(const std::string& courseSchedule);
    void setPrice(double coursePrice);

    // Getters
    std::string getCourseNumber() const;
    std::string getCourseName() const;
    std::string getSchedule() const;
    double getPrice() const;

    // Display course information
    void display() const;
};

#endif
