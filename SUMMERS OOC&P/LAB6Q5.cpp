#include<iostream>
using namespace std ;

class student_record
{
    string student_name;
    string student_Id;
    int no_of_courses;
    float *credit_hours;
    float total_credit_hours;
    float grade_points;
    float total_gradepoint;
    char *grade;
    float Cgpa;

public:
    student_record(string x, string y) : student_name(x), student_Id(y), credit_hours(nullptr), grade_points(0.0), Cgpa(0.0), total_credit_hours(0.0), total_gradepoint(0.0) {
        cout<<student_name<<"'s GPA is:  "<<Cgpa<<endl;
        cout<<endl;
    }

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
        cout<<"\n"<<endl;
    }

    void display()
    {
        cout << student_name <<"'s 1st Semester grade point and gpa is: "<< total_gradepoint<<", "<<total_credit_hours<< endl;
        cout<< "Student Id: "<<student_Id<<"\tCredit Hours: "<<total_credit_hours<<"\tGrade Points: "<<total_gradepoint<<"\tGPA: "<<Cgpa<<endl;

    }
     ~student_record()
    {
        delete[] credit_hours;
        delete[] grade;
    }
};

int main()
{
    string studentName, studentId;
    cout << "Enter Student Name: ";
    getline (cin, studentName);
    cout << "Enter Student Id: ";
    getline (cin, studentId);
    student_record s1( studentName, studentId);
    s1.setData();
    s1.grading_system();
    s1.display();
    return 0;
}
