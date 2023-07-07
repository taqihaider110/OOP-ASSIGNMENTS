#include<iostream>
#include <stdlib.h>
using namespace std;

class time{
	int sec,min,hrs;
	public:
		time():sec(0),min(0),hrs(0){}
		time(int h,int m,int s){
			while(s>=60){
				s-=60;
				m++;
			}
			while(m>=60){
				m-=60;
				h++;
			}
			while(h>=12){
				h-=12;
			}
			hrs=h;min=m;sec=s;
		}
		time difference(time obj1){
			int A=(hrs*3600)+(min*60)+sec;int B=(obj1.hrs*3600)+(obj1.min*60)+obj1.sec;int C;
			if(A>B){
				C=A-B;
			}
			else{
				C=B-A;
			}
			time diff(0,0,C);
			return diff;
		}
		void get(){
			cout<<"Enter hours (In Analog Clock Format):"<<endl;
			cin>>hrs;
			if(hrs<0||hrs>12){
				cout<<"Invalid Input, not in analog clock format."<<endl;exit(0);
			}
			cout<<"Enter minutes:"<<endl;
			cin>>min;
			cout<<"Enter seconds:"<<endl;
			cin>>sec;
			if(min<0||min>12){
				cout<<"Invalid Input, not in analog clock format."<<endl;exit(0);
			}
			if(min==12){min=0;}
			if(sec<0||sec>12){
				cout<<"Invalid Input, not in analog clock format."<<endl;exit(0);
			}
			if(sec==12){sec=0;}
		}
		void show(){
			cout<<"Time :  "<<hrs<<":"<<min<<":"<<sec<<endl;
		}
};

int main(){
	time t1;
	t1.get();
	t1.show();
	time t2;
	t2.get();
	t2.show();
	time t3 = t1.difference(t2);
	t3.show();
}