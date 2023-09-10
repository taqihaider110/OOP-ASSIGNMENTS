#include<iostream>
using namespace std;
int main(){
int time_seconds;
int hrs, min, sec;
cout<<"Enter Time in Seconds: ";
cin>>time_seconds;
hrs = time_seconds /3600;
cout<<"Time in Hours is "<< hrs<<endl;
min = (time_seconds % 3600)/60;
cout<<"Time in Minutes is "<< min <<endl;
sec = time_seconds % 60;
cout<<"Time in Seconds is "<< sec <<endl;
}