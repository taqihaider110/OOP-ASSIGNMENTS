#include<iostream>
using namespace std ;
void calculation(int x, int y){
int sum;
float average;
sum = x + y;
average = sum/2;
cout<<"Sum is "<< sum << endl;
cout<<"Average is "<< average << endl;
}
int main(){
int num1 , num2;
cout<<"Enter First Number : ";
cin>>num1;
cout<<"Enter Second Number : ";
cin>>num2;
calculation( num1 , num2 );
return 0;
}