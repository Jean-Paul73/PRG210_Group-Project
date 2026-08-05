#ifndef STUDENT_INTERFACE_H
#define STUDENT_INTERFACE_H

#include "Cart.h"
#include "Interface.h"

class StudentInterface : public Interface
{
private:
    Cart cart; // Stores the student's shopping cart

    // Display the cart menu
    void showCartMenu();

    // Display all departments
    void browseDepartments();

    // Display all courses in one department
    void showCoursesMenu(int departmentIndex);

public:
    // Run the student menu
    void run() override;
};

#endif
