#include<iostream>
using namespace std;

int main(){
	int LastDigit = 4;   //CT-084
	int num,remain,digit,samecount=0;
	do{
		cout<<endl<<"Enter Number : "<<endl;
		cin>>num;
		if(num<0 || num>9999){
			cout<<"Invalid Input, Enter a Valid Integer.";
		}
	}while(num<0 || num>9999);
	cout<<endl;
	remain=num;
	while(remain>0){
		digit = remain%10;
		remain = remain/10;
		if(digit == LastDigit){
			samecount++;
		}
	}
	cout<<"In "<<num<<" there are "<<samecount<<" digits that are equal to your last digit "<<LastDigit<<endl;
	
}