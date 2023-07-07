#include<iostream>
#include <cmath>
using namespace std;
class num{
	double number;
	public:
		num(): number(0){}
		num(double n){number = n;}
		void getnum(){
			double n;
			cout<<"Enter number: "<<endl;
			cin>>n;
			number = n;
		}
		void shownum(){
			cout<<number<<endl;
		}
		void getratio(num obj){
			double A,B,ratio1=0,ratio2=0;
			if(number>obj.number){
				A=number;B=obj.number;	
			}
			else{
				A=obj.number;B=number;
			}
			ratio1=(A+B)/A;
			ratio1=dot3place(ratio1);
			ratio2=A/B;
			ratio2=dot3place(ratio2);
			if(ratio1==ratio2){
				cout<< A << " and " << B << " Are in Golden Ratio"<<endl;
			}
			else{
				cout<< A << " and " << B << " Are NOT in Golden Ratio"<<endl;
			}
		}
		double dot3place(double ratio){
			ratio=ratio*1000;
			ratio=round(ratio);
			ratio=ratio/1000;
			return ratio;
		}
};
int main(){
	num n1,n2;
	n1.getnum();
	n2.getnum();
	n1.getratio(n2);
}