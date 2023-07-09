#include<iostream>
#include<cstdlib>

using namespace std;

class Book{
	private:
		string bookname,author;
	public:
		Book():bookname(""),author(""){}
		Book(string b,string a):bookname(b),author(a){}
		void setbookname(string n){bookname=n;}
		void setauthor(string a){author=a;}
		string getbookname(){return bookname;}
		string getauthor(){return author;}
		virtual void takebook()=0;
		virtual void display()=0;
		virtual void set()=0;
};

class Textbook:public Book{
	private:
		bool Available=true;
	public:
		Textbook(string n,string a):Book(n,a){}
		Textbook():Book(){}
		void set(){
			string b,a;
			cout<<"Enter Book Name, Author"<<endl;
			cin>>b>>a;
			setbookname(b);setauthor(a);
		}
		void takebook(){
			Available=false;
		}
		void display(){
			cout<<"Book Name:"<<getbookname()<<" | Author:"<<getauthor()<<endl;
		}
};

class Novel:public Book{
	private:
		string genre;
	public:
		Novel(string n,string g,string a):Book(n,a),genre(g){}
		Novel():Book(),genre(""){}
		void set(){
			string b,a,g;
			cout<<"Enter Book Name, Author and Genre"<<endl;
			cin>>b>>a>>g;
			setbookname(b);setauthor(a);genre=g;
		}
		void takebook(){
			cout<<genre<<" Novel was taken"<<endl;
		}
		void display(){
			cout<<"Book Name:"<<getbookname()<<" | Genre:"<<genre<<" | Author:"<<getauthor()<<endl;
		}
};

class LibraryMember{
	private:
		string name;
		bool canborrow=true;
	public:	
		LibraryMember(string n):name(n){}
		LibraryMember():name(""){}
		void setname(string n){name=n;}
		void toggleborrow(){canborrow = !canborrow;}
		bool borrow(){return canborrow;}
		string getname(){return name;}
		virtual void display()=0;
		virtual void Set()=0;
};

class Student:public LibraryMember{
	private:
		int RollNo;
	public:
		Student(string n,int r):LibraryMember(n),RollNo(r){}
		Student():LibraryMember(),RollNo(0){}
		void Set(){
			string n;int r;
			cout<<"Enter Name and RollNo."<<endl;
			cin>>n>>r;
			setname(n);RollNo=r;
		}
		void display(){
			cout<<"Student | Name :"<<getname()<<" | Roll No :"<<RollNo<<endl;
		}
};

class Faculty:public LibraryMember{
	private:
		string Department;
	public:	
		Faculty(string n,string D):LibraryMember(n),Department(D){}
		Faculty():LibraryMember(),Department(""){}
		void Set(){
			string n;int r;
			cout<<"Enter Name and Dept."<<endl;
			cin>>n;
			cin>>Department;
			setname(n);
		}
		void display(){
			cout<<"Faculty | Name :"<<getname()<<" | Department :"<<Department<<endl;
		}
};

class Transaction{
	private:
		int ID;
		int amount;
	public:
		Transaction():ID(rand()),amount(0){}
		void setamount(int a){amount=a;}
		int getamount(){return amount;}
		bool GetBook(Book& book,LibraryMember& person){
			if(person.borrow()){
				book.display();
				cout<<"was Successfuly borrowed by:"<<endl;
				person.display();
				book.takebook();
				amount=0;
				receipt();
				return false;
			}
			else{
				book.display();
				cout<<"was Successfuly taken by:"<<endl;
				person.display();
				book.takebook();
				cout<<"Enter amount for transaction: "<<endl;
				cin>>amount;
				receipt();
				return true;
			}
		}
		void receipt(){
			cout<<"transaction ID: "<<ID<<endl<<"Amount :"<<amount<<endl<<endl;
		}
		
};

class Library{
	Book** books;
	LibraryMember** people;
	int Nbooks,Npeople;
	public:
		Library(int b,int p):Nbooks(b),Npeople(p){
			int opt;
			books= new Book*[b];
			for(int i=0;i<b;i++){
				cout<<"Is book a (1) Textbook or (2) Novel :"<<endl;
				cin>>opt;
				while(opt!=1&&opt!=2){
					cout<<"Invalid option, try again"<<endl;
					cout<<"Is book a (1) Textbook or (2) Novel :"<<endl;
					cin>>opt;
				}
				if(opt==1){
					books[i]= new Textbook;
					books[i]->set();
				}
				else if(opt==2){
					books[i]= new Novel;
					books[i]->set();
				}
			}
			cout<<"----------------------------"<<endl;
			people= new LibraryMember*[p];
			for(int i=0;i<p;i++){
				cout<<"Is person a (1)Faculty or (2)Student :"<<endl;
				cin>>opt;
				while(opt!=1&&opt!=2){
					cout<<"Invalid option, try again"<<endl;
					cout<<"Is person a (1)Faculty or (2)Student :"<<endl;
					cin>>opt;
				}
				if(opt==1){
					people[i]= new Faculty;
					people[i]->Set();
				}
				else if(opt==2){
					people[i]= new Student;
					people[i]->Set();
				}
			}
		}
		void Show(){
			cout<<endl<<endl<<endl<<"////////Library Details/////////"<<endl;
			cout<<"Total Books = "<<Nbooks<<endl;
			for(int i=0;i<Nbooks;i++){
				cout<<"INDEX #"<<i<<"\t";
				books[i]->display();
				cout<<endl;
			}
			cout<<"Total People = "<<Npeople<<endl;
			for(int i=0;i<Npeople;i++){
				cout<<"INDEX #"<<i<<"\t";
				people[i]->display();
				cout<<endl;
			}
		}
		void Addmember(){
			LibraryMember** x;
			x=new LibraryMember*[Npeople];
			for(int i=0;i<Npeople;i++){
				x[i]=people[i];
			}
			people = new LibraryMember*[Npeople+1];
			for(int i=0;i<Npeople;i++){
				people[i]=x[i];
			}
			people[Npeople]->Set();
			Npeople++;
		}
		void AddBook(){
			Book** x;
			x=new Book*[Nbooks];
			for(int i=0;i<Nbooks;i++){
				x[i]=books[i];
			}
			books = new Book*[Nbooks+1];
			for(int i=0;i<Nbooks;i++){
				books[i]=x[i];
			}
			books[Nbooks]->set();
			Nbooks++;
		}
		void take(){
			Transaction t;
			cout<<"Enter your Index in Library List, and Index of Book"<<endl;
			int i,j;
			cin>>i>>j;
			if(i<0||i>=Npeople||j<0||j>Nbooks){
				cout<<"Invalid Transaction, aborting"<<endl;
				return;
			}
			if(t.GetBook(*books[i],*people[j])){
				cout<<"Book was Bought, total books decremented"<<endl;
				Nbooks--;
			}
			else{
				cout<<"Book was Borrowed only "<<endl;
			}
		}
};
int main(){
	int n,p;
	cout<<"Welcome to the library"<<endl;
	cout<<"Enter Number of Total Books, and Total People :"<<endl;
	cin>>n>>p;
	Library l(n,p);
	
	l.Show();
	l.take();
	l.Show();
	
}