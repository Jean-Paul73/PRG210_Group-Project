#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
private:
    std::string courseNumber;
    std::string courseName;
    std::string schedule;
    double price;

public:
    Course(); // Default constructor to initialize a Course object
    Course(const std::string& number, // Parameterized constructor to initialize a Course object with specific values
           const std::string& name,
           const std::string& courseSchedule,
           double coursePrice);

    void setCourseNumber(const std::string& number); // Method to set the course number
    void setCourseName(const std::string& name);
    void setSchedule(const std::string& courseSchedule);
    void setPrice(double coursePrice);

    std::string getCourseNumber() const; // Method to get the course number
    std::string getCourseName() const;
    std::string getSchedule() const;
    double getPrice() const;

    void display() const;
};

#endif
