#include<iostream>
#include<math.h>
using namespace std;
void distance_formula (int x1, int y1, int x2, int y2){ 
    float distance;
    distance=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    cout<<"The value of distance formula is: "<<distance<<endl;
}
int main(){
int x1,y1,x2,y2;
cout<<"Enter the value of First Coordinate:";
cin>>x1>>y1;
cout<<"(X1,Y1)=("<<x1<<","<<y1<<")"<<endl;
cout<<"Enter the value of Second Coordinate:";
cin>>x2>>y2;
cout<<"(X2,Y2)=("<<x2<<","<<y2<<")"<<endl;
distance_formula (x1,y1,x2,y2);
}