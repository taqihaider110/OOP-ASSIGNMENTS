#include<iostream>
using namespace std ;
int main () {
float temp;
cout<<"Enter Temperature in Fahrenheit ";
cin>>temp;
temp = 5*(temp-32)/9;
cout<<"Temperature in celsius is : "<< temp ;
return 0;
}