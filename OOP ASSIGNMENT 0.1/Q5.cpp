#include<iostream>
#include<cmath>
using namespace std;

class data{
		int size;
		double *operands;
		char *sign;
	public:
		data(int s){
			size = s;
			operands = new double[s];
			sign= new char[s-1];
		}
		void getequation(){
			cout<<endl<<endl<<"Enter Operand 1: "<<endl;
			cin>>operands[0];
			for(int i = 1 ; i<size;i++){
				cout<<"Enter Operator "<<i<<" : "<<endl;
				cin>>sign[i-1];
				cout<<"Enter Operand "<<i+1<<" : "<<endl;
				cin>>operands[i];
			}
		}
		void display(){
			cout<<operands[0];
			for(int i=0;i<size-1;i++){
				cout<<" "<<sign[i]<<" "<<operands[i+1];
			}
		}
		void solveequation(){
			cout<<operands[0];
			for(int i=0;i<size-1;i++){
				cout<<" "<<sign[i]<<" "<<operands[i+1];
				if(sign[i]=='+'){
					operands[i+1]=operands[i]+operands[i+1];
				}
				else if(sign[i]=='-'){
					operands[i+1]=operands[i]-operands[i+1];
				}
				else if(sign[i]=='*'){
					operands[i+1]=operands[i]*operands[i+1];
				}
				else if(sign[i]=='/'){
					operands[i+1]=operands[i]/operands[i+1];
				} 
			}
			cout<<" = "<<operands[size-1];
		}
		
};

class vector{
	int size;
	double *members;
	public:
		vector(int s){
			size=s;
			members = new double[s];
		}
		void getvector(){
			for(int i=0;i<size;i++){
				cout<<"Input member "<<i+1<<" : "<<endl;
				cin>>members[i];
			}
		}
		void showvector(){
			cout<<"[ ";
			for(int i=0;i<size-1;i++){
				cout<<members[i]<<" , ";
			}
			cout<<members[size-1]<<" ]"<<endl;
		}
		double dot(vector obj){
			double value=0;
			for(int i=0;i<size;i++){
				value += (members[i]*obj.members[i]);
			}
			cout<<"Dot Product is : "<<value;
			return value;
		}
};

int main(){
	char opt;
	int n;
	cout<<"What do you want to do?"<<endl<<"(A) Solve an Equation of N operands \t (B) Dot Product of 2 vectors "<<endl;
	cin>>opt;
	fflush(stdin);
	if(opt=='A'||opt=='a'){
		cout<<"How many operands does your equation have : "<<endl;
		cin>>n;
		data obj(n);
		obj.getequation();
		cout<<endl<<"Equation input into program : "<<endl;
		obj.display();
		cout<<endl<<"Solution : "<<endl;
		obj.solveequation();
	}
	else if(opt=='b'||opt=='B'){
		cout<<"How many members do your vectors have : "<<endl;
		cin>>n;
		vector A(n);
		vector B(n);
		cout<<endl<<"Enter Members for Vector A :"<<endl;
		A.getvector();
		cout<<endl<<"A = ";
		A.showvector();
		cout<<"Enter Members for Vector B :"<<endl;
		B.getvector();
		cout<<endl<<"B = ";
		B.showvector();
		A.dot(B);
	}
	else{
		return 0;
	}
}
          
         