#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
    string gender;

public:
    Person(string n, int a, string g) : name(n), age(a), gender(g) {}
    virtual void displayData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Student : public Person {
private:
    string studentId;

public:
    Student(string id, string n, int a, string g) : Person(n, a, g), studentId(id) {}
    void displayStudentRecord() {
        cout << "NED Student Record " << endl;
        cout << endl;
    }

    void displayData() override {
        cout << "Student ID: " << studentId << endl;
        Person::displayData();
    }
};

class GraduateStudent : public Student {
private:
    int graduationYear;
    string degreeName;

public:
    GraduateStudent(string degree, int year, string id, string n, int a, string g) : Student(id, n, a, g), degreeName(degree), graduationYear(year) {}

    void displayData() override {
        cout << "NED Alumni Record" << endl;
        cout << endl;
        Student::displayData();
        cout << "Student Graduated in year " << graduationYear << endl;
        cout << "Bachelors of " << degreeName << endl;
    }
};

int main() {
    cout << endl;
    Student student1("CT-22092", "Taqi", 20, "Male");
    student1.displayStudentRecord();
    student1.displayData();
    cout << endl;
    GraduateStudent gradStudent1("Computer Science", 2019, "CT-19021", "Abid", 23, "Male");
    gradStudent1.displayData();
    cout << endl;
    return 0;
}
