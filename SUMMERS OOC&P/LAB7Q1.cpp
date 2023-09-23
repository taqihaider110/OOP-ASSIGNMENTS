#include<iostream>
#include<cstring>
using namespace std;
const double pi=3.142;
class Circle{
	double radius;
	public:
	Circle(){radius=0.0;}
	Circle(double radius):radius(radius){}
	void set_radius(double radius){
		this->radius=radius;
	}
	double get_radius(){
		return radius;
	}
	double CalcArea(){
		return pi* radius *radius;
	}
	double CalcCircumference(){
		return 2*pi*radius;
	}
	string tostring(){
		return "Circle with Radius: "+to_string(radius);
	}
	bool equals(Circle &c){
		return this->radius==c.radius;
	}
};
class Cylinder:public Circle{
	double height;
	public:
	Cylinder(){
		height=0.0;
	}
	Cylinder(double radius,double height):Circle(radius),height(height){}
	void set_height(double height){
		this->height=height;
	}
	double get_height(){
		return height;
	}
	double CalcArea(){
		double basearea=Circle::CalcArea();
		double Lateralarea= 2*pi* get_radius()*height;
		return 2*basearea*Lateralarea;
	}
	double CalcVolume(){
		return Circle::CalcArea()*height;
	}
	string tostring(){
		return "Cylinder with Radius: "+to_string(get_radius())+" Cylinder with Height: "+to_string(height);
	}
	bool equals(Cylinder &c){
		return Circle::equals(c)&&this->height==c.height;
	}
};
int main(){
	Circle circle1(5.0);
	Circle circle2(5.0);
	Cylinder cylinder1(3.0,7.0);
	Cylinder cylinder2(7.0,3.0);
	
	cout<<"The String is:"<<circle1.tostring()<<endl;
	cout<<"The Circle Area is: "<<circle1.CalcArea()<<endl;
	cout<<"The Circle Circumference is: "<<circle1.CalcCircumference()<<endl;
	cout<<"The Circle is equal or not: "<<circle1.equals(circle2)<<endl;
	
	cout<<"The String is:"<<cylinder1.tostring()<<endl;
	cout<<"The Circle Area is: "<<cylinder1.CalcArea()<<endl;
	cout<<"The Circle Circumference is: "<<cylinder1.CalcCircumference()<<endl;
	cout<<"The Circle is equal or not: "<<cylinder1.equals(cylinder2)<<endl;
}