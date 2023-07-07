#include<iostream>
#include<cmath>
using namespace std;

class encrypt{
	int message,encode;
	public:
		encrypt():message(0),encode(0){}
		encrypt(int m){message=m;}
		void get(){
			cout<<"Enter message to be encoded: "<<endl;
			cin>>message;
		}
		void show(){
			cout<<"Message : "<<message<<endl<<"Encoded : "<<encode<<endl;
		}
		void encoder(){
			int checks[10]={0,0,0,0,0,0,0,0,0,0}; //Array to count number of occurences of a digit, i.e. checks[1]==0 means '1' appeared 0 times 
    		int count=0;
			count=(message==0)?1:log10(message)+1;
			int rem,ld,highest=-1,lowest=10;
			if(count<2){ //Checks if number was a single digit input, as encodinging it wont give unique two digits output from input.
				cout<<"Number too small to actually encode as highest lowest will be same after encoding"<<endl;
				return;
			}
			else if(message<0){ //converts num from negative to positive if someone inputs negative number. Even though negative numbers dont mess up the encoding, it is just in case if another compiler does not interact the same way.
				cout<<"Negative will be converted to positive to encode"<<endl;
				message = -message;
			}
			rem=message;
			for(int i=0;i<count;i++){ //looping through the whole number
				ld=rem%10;
				if(ld==0){
					cout<<"Input Does NOT follow question's rule of being only in 1-9 range"<<endl;	// this gives error if it encounters a zero in the number as tasked by question's rule.
					return;
				}
				rem=rem/10;
				if(ld>highest){highest=ld;}   //comparing with highest and then with lowest
				if(ld<lowest){lowest=ld;}
		
				checks[ld]++;	//increments array element of index [Last Digit] to later check for duplicates.
		
				if(checks[ld]>1){
				cout<<"Duplicate Numbers are present in Input value.\nQuestion's rule of numbers appearing once at most was broken."<<endl; // this gives error if any number was used more than once
				return;
				}
			}
			(count%2==0)?encode=(highest*10)+lowest:encode=(lowest*10)+highest;
		}
			
};
int main(){
	encrypt number;
	number.get();
	number.encoder();
	number.show();
}