#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

class Interface
{
protected:
    int readIntInRange(const std::string& prompt, // Method to read an integer input from the user within a specified range
                       int minimum,
                       int maximum) const;

    double readPositiveDouble(const std::string& prompt) const; // Method to read a positive double input from the user

    std::string readNonEmptyLine(const std::string& prompt) const; 

    std::string readSchedule(const std::string& prompt) const; 

    void listDepartments() const;

public:
    virtual void run() = 0;
    virtual ~Interface();
};

#endif
