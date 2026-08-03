#ifndef ADMIN_INTERFACE_H
#define ADMIN_INTERFACE_H

#include "Interface.h"

class AdminInterface : public Interface
{
private:
    void addDepartment();
    void addCourseToDepartment();

public:
    void run() override;
};

#endif
