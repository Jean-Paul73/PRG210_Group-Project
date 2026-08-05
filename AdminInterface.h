#ifndef ADMIN_INTERFACE_H
#define ADMIN_INTERFACE_H

#include "Interface.h"

class AdminInterface : public Interface
{
private:
    // Add a new department
    void addDepartment();

    // Add a course to a department
    void addCourseToDepartment();

public:
    // Display and control the Admin menu
    void run() override;
};

#endif
