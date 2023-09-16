#include<iostream>
using namespace std;
void table(int *x){
	for(int i=1;i<=10;i++){
		cout<<*x<<" * "<<i<<" = "<<*x * i<<endl;
	}
}
int main(){
	int x;
	cout<<"Enter the no. to find its table:";
	cin>>x;
	table(&x);
}