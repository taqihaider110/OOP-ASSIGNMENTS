#include <iostream>
using namespace std;
struct student{
string first_name;
string last_name;
float score;
};
void display(student stud){
cout << "Student Fist name is " << stud.first_name << endl;
cout << "Student Last name is " << stud.last_name << endl;
cout << "Student Score is " << stud.score << endl;
}
int main()
{
student s1[2];
for (int i = 0; i < 2; i++)
{
cout << "Enter Student " << i + 1 << " First Name: ";
cin >> s1[i].first_name;
cout << "Enter Student " << i + 1 << " Last Name: ";
cin >> s1[i].last_name;
cout << "Enter Student " << i + 1 << " Score: ";
cin >> s1[i].score;
cout << endl;
}
for (int i = 0; i < 2; i++)
{
display(s1[i]);
cout << endl;
}
return 0;
}