#include<iostream>
using namespace std;
void circle_Area(double *r,double pi){
	double Area;
	Area=pi * *r * *r;
	cout<<"The Area of a circle is: "<<Area<<endl;
}
int main(){
	const double pi=3.142;
	double r;
	cout<<"Enter the radius of a circle: ";
	cin>>r;
	circle_Area(&r,pi);
}