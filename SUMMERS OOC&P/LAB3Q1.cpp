#include <iostream>
using namespace std;
class DM{
	double meters;
	double centimeters;
	public:
	DM():meters(0),centimeters(0){}
	void inputmeter(){
		cout<<"Enter distance in meters: "<<endl;
		cin>>meters;
		centimeters=meters*100;	// 1m ---> 100cm
		cout<<"Entered meters is: "<<meters<<endl;
	}
	void inputcentimeter(){
		cout<<"Enter distance in centimeters: "<<endl;
		cin>>centimeters;
		meters=centimeters/100;
		cout<<"Entered centimeters is: "<<centimeters<<endl;
	}
	void displaymeter_converter(){
		cout<<"Conversion of meter in centimeters is : "<<centimeters<<endl;
	}
	void displaycentimeter_converter(){
		cout<<"Conversion of centimeters in meters is: "<<meters<<endl;
	}
};
int main(){
	DM distance;
	distance.inputmeter();
	distance.displaymeter_converter();
	distance.inputcentimeter();
	distance.displaycentimeter_converter();
}