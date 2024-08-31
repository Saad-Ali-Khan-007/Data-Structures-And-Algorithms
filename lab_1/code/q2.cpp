#include <iostream>
using namespace std;

int lab1()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 01" << endl;
    return 0;
}

double calculateGPA(double grades[], int numberOfGrades, int creditHours)
{
    double totalPoints = 0;
    for (int i = 0; i < numberOfGrades; i++)
    {
        totalPoints += grades[i] * creditHours;
    }
    return totalPoints / (numberOfGrades * creditHours);
}

int q2()
{
    int const numStudents = 5;
    int const numCourses = 5;
    double sub_gpa[numStudents][numCourses] = {
        {3.66, 3.33, 4.0, 3.0, 2.66},
        {3.33, 3.0, 3.66, 3.0, -1},
        {4.0, 3.66, 2.66, -1, -1},
        {2.66, 2.33, 4.0, -1, -1},
        {3.33, 3.66, 4.0, 3.0, 3.33}};

    string students[numStudents] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};
    int credithour = 3;
    for (int i = 0; i < numStudents; i++)
    {
        int validGradeCount = 0;
        for (int j = 0; j < numCourses; j++)
        {
            if (sub_gpa[i][j] != -1)
            {
                validGradeCount++;
            }
        }

        double gpa = calculateGPA(sub_gpa[i], validGradeCount, credithour);
        cout << "GPA of " << students[i] << ": " << gpa << endl;
    }

    return 0;
}

int main()
{
    lab1();
    q2();
    return 0;
}