#include<iostream> //1 extra iteration that shows a value in 3.14 form
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	int Term=1;
	double PI_approx=4;
	cout<<"TERM "<<Term<<" || PI = "<<PI_approx<<endl;
	while(PI_approx<3.14 || PI_approx>=3.15){
		PI_approx = PI_approx + (pow(-1,Term)*4)/(2*Term+1);
		Term++;
		cout<<"TERM "<<Term<<" || PI = "<<PI_approx<<endl;
	}
	cout<<"It took "<<Term<<" Terms to reach a value of 3.14 using the series"<<endl;
}