#include "DataManager.h"
#include "Course.h"
#include "Department.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// The vector is created in main.cpp
extern vector<Department> StoreDepartments;

// The CSV file name is created in main.cpp
extern const char* csvFile;

// Load departments and courses from the CSV file
bool loadDataFromCSV()
{
    // Open the CSV file
    ifstream file(csvFile);

    // Check if the file opened correctly
    if (!file)
    {
        cout << "No CSV file found. Starting with empty data.\n";
        return false;
    }

    // Remove any old data from the vector
    StoreDepartments.clear();

    int numberOfDepartments;

    // Read the number of departments
    if (!(file >> numberOfDepartments))
    {
        cout << "Invalid CSV file.\n";
        return false;
    }

    // Ignore the remaining newline
    file.ignore(10000, '\n');

    // Read every department
    for (int i = 0; i < numberOfDepartments; i++)
    {
        string departmentLine;

        // Read one department line
        if (!getline(file, departmentLine))
        {
            cout << "Missing department information.\n";
            return false;
        }

        stringstream departmentStream(departmentLine);

        string departmentName;
        string courseCountText;

        // Read the department name
        getline(departmentStream, departmentName, ',');

        // Read the number of courses
        getline(departmentStream, courseCountText);

        int courseCount = 0;
        stringstream countStream(courseCountText);
        countStream >> courseCount;

        // Create a new department
        Department department(departmentName);

        // Read all courses in this department
        for (int j = 0; j < courseCount; j++)
        {
            string courseLine;

            // Read one course line
            if (!getline(file, courseLine))
            {
                cout << "Missing course information.\n";
                return false;
            }

            stringstream courseStream(courseLine);

            string courseNumber;
            string courseName;
            string schedule;
            string priceText;

            // Separate the course information using commas
            getline(courseStream, courseNumber, ',');
            getline(courseStream, courseName, ',');
            getline(courseStream, schedule, ',');
            getline(courseStream, priceText);

            double price = 0.0;
            stringstream priceStream(priceText);
            priceStream >> price;

            // Create a Course object
            Course course(
                courseNumber,
                courseName,
                schedule,
                price
            );

            // Add the course to the department
            department.addCourse(course);
        }

        // Add the department to the vector
        StoreDepartments.push_back(department);
    }

    cout << "CSV data loaded successfully.\n";
    return true;
}

// Save departments and courses to the CSV file
bool saveDataToCSV()
{
    // Open the CSV file for writing
    ofstream file(csvFile);

    // Check if the file opened correctly
    if (!file)
    {
        cout << "Could not open the CSV file.\n";
        return false;
    }

    // Save the number of departments
    file << StoreDepartments.size() << endl;

    // Save every department
    for (int i = 0;
         i < static_cast<int>(StoreDepartments.size());
         i++)
    {
        Department& department = StoreDepartments[i];

        // Save department name and course count
        file << department.getDepartmentName() << ","
             << department.getTotalCourses() << endl;

        // Save every course in the department
        for (int j = 0;
             j < department.getTotalCourses();
             j++)
        {
            Course* course = department.getCourse(j);

            // Check that the course exists
            if (course != nullptr)
            {
                file << course->getCourseNumber() << ","
                     << course->getCourseName() << ","
                     << course->getSchedule() << ","
                     << course->getPrice() << endl;
            }
        }
    }

    return true;
}
