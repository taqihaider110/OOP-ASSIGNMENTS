#include<iostream>
using namespace std ;
int main () {
float temp;
cout<<"Enter Temperature in Celsius : ";
cin>>temp;
temp = (9*temp)/5+32;
cout<<"Temperature in Fahrenheit is : "<< temp ;
return 0;
}