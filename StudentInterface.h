#ifndef STUDENT_INTERFACE_H
#define STUDENT_INTERFACE_H

#include "Cart.h"
#include "Interface.h"

class StudentInterface : public Interface
{
private:
    Cart cart; // Object to manage the student's cart

    void showCartMenu();
    void browseDepartments();
    void showCoursesMenu(int departmentIndex);

public:
    void run() override; // Override the run method from the Interface class
};

#endif
