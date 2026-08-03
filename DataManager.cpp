#include "DataManager.h"
#include "Course.h"
#include "Department.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

extern Department* StoreDepartments;
extern int TotalDepartments;
extern const char* csvFile;

static bool splitDepartmentLine(const std::string& line,
                                std::string& name,
                                int& courseCount)
{
    std::size_t comma = line.find(',');

    if (comma == std::string::npos)
    {
        return false;
    }

    name = line.substr(0, comma);

    std::stringstream stream(line.substr(comma + 1));
    return static_cast<bool>(stream >> courseCount);
}

static bool splitCourseLine(const std::string& line,
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
    std::ifstream file(csvFile);

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

    file.ignore(10000, '\n');

    delete[] StoreDepartments;
    StoreDepartments = nullptr;
    TotalDepartments = 0;

    if (departmentCount <= 0)
    {
        return true;
    }

    StoreDepartments = new Department[departmentCount];

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

        std::string departmentName;
        int courseCount = 0;

        if (!splitDepartmentLine(departmentLine,
                                 departmentName,
                                 courseCount))
        {
            std::cout << "Invalid department line in CSV.\n";
            delete[] StoreDepartments;
            StoreDepartments = nullptr;
            TotalDepartments = 0;
            return false;
        }

        StoreDepartments[i].setDepartmentName(departmentName.c_str());

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
                std::cout << "Invalid course line in CSV.\n";
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

bool saveDataToCSV()
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
