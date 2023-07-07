#include<iostream>
using namespace std;
//Question 8
int main(){
	int x=10,y=10,SumOfNumbers,firstNumber=2,secondNumber=3,number=5,largest=2;  //initializations for variables used in question just so this code can work
	//a
	int value;
	cin>>value;
	//b
	cout<<"The product of "<<x<<" and "<<y<<" is "<<x*y<<endl;
	//c
	SumOfNumbers = firstNumber + secondNumber;
	//d
	if(number>=largest){
		largest = number;
	}
	//e
		/*program to determine he largest of three integers*/
	//f
	int anInteger;
	cin>>anInteger;
	//g
	cout<<"Remainder of "<<x<<" divided by "<<y<<" is "<<x%y<<endl;
	//h
	if(x==y){
		cout<<x<<" is equal to "<<y<<endl;
	}
	//i
	cout<<"The sum is "<<x+y<<endl;
	//j
	cout<<"The value you entered is: "<<value<<endl;	
	//k
	int X=1,total=0;
	while(X<=10){
		total+=X;
		++X;
	}
	//l
	while(X<=100){
		total+=X;
		++X;
	}
	//m
	while(y>0){ 
		cout<<y<<endl;
		--y;
	}
	//n
	for(x=100;x>=1;--x){
		cout<<x<<endl;
	}
	//o
	switch(value%2){
		case 0:
			cout<<"Even Integer"<<endl;
			break;
		case 1:
			cout<<"Odd Integer"<<endl;
	}
	//p
	int intVAL;
	char charVAL;
	cin>>intVAL;
	cin>>charVAL;
	cout<<"Integer : "<<intVAL<<" Character :"<<charVAL<<endl;
	//q
	double p;
	for(p=0.000001;p==0.0001;p+=0.000001){
		cout<<p<<endl;
	}
	//r
	for(x=999;x>=1;x-=2){
		cout<<x;
	}
	//s
	int counter=2;
	do{
		if(counter%2==0){
			cout<<counter<<endl;
		}
		counter+=2;
	}while(counter<100);
	//t
	total=0;
	for(x=100;x<=150;x++){
		total+=x;
	}
}