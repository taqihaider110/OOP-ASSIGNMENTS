#include<iostream>
using namespace std;
int main(){
int amount;
cout<<"Enter Amount In Rupees: ";
cin>>amount;
cout<<"1000's in the Given amount is: "<< amount/1000<<endl;
cout<<"500's in the Given amount is: "<< (amount%1000)/500<<endl;
cout<<"100's in the Given amount is: "<< ((amount%1000)%500)/100<<endl;
cout<<"50's in the Given amount is: "<< (((amount%1000)%500)%100)/50<<endl;
cout<<"10's in the Given amount is: "<<
((((amount%1000)%500)%100)%50)/10<<endl;
cout<<"5's in the Given amount is: "<<
(((((amount%1000)%500)%100)%50)%10)/5<<endl;
cout<<"2's in the Given amount is: "<<
((((((amount%1000)%500)%100)%50)%10)%5)/2<<endl;
cout<<"1's in the Given amount is: "<<
(((((((amount%1000)%500)%100)%50)%10)%5)%2)/1<<endl;
}