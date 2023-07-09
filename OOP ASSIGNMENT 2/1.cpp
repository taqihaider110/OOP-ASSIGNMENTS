#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Book{
	private:
		string bookname,author;
	public:
		Book(string b,string a):bookname(b),author(a){}
		void setbookname(string n){bookname=n;}
		void setauthor(string a){author=a;}
		string getbookname(){return bookname;}
		string getauthor(){return author;}
		virtual void takebook()=0;
		virtual void display()=0;
};

class Textbook:public Book{
	private:
		bool Available=true;
	public:
		Textbook(string n,string a):Book(n,a){}
		void takebook(){
			Available=false;
		}
		void display(){
			cout<<getbookname()<<endl<<getauthor()<<endl;
		}
};

class Novel:public Book{
	private:
		string genre;
	public:
		Novel(string n,string g,string a):Book(n,a),genre(g){}
		void takebook(){
			cout<<genre<<" Novel was bought"<<endl;
		}
		void display(){
			cout<<"Book Name:"<<getbookname()<<endl<<"Genre:"<<genre<<endl<<"Author:"<<getauthor()<<endl;
		}
};

class LibraryMember{
	private:
		string name;
		time_t datejoined;
	public:	
		LibraryMember(string n):name(n),datejoined(time(0)){}
		void setname(string n){name=n;}
		void setdate(){time(0);}
		string getname(){return name;}
		time_t getdate(){return datejoined;}
		virtual void display()=0;
};

class Student:public LibraryMember{
	private:
		int RollNo;
	public:
		Student(string n,int r):LibraryMember(n),RollNo(r){}
		void display(){
			cout<<"Name :"<<getname()<<endl<<"Date Joined :"<<getdate()<<endl<<"Roll No :"<<RollNo<<endl;
		}
};

class Faculty:public LibraryMember{
	private:
		string Department;
	public:	
		Faculty(string n,string D):LibraryMember(n),Department(D){}
		void display(){
			cout<<"Name :"<<getname()<<endl<<"Date Joined :"<<getdate()<<endl<<"Department :"<<Department<<endl;
		}
};

class Transaction{
	private:
		int ID;
		int amount;
		time_t date;
	public:
		Transaction():ID(rand()),amount(0),date(time(0)){}
		void setamount(int a){amount=a;}
		void setdate(){time(0);}
		int getamount(){return amount;}
		time_t getdate(){return date;}
		void GetBook(Book& book,LibraryMember& person){
			book.display();
			cout<<"was Successfuly taken by:"<<endl;
			person.display();
			book.takebook();
			cout<<"Enter amount for transaction: "<<endl;
			cin>>amount;
			date=time(0);
		}
		void receipt(){
			cout<<"transaction ID: "<<ID<<endl<<"Amount :"<<amount<<endl<<"Date of Transaction :"<<time(0)<<endl;
		}
		
};

int main(){
	Student st("Murtaza",93);
	Novel novel("How to Kill Someone","Thriller","Jason Mamoa");
	cout<<"Generating Transaction..."<<endl;
	Transaction obj;
	obj.GetBook(novel,st);
	obj.receipt();
	
	
}