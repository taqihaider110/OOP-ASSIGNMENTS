#include<iostream>
using namespace std;

void factorial(int *x){
	int result=1;
	for(int i=1;i<=*x;i++){
		result *=i;
	}
	cout<<"The Factorial of "<<*x<<" is : "<<result<<endl;
}
int main(){
	int x;
	cout<<"Enter the value to find its factorial: ";
	cin>>x;
	factorial(&x);
	return 0;
}