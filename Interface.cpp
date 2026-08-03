#include "Interface.h"
#include "Department.h"
#include <iostream>
#include <sstream>

extern Department* StoreDepartments;
extern int TotalDepartments;

Interface::~Interface()
{
}

int Interface::readIntInRange(const std::string& prompt,
                              int minimum,
                              int maximum) const
{
    while (true)
    {
        std::cout << prompt;

        std::string input;
        std::getline(std::cin, input);

        std::stringstream stream(input);
        int value;
        char extra;

        if ((stream >> value) &&
            !(stream >> extra) &&
            value >= minimum &&
            value <= maximum)
        {
            return value;
        }

        std::cout << "Invalid input. Enter a number from "
                  << minimum << " to " << maximum << ".\n";
    }
}

double Interface::readPositiveDouble(const std::string& prompt) const
{
    while (true)
    {
        std::cout << prompt;

        std::string input;
        std::getline(std::cin, input);

        std::stringstream stream(input);
        double value;
        char extra;

        if ((stream >> value) &&
            !(stream >> extra) &&
            value > 0.0)
        {
            return value;
        }

        std::cout << "Invalid price. Enter a positive number.\n";
    }
}

std::string Interface::readNonEmptyLine(const std::string& prompt) const
{
    while (true)
    {
        std::cout << prompt;

        std::string value;
        std::getline(std::cin, value);

        if (!value.empty())
        {
            return value;
        }

        std::cout << "Input cannot be empty.\n";
    }
}

std::string Interface::readSchedule(const std::string& prompt) const
{
    while (true)
    {
        std::string schedule = readNonEmptyLine(prompt);

        if (schedule == "M/W" ||
            schedule == "T/R" ||
            schedule == "W/F")
        {
            return schedule;
        }

        std::cout << "Invalid schedule. Enter M/W, T/R, or W/F.\n";
    }
}

void Interface::listDepartments() const
{
    if (TotalDepartments == 0)
    {
        std::cout << "No departments are available.\n";
        return;
    }

    std::cout << "\nDepartments\n";
    std::cout << "------------------------------\n";

    for (int i = 0; i < TotalDepartments; i++)
    {
        std::cout << i + 1 << ". "
                  << StoreDepartments[i].getDepartmentName()
                  << '\n';
    }
}
