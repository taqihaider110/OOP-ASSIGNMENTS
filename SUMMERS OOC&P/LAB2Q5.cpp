#include <iostream>
#include <string>
using namespace std;
struct address
{
    string house_no;
    string city;
    int pin_code;
};
struct employee
{
    string empId;
    string name;
    int salary;
    address a1;
};
void display(employee e)
{
    cout << "Employee Name is: " << e.name << endl;
    cout << "Employee ID is: " << e.empId << endl;
    cout << "Employee Salary is: Rs " << e.salary << endl;
    cout << "Employee Address is: " << e.a1.house_no << ", " << e.a1.city << endl;
    cout << "Employee Pin Code is: " << e.a1.pin_code << endl;
}
int main()
{
    employee e[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter Employee " << i + 1 << " ID: ";
        cin >> e[i].empId;
        cout << "Enter Employee " << i + 1 << " Name: ";
        cin >> e[i].name;
        cout << "Enter Employee " << i + 1 << " Salary: ";
        cin >> e[i].salary;
        cout << "Enter Employee " << i + 1 << " House Number: ";
        cin.ignore();
        getline(cin, e[i].a1.house_no);
        cout << "Enter Employee " << i + 1 << " City: ";
        cin >> e[i].a1.city;
        cout << "Enter Employee " << i + 1 << " Pin Code: ";
        cin >> e[i].a1.pin_code;
        cout << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "Details Of Employee " << i + 1 << endl;
        display(e[i]);
        cout << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        if (e[i].salary < 50000)
        {
            cout << e[i].name << "'s salary has been increased as it was less than Rs 50,000 " << endl;
        }
    }
    return 0;
}