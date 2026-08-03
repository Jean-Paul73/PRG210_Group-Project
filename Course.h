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
    Course();
    Course(const std::string& number,
           const std::string& name,
           const std::string& courseSchedule,
           double coursePrice);

    void setCourseNumber(const std::string& number);
    void setCourseName(const std::string& name);
    void setSchedule(const std::string& courseSchedule);
    void setPrice(double coursePrice);

    std::string getCourseNumber() const;
    std::string getCourseName() const;
    std::string getSchedule() const;
    double getPrice() const;

    void display() const;
};

#endif
