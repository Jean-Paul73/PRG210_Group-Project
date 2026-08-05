#include "DataManager.h"
#include "Course.h"
#include "Department.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

extern Department* StoreDepartments; // Pointer to the array of departments
extern int TotalDepartments; // Total number of departments in the store
extern const char* csvFile; // Path to the CSV file for storing department and course data

static bool splitDepartmentLine(const std::string& line, // Method to split a department line from the CSV file into its components
                                std::string& name,
                                int& courseCount)
{
    std::size_t comma = line.find(','); // Find the position of the first comma in the line

    if (comma == std::string::npos)
    {
        return false;
    }

    name = line.substr(0, comma);

    std::stringstream stream(line.substr(comma + 1));
    return static_cast<bool>(stream >> courseCount);
}

static bool splitCourseLine(const std::string& line, // Method to split a course line from the CSV file into its components
                            std::string& number,
                            std::string& name,
                            std::string& schedule,
                            double& price)
{
    std::stringstream stream(line);

    if (!std::getline(stream, number, ','))
    {
        return false;
    }

    if (!std::getline(stream, name, ','))
    {
        return false;
    }

    if (!std::getline(stream, schedule, ','))
    {
        return false;
    }

    std::string priceText;

    if (!std::getline(stream, priceText))
    {
        return false;
    }

    std::stringstream priceStream(priceText);
    return static_cast<bool>(priceStream >> price);
}

bool loadDataFromCSV()
{
    std::ifstream file(csvFile); // Open the CSV file for reading

    if (!file)
    {
        // The file may not exist the first time the program runs.
        return false;
    }

    int departmentCount = 0;

    if (!(file >> departmentCount)) 
    {
        std::cout << "CSV file is not in the expected format.\n";
        return false;
    }

    file.ignore(10000, '\n'); // Ignore the rest of the line after reading the department count

    delete[] StoreDepartments;
    StoreDepartments = nullptr;
    TotalDepartments = 0;

    if (departmentCount <= 0)
    {
        return true;
    }

    StoreDepartments = new Department[departmentCount]; // Allocate memory for the array of departments

    for (int i = 0; i < departmentCount; i++)
    {
        std::string departmentLine;

        if (!std::getline(file, departmentLine))
        {
            std::cout << "CSV file ended unexpectedly.\n";
            delete[] StoreDepartments;
            StoreDepartments = nullptr;
            TotalDepartments = 0;
            return false;
        }

        std::string departmentName; // Variable to hold the department name
        int courseCount = 0;

        if (!splitDepartmentLine(departmentLine,
                                 departmentName,
                                 courseCount))
        {
            std::cout << "Invalid department line in CSV.\n"; // Error message for invalid department line
            delete[] StoreDepartments;
            StoreDepartments = nullptr;
            TotalDepartments = 0;
            return false;
        }

        StoreDepartments[i].setDepartmentName(departmentName.c_str()); // Set the name of the department

        for (int j = 0; j < courseCount; j++)
        {
            std::string courseLine;

            if (!std::getline(file, courseLine))
            {
                std::cout << "CSV file ended unexpectedly.\n";
                delete[] StoreDepartments;
                StoreDepartments = nullptr;
                TotalDepartments = 0;
                return false;
            }

            std::string number;
            std::string name;
            std::string schedule;
            double price = 0.0;

            if (!splitCourseLine(courseLine,
                                 number,
                                 name,
                                 schedule,
                                 price))
            {
                std::cout << "Invalid course line in CSV.\n"; // Error message for invalid course line
                delete[] StoreDepartments;
                StoreDepartments = nullptr;
                TotalDepartments = 0;
                return false;
            }

            Course course(number, name, schedule, price);
            StoreDepartments[i].addCourse(course);
        }
    }

    TotalDepartments = departmentCount;
    return true;
}

bool saveDataToCSV() // Method to save the department and course data to a CSV file
{
    std::ofstream file(csvFile);

    if (!file)
    {
        return false;
    }

    file << TotalDepartments << '\n';

    for (int i = 0; i < TotalDepartments; i++)
    {
        file << StoreDepartments[i].getDepartmentName()
             << ','
             << StoreDepartments[i].getTotalCourses()
             << '\n';

        for (int j = 0;
             j < StoreDepartments[i].getTotalCourses();
             j++)
        {
            const Course* course =
                StoreDepartments[i].getCourse(j);

            if (course != nullptr)
            {
                file << course->getCourseNumber() << ','
                     << course->getCourseName() << ','
                     << course->getSchedule() << ','
                     << course->getPrice() << '\n';
            }
        }
    }

    return true;
}
