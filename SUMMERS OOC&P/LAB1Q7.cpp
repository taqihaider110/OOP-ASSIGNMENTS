#include<iostream>
using namespace std;
int main () {
char chTen;
char chUnit;
cout<<"Enter a two digit Number: ";
cin>>chTen>>chUnit;
int valueTen = chTen - '0';
int valueUnit = chUnit - '0';
cout<<"Numeric value is "<<valueTen*10 + valueUnit<<endl;
return 0;
}