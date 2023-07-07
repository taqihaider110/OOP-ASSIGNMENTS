#include<iostream>
#include<string>
using namespace std;
int main(){
	int Qnum,Students,invalid=0;
	char temp1,temp2;
	cout<<"Enter number of Students :"<<endl;
	cin>>Students;
	cout<<"Enter number of Questions :"<<endl;
	cin>>Qnum;
	string Answers,temp,ID[Students];
	char StdAnswers[Students][Qnum]; //ASSUMING STUDENT ID IS 8 Characters
	do{
		invalid=0;
		cout<<"Enter Answers to the test:"<<endl;
		getline(cin, Answers);
		if(Answers.size()>Qnum || Answers.size()<Qnum){
			cout<<"Please enter same number of answers as questions! Try again"<<endl;
		}
		for(int i=0;i<Answers.size();i++){
			temp1=Answers[i];
			if(!((temp1=='F')||(temp1=='f')||(temp1=='T')||(temp1=='t')||(temp1==' '))){
				invalid=1;
			}
		}
		if(invalid==1){
			cout<<"Answers can only be given in T/t for TRUE or F/f for FALSE, please try again"<<endl;
		}
	}while((Answers.size()>Qnum || Answers.size()<Qnum)||invalid==1);
	for(int j=0;j<Students;j++){
		do{
			invalid=0;
			fflush(stdin);
			cout<<"Please enter ID and Answers of Student #"<<j+1<<" : "<<endl;
			cout<<"Format (8 character ID) (Answers)"<<endl<<"ABC12345 TTF...(same amount as questions)"<<endl;
			cin>>ID[j];
			cin>>StdAnswers[j];
			for(int i=0;i<Qnum;i++){
				temp1 = StdAnswers[j][i];
				if(!((temp1=='F')||(temp1=='f')||(temp1=='T')||(temp1=='t')||(temp1==' '))){
					invalid=1;
				}
			}
			if(invalid==1){
				cout<<"Invalid Input! please enter again according to the format, in T/t or F/f only."<<endl;
			}
		}while(invalid==1);
		fflush(stdin);
	}
	int score=0;
	char grade;
	float percent;
	cout<<endl<<endl;
	
	for(int i=0;i<Students;i++){
		score=0;
		for(int j=0;j<Qnum;j++){
			temp1=Answers[j];
			temp2=StdAnswers[i][j];
			if(temp1==temp2){
				score+=2;
			}
			else if(temp1!=temp2 && temp2!=' '){
				score--;
			}	
		}
		percent = 100*score/(Qnum*2);
		if(percent<60){
			grade='F';
		}
		else if(percent<60){
			grade='E';
		}
		else if(percent<70){
			grade='D';
		}
		else if(percent<80){
			grade='C';
		}
		else if(percent<90){
			grade='B';
		}
		else{
			grade='A';
		}
		cout<<ID[i]<<" ";
		for(int l=0;l<Qnum;l++){
			cout<<StdAnswers[i][l];
		}
		cout<<" "<<score<<" "<<grade<<endl;
	}
}