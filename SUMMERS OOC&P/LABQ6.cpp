#include<iostream>
using namespace std;
int main () {
int num;
cout<<"Enter Two digit Number: ";
cin>>num;
int unitNum = num % 10;
int tenthNum = num /10;
cout<<"Reversed Number is "<< unitNum*10 + tenthNum<<endl;
return 0;
}