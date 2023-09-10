#include<iostream>
using namespace std;
void add(double *x,double *y){
    cout<<"The Sum of "<<*x<<" + "<<*y<<" = "<<*x+*y<<endl; 
}
void sub(double *x,double *y){
    cout<<"The Subtraction of "<<*x<<" - "<<*y<<" = "<<*x-*y<<endl; 
}
void div(double *x,double *y){
    cout<<"The Division of "<<*x<<" / "<<*y<<" = "<<*x / *y<<endl; 
}
void mult(double *x,double *y){
    cout<<"The Multiplication of "<<*x<<" x "<<*y<<" = "<<*x * *y<<endl; 
}
int main(){
double x,y;
cout<<"Enter First Operand:"<<endl;
cin>>x;
cout<<"Enter Second Operand:"<<endl;
cin>>y;
add(&x,&y);
sub(&x,&y);
div(&x,&y);
mult(&x,&y);
}