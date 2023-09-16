#include<iostream>
using namespace std;
class calculator{
	double x ,y;
	public:
	calculator():x(0.0),y(0.0){}
	void add(double *x,double *y){
		cout<<"The Addition of "<<*x<<" + "<<*y<<" is: "<<*x + *y<<endl;
	}	
	void sub(double *x,double *y){
		cout<<"The Subtraction of "<<*x<<" - "<<*y<<" is: "<<*x - *y<<endl;
	}	
	void mult(double *x,double *y){
		cout<<"The Multiplication of "<<*x<<" * "<<*y<<" is: "<<*x * *y<<endl;
	}	
	void div(double *x,double *y){
		cout<<"The Divison of "<<*x<<" / "<<*y<<" is: "<<*x / *y<<endl;
	}	
};
int main(){
	calculator c;
	double x,y;
	cout<<"Enter the First number:";
	cin>>x;
	cout<<"Enter the Second number:";
	cin>>y;
	c.add(&x,&y);
	c.sub(&x,&y);
	c.mult(&x,&y);
	c.div(&x,&y);
}