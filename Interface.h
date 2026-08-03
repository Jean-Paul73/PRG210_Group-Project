#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

class Interface
{
protected:
    int readIntInRange(const std::string& prompt,
                       int minimum,
                       int maximum) const;

    double readPositiveDouble(const std::string& prompt) const;

    std::string readNonEmptyLine(const std::string& prompt) const;

    std::string readSchedule(const std::string& prompt) const;

    void listDepartments() const;

public:
    virtual void run() = 0;
    virtual ~Interface();
};

#endif
