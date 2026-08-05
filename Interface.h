#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

class Interface
{
protected:
    // Read an integer between the minimum and maximum values
    int readIntInRange(const std::string& prompt,
                       int minimum,
                       int maximum) const;

    // Read a positive number
    double readPositiveDouble(const std::string& prompt) const;

    // Read a line that is not empty
    std::string readNonEmptyLine(const std::string& prompt) const;

    // Read a valid course schedule
    std::string readSchedule(const std::string& prompt) const;

    // Display all departments
    void listDepartments() const;

public:
    // Every derived class must have a run function
    virtual void run() = 0;

    // Virtual destructor
    virtual ~Interface();
};

#endif
