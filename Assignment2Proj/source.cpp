#define PRE_RELEASE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
    string firstName;
    string lastName;
    string email;
};

int main()
{
    // Display which version is running
#ifdef PRE_RELEASE
    cout << "Running Pre-Release Version" << endl;
#else
    cout << "Running Standard Version" << endl;
#endif

    // Create a vector to store all students
    vector<STUDENT_DATA> students;

    // Choose which file to open
#ifdef PRE_RELEASE
    ifstream inputFile("StudentData_Emails.txt");
#else
    ifstream inputFile("StudentData.txt");
#endif

    string line;

    // Read the file one line at a time
    while (getline(inputFile, line))
    {
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);

        STUDENT_DATA student;

        // Get first name
        student.firstName = line.substr(0, firstComma);

#ifdef PRE_RELEASE
        // Pre-Release file has first name, last name, and email
        student.lastName = line.substr(
            firstComma + 1,
            secondComma - firstComma - 1
        );

        student.email = line.substr(secondComma + 1);
#else
        // Standard file only has first name and last name
        student.lastName = line.substr(firstComma + 1);
#endif

        // Add student to vector
        students.push_back(student);
    }

    // Only print student information in Debug mode
#ifdef _DEBUG

    for (const STUDENT_DATA& student : students)
    {
        cout << student.firstName << " " << student.lastName;

#ifdef PRE_RELEASE
        cout << " - " << student.email;
#endif

        cout << endl;
    }

#endif

    return 1;
}