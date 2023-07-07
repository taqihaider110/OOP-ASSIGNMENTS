#include<iostream>
#include<string>
using namespace std;
class Student{
	int size;
	int *Roll;
	string *Name;
	double *Marks;
	public:
		Student(int s){
			size = s;
			Roll = new int[s];
			Name = new string[s];
			Marks = new double{s};
		}
		void getdata(){
			for(int i=0;i<size;i++){
				cout<<"Enter Roll for student "<<i+1<<" : "<<endl;
				cin>>Roll[i];
				cout<<"Enter Name for student "<<i+1<<" : "<<endl;
				cin>>Name[i];
				cout<<"Enter Marks for student "<<i+1<<" : "<<endl;
				cin>>Marks[i];
				cout<<endl;
			}
		}
		void Marksort(){
			int temproll,l=size-1;
			string tempname;
			double tempmarks;
			for(int i=0;i<size;i++){
				for(int j=0;j<l;j++){
					if(Marks[j]<Marks[j+1]){
						tempmarks=Marks[j];
						Marks[j]=Marks[j+1];
						Marks[j+1]=tempmarks;
						tempname=Name[j];
						Name[j]=Name[j+1];
						Name[j+1]=tempname;
						temproll=Roll[j];
						Roll[j]=Roll[j+1];
						Roll[j+1]=temproll;
					}
				}
				l--;
			}
		}
		void RollSearch(int roll){
			for(int i=0;i<size;i++){
				if(roll == Roll[i]){
					cout<<"Roll Number : "<<Roll[i]<<endl;
					cout<<"Name  : "<<Name[i]<<endl;
					cout<<"Marks : "<<Marks[i]<<endl;
				}
				cout<<endl;
			}
		}
		void NameSearch(string name){
			for(int i=0;i<size;i++){
				if(name == Name[i]){
					cout<<"Roll Number : "<<Roll[i]<<endl;
					cout<<"Name  : "<<Name[i]<<endl;
					cout<<"Marks : "<<Marks[i]<<endl;
				}
				cout<<endl;
			}
		}
		void ShowData(){
			for(int i=0;i<size;i++){
					cout<<"Roll Number : "<<Roll[i]<<endl;
					cout<<"Name  : "<<Name[i]<<endl;
					cout<<"Marks : "<<Marks[i]<<endl;
			}
			cout<<endl;
		}
};
int main(){
	int roll,students;
	string name;
	cout<<"Enter Number of Students: "<<endl;
	cin>>students;
	Student Object(students);
	Object.getdata();
	cout<<endl<<"Data before Sorting: "<<endl;
	Object.ShowData();
	cout<<endl<<"Data After Sorting by Marks: "<<endl;
	Object.ShowData();
	cout<<"Enter Roll No. to search: "<<endl;
	cin>>roll;
	Object.RollSearch(roll);
	cout<<endl<<endl;
	cout<<"Enter Name to search: "<<endl;
	cin>>name;
	Object.NameSearch(name);
	
}