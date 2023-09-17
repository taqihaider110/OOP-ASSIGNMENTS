#include <iostream>
using namespace std;

class person
{
private:
    string name;
    int age;
    string gender;

public:
    person(string x, int y, string z) : name(x), age(y), gender(z) {}
    virtual void showdata()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class student : public person
{
    string studentid;

public:
    student(string id, string x, int y, string z) : person(x, y, z), studentid(id)
    {
    }
    void display()
    {
        cout << "NED Student Record " << endl;
        cout << endl;
    }

    void showdata() override
    {

        cout << "Student ID: " << studentid << endl;
        person::showdata();
    }
};

class graduate_student : public student
{
    int year_of_graduate;
    string degree_name;

public:
    graduate_student(string d, int v, string id, string x, int y, string z) : student(id, x, y, z), degree_name(d), year_of_graduate(v)
    {}

    void showdata() override
    {
        cout << "NED Alumni Record" << endl;
        cout << endl;
        student::showdata();
        cout << "Student Graduated in year " << year_of_graduate << endl;
        cout << "Bachelors of " << degree_name << endl;
    }
};

int main()
{
    cout << endl;
    student s1("CT-22099", "Rafay", 20, "Male");
    s1.display();
    s1.showdata();
    cout<<endl;
    graduate_student g1("Computer Science", 2019, "CT-15082", "Haris", 26, "Male");
    g1.showdata();
    cout << endl;
    return 0;
}
