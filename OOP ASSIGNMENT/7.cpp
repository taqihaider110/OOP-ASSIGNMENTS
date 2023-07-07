#include<iostream>
using namespace std;
int main(){
	int num,reverse=0,remain,digit;
	do{
		cout<<endl<<"Enter Number to check for palindrome : "<<endl;
		cin>>num;
		if(num<0 || num>99999){
			cout<<"Invalid Input, Enter a Valid Integer.";
		}
	}while(num<0 || num>99999);
	remain=num;
	while(remain>0){
		digit = remain%10;
		remain = remain/10;
		reverse = reverse*10+digit;
	}
	cout<<"Number : "<<num<<endl<<"Reverse : "<<reverse<<endl;
	if(num==reverse){
		cout<<"Number is a Palindrome!"<<endl;
	}
	else{
		cout<<"Number is NOT a Palindrome!"<<endl;
	}
}