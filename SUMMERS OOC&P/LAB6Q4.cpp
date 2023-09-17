#include <iostream>
using namespace std;

class student_record
{
    string studentId;
    int no_of_courses;
    float *credit_hours;
    float total_credit_hours;
    float grade_points;
    float total_gradepoint;
    char *grade;
    float Cgpa;

public:
    student_record(string x) : studentId(x), credit_hours(nullptr), grade_points(0.0), Cgpa(0.0), total_credit_hours(0.0), total_gradepoint(0.0) {}

    void setData()
    {
        cout << "Enter Number Of Courses in this semester: ";
        cin >> no_of_courses;
        credit_hours = new float[no_of_courses];
        grade = new char[no_of_courses];
        for (int i = 0; i < no_of_courses; i++)
        {
            cout << "Enter credit hours of the course: ";
            cin >> credit_hours[i];

            cout << "Enter grade in the course: ";
            cin >> grade[i];

            total_credit_hours = total_credit_hours + credit_hours[i];
        }
    }
    void updateRecords(float newCredits, float newGradePoints)
    {
        total_credit_hours += newCredits;
        total_gradepoint += newGradePoints;
    }

    void grading_system()
    {
        for (int i = 0; i < no_of_courses; i++)
        {
            if (grade[i] == 'a' || grade[i] == 'A')
            {
                grade_points = credit_hours[i] * 4;
                total_gradepoint = total_gradepoint + grade_points;
            }
            else if (grade[i] == 'b' || grade[i] == 'B')
            {
                grade_points = credit_hours[i] * 3;
                total_gradepoint = total_gradepoint + grade_points;
            }
            else if (grade[i] == 'c' || grade[i] == 'C')
            {
                grade_points = credit_hours[i] * 2;
                total_gradepoint = total_gradepoint + grade_points;
            }
            else if (grade[i] == 'd' || grade[i] == 'D')
            {
                grade_points = credit_hours[i] * 1;
                total_gradepoint = total_gradepoint + grade_points;
            }
            else if (grade[i] == 'f' || grade[i] == 'F')
            {
                grade_points = credit_hours[i] * 0;
                total_gradepoint = total_gradepoint + grade_points;
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }

        Cgpa = total_gradepoint / total_credit_hours;
        updateRecords(total_credit_hours, total_gradepoint);
    }

    void display()
    {
        cout << "Studen Id: " << studentId << endl;
        cout << "Total credit hours: " << total_credit_hours << endl;
        cout << "Total grade points: " << total_gradepoint << endl;
        cout << "CGPA: " << Cgpa << endl;
    }
~student_record()
    {
        delete[] credit_hours;
        delete[] grade;
    }

};

int main()
{
    string student_id;
    cout << "Enter Student Id: ";
    cin >> student_id;
    student_record s1(student_id);
    s1.setData();
    s1.grading_system();
    s1.display();
    return 0;
}
