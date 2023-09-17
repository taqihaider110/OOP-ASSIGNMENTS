#include <iostream>
using namespace std;

class StudentRecord {
    string studentId;
    int numCourses;
    float *creditHours;
    float totalCreditHours;
    float gradePoints;
    float totalGradePoints;
    char *grades;
    float CGPA;

public:
    StudentRecord(string id) : studentId(id), creditHours(nullptr), gradePoints(0.0), CGPA(0.0), totalCreditHours(0.0), totalGradePoints(0.0) {}

    void setData() {
        cout << "Enter Number Of Courses in this semester: ";
        cin >> numCourses;
        creditHours = new float[numCourses];
        grades = new char[numCourses];
        for (int i = 0; i < numCourses; i++) {
            cout << "Enter credit hours of the course: ";
            cin >> creditHours[i];

            cout << "Enter grade in the course: ";
            cin >> grades[i];

            totalCreditHours += creditHours[i];
        }
    }
    
    void updateRecords(float newCredits, float newGradePoints) {
        totalCreditHours += newCredits;
        totalGradePoints += newGradePoints;
    }

    void calculateCGPA() {
        for (int i = 0; i < numCourses; i++) {
            if (grades[i] == 'A' || grades[i] == 'a') {
                gradePoints = creditHours[i] * 4;
                totalGradePoints += gradePoints;
            } else if (grades[i] == 'B' || grades[i] == 'b') {
                gradePoints = creditHours[i] * 3;
                totalGradePoints += gradePoints;
            } else if (grades[i] == 'C' || grades[i] == 'c') {
                gradePoints = creditHours[i] * 2;
                totalGradePoints += gradePoints;
            } else if (grades[i] == 'D' || grades[i] == 'd') {
                gradePoints = creditHours[i] * 1;
                totalGradePoints += gradePoints;
            } else if (grades[i] == 'F' || grades[i] == 'f') {
                gradePoints = creditHours[i] * 0;
                totalGradePoints += gradePoints;
            } else {
                cout << "Invalid Input" << endl;
            }
        }

        CGPA = totalGradePoints / totalCreditHours;
        updateRecords(totalCreditHours, totalGradePoints);
    }

    void display() {
        cout << "Student Id: " << studentId << endl;
        cout << "Total credit hours: " << totalCreditHours << endl;
        cout << "Total grade points: " << totalGradePoints << endl;
        cout << "CGPA: " << CGPA << endl;
    }

    ~StudentRecord() {
        delete[] creditHours;
        delete[] grades;
    }
};

int main() {
    string studentId;
    cout << "Enter Student Id: ";
    cin >> studentId;
    StudentRecord student(studentId);
    student.setData();
    student.calculateCGPA();
    student.display();
    return 0;
}
