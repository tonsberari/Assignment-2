#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
    string firstName;
    string lastName;
};

int main()
{
    // Create a vector to store all students
    vector<STUDENT_DATA> students;

    // Open the student data file
    ifstream inputFile("StudentData.txt");

    string line;

    // Read the file one line at a time
    while (getline(inputFile, line))
    {
        // Find the comma between first and last name
        size_t commaPosition = line.find(',');

        // Create a student
        STUDENT_DATA student;

        // Separate first name and last name
        student.firstName = line.substr(0, commaPosition);
        student.lastName = line.substr(commaPosition + 1);

        // Add the student to the vector
        students.push_back(student);
    }

    return 1;
}