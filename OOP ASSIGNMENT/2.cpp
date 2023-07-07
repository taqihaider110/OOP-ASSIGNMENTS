#include<iostream>
#include<cmath>
using namespace std;

class order{
	int DineIn=0,L_D_MN=0,Happyhour=0,cash=1;	//variables to store what option the user wants, L_D_MN is Lunch_Dinner_MidNight choice.
	double Bill,discount=0,discamount=0;
	public:
		void getdata(){
		
			char selection;	//declaration to use char inputs later.
			cout<<"Please Enter the cost of your bill:"<<endl;
			cin>>Bill;
			
			cout<<"\nWhen would you like to take your meal?\n\n(A) Lunch\t(B) Dinner\t(C) Midnight"<<endl;
			cin>>selection;
			while((selection!='a')&&(selection!='b')&&(selection!='c')&&(selection!='A')&&(selection!='B')&&(selection!='C')){ //loops until correct input is given
				cout<<"\nPlease Answer with the mentioned Characters..."<<endl<<"When would you like to take your meal?\n\n(A) Lunch\t(B) Dinner\t(C) Midnight"<<endl;
				cin>>selection;
			}
			if((selection=='a')||(selection=='A')){
				L_D_MN=1;
			}
			else if((selection=='b')||(selection=='B')){
				L_D_MN=2;
			}
			else if((selection=='c')||(selection=='C')){
				L_D_MN=3;
			}
			
			cout<<"\nWill you have this meal as:\n(A) Takeout\t(B) Dine-In"<<endl;
			cin>>selection;
			while((selection!='a')&&(selection!='b')&&(selection!='A')&&(selection!='B')){
				cout<<"\nPlease Answer with the mentioned Characters...\nWill you have this meal as:\n(A) Takeout\t(B) Dine-In"<<endl;
				cin>>selection;
			}
			if((selection=='a')||(selection=='A')){
				DineIn=0;
			}
			else if((selection=='b')||(selection=='B')){
				DineIn=1;
			}
			
			cout<<"\nWould you like to avail Special Happy Hour deal instead of the regular sale discount?\nA 50% Discount of up to RS.2500/- on your bill will be applied:\n(Y) YES\t(N) NO"<<endl;
			cin>>selection;
			while((selection!='Y')&&(selection!='N')&&(selection!='y')&&(selection!='n')){
				cout<<"\nPlease Answer with the mentioned Characters..."<<endl;
				cout<<"Would you like to avail Special Happy Hour deal instead of the regular sale discount?\nA 50% Discount of up to RS.2500/- on your bill will be applied:\n(Y) YES\t(N) NO"<<endl;
				cin>>selection;
			}	
			if((selection=='y')||(selection=='Y')){ //If happy hour deal is accepted, overwrites previously calculated discount with happy hour deal.
				discount=0.5;
				Happyhour=1;
			}
			cout<<"\nHow would you like to pay for your deal? (Cards will not get Discount!)?\n\n(A) Credit Card\t(B) Debit Card\t(C) Cash"<<endl;
			cin>>selection;
			while((selection!='a')&&(selection!='b')&&(selection!='c')&&(selection!='A')&&(selection!='B')&&(selection!='C')){
				cout<<"\nPlease Answer with the mentioned Characters..."<<endl;
				cout<<"How would you like to pay for your deal? (Cards will not get Discount!)?\n\n(A) Credit Card\t(B) Debit Card\t(C) Cash"<<endl;
				cin>>selection;
			}
			if((selection=='A')||(selection=='a')||(selection=='B')||(selection=='b')){
				cash=0;
				discount=0;
			}		
		}
		
		void calcdiscount(){
			if(Happyhour==0&&cash==1){
				if((L_D_MN==1)&&(DineIn==1)){	//Lunch and Dine In
						discount=0.25;
				}
				else if((L_D_MN==1)&&(DineIn==0)){ //Lunch and TakeAway
					discount=0.35;
				}
				else if((L_D_MN==2)&&(DineIn==1)){ //Dinner and Dine In
					discount=0.2;
				}
				else if((L_D_MN==2)&&(DineIn==0)){ //Dinner and TakeAway
					discount=0.25;
				}
				else if((L_D_MN==3)&&(DineIn==1)){ //Midnight and Dine In
					discount=0;
				}
				else if((L_D_MN==3)&&(DineIn==0)){ //Midnight and TakeAway
					discount=0.15;
				}
			}
			
			discamount=Bill*discount;
	
			if((Happyhour==1)&&(discamount>2500)){ //This Discount Amount limit only applies to Happy Hour Deal thus it is checked by Happy Hour == 1
				discamount=2500;
			}
			
			Bill=Bill-discamount;	
			
			cout<<"\nYour Meal will now cost : "<<Bill<<" as a discount of "<<discount*100<<" was applied according to your selection"<<endl;
		}
};

int main(){
	order Customer;
	Customer.getdata();
	Customer.calcdiscount();
}