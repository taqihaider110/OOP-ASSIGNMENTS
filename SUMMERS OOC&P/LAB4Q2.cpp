#include<iostream>
using namespace std;
void sum(int *arr1,int *arr2,int *sum,int size){
	for(int i=0;i<size;i++){
		sum[i]=arr1[i]+arr2[i];
	}
	cout<<"The sum of arr is:"<<endl;
	cout<<"{ ";
	for(int i=0;i<size;i++){
		cout<<sum[i]<<" ";
	}
	cout<<"}";
}
int main(){
	int size;
	cout<<"Enter the size of both the array at a time:";
	cin>>size;
	int result[size];
	int arr1[size], arr2[size];
	cout<<"Enter "<<size<<" elements of arr1:"<<endl;
	for(int i=0;i<size;i++){
		cin>>arr1[i];
	}
	cout<<"Enter "<<size<<" elements of arr2:"<<endl;
	for(int i=0;i<size;i++){
		cin>>arr2[i];
	}
	sum(arr1,arr2,result,size);
}