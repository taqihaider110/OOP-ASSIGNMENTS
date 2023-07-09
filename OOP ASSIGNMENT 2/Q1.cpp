#include<iostream>
#include<cstring>
using namespace std;
class Book{
    protected:
    string name,author;
    public:
    Book(const string &name, const string &author): name(name), author(author){}
    // virtual void add_book()=0;
    // virtual void remove_book()=0;
    // virtual void update_book()=0;
    virtual void display_book()=0;
};
class Textbook:public Book{
    string Subject;
    public:
    Textbook(const string &name,string &author,string &Subject):Book(name,author),Subject(Subject){}
    // void add_book() override{
    //     cout<<"-------Enter Details for TextBook--------"<<endl;
    //     cout<<"Enter TextBook name :"<<endl;
    //     getline(cin>>ws, name);
    //     cout<<"Enter Author name :"<<endl;
    //     getline(cin>>ws, author);
    // }
    // void remove_book() override{
    //     cout<<"Enter TextBook name to remove :"<<endl;
    //     getline(cin>>ws, name);
    //     cout<<"Enter Author name to remove :"<<endl;
    //     getline(cin>>ws, author);
    //     name = " ";
    //     author = " ";
    //     cout<<"Book removed successfully."<<endl;
    // }
    // void update_book() override {
    //     cout<<"Enter TextBook name to update :"<<endl;
    //     getline(cin>>ws, name);
    //     cout<<"Enter Author name to update :"<<endl;
    //     getline(cin>>ws, author);
    // }
    void display_book() override{
        cout<<"-------Details for TextBook--------"<<endl;
        cout<<"Text Book name : "<<name<<endl;
        cout<<"Author name : "<<author<<endl;
        cout<<"Subject name : "<<Subject<<endl;
    }
};

class Novel:public Book{
    string type;
    public:
    Novel(const string &name,string &author,string &type):Book(name,author),type(type){}
    // void add_book() override{
    //     cout<<"-------Enter Details for Novel--------"<<endl;
    //     cout<<"Enter Novel name :"<<endl;
    //     getline(cin>>ws, name);
    //     cout<<"Enter Novel Author name :"<<endl;
    //     getline(cin>>ws, author);
    // }
    // void remove_book() override{
    //     cout<<"Enter Novel name to remove:"<<endl;
    //     getline(cin>>ws, name);
    //     cout<<"Enter Novel Author name to remove :"<<endl;
    //     getline(cin>>ws, author);
    //     name = " ";
    //     author = " ";
    //     cout<<"Book removed successfully."<<endl;
    // }
    // void update_book() override{
    //     cout<<"Enter Novel name to update:"<<endl;
    //     getline(cin>>ws, name);
    //     cout<<"Enter Novel Author name to update :"<<endl;
    //     getline(cin>>ws, author);
    // }
    void display_book() override{
        cout<<"-------Details for Novel--------"<<endl;
        cout<<"Novel name : "<<name<<endl;
        cout<<"Novel Author name : "<<author<<endl;
        cout<<"Novel Type name : "<<type<<endl;
    }
};
class LibraryMember{
    protected:
    int Id;
    string name;
    public:
    LibraryMember(int Id,const string &name):Id(Id),name(name){}
    // virtual void get_data()=0;
    virtual void display_data()=0;

};
class StudentMember:public LibraryMember{
    private:
    int Max_books;
    public:
    StudentMember(int Id,const string &name):LibraryMember(Id,name),Max_books(5){}
    // void get_data(){
    //     cout<<"-------Enter Details for Student Member--------"<<endl;
    //     cout<<"Enter Student member Id :"<<endl;
    //     cin>>Id;
    //     cout<<"Enter Student member Name :"<<endl;
    //     getline(cin>>ws, name);
    //     }
    void display_data(){
        cout<<"-------Details for Student Member--------"<<endl;
        cout<<"Student member Id :"<<Id<<endl;
        cout<<"Student member Name :"<<name<<endl;
        cout<<"Maximum Books Allowed :"<<Max_books<<endl;
        }
};
class FacultyMember:public LibraryMember{
    private:
    int Max_books;
    public:
    FacultyMember(int Id,const string &name):LibraryMember(Id,name),Max_books(5){}
    // void get_data(){
    //     cout<<"-------Enter Details for Faculty Member--------"<<endl;
    //     cout<<"Enter Faculty member Id :"<<endl;
    //     cin>>Id;
    //     cout<<"Enter Faculty member Name :"<<endl;
    //     getline(cin>>ws, name);
    //     cout<<"Enter Faculty member Designation :"<<endl;
    //     getline(cin>>ws, designation);
    //     }
    void display_data(){
        cout<<"-------Details for Faculty Member--------"<<endl;
        cout<<"Faculty member Id :"<<Id<<endl;
        cout<<"Faculty member Name :"<<name<<endl;
        cout<<"Maximum Books Allowed :"<<Max_books<<endl;
        }
};
class Transaction{
    Book* book;
    LibraryMember* member;
    string due_date;
    public:
    Book* book;
    LibraryMember* member;
    Transaction():book(nullptr),member(nullptr),due_date(""){}
    Transaction(Book* book,LibraryMember* member,const string &due_date):
    book(book),member(member),due_date(due_date){}
    Book *getBook(){
    }
    LibraryMember *getMember(){
    }
    string getDueDate(){
        return due_date;
    }
};
class library{
};
int main(){
    return 0;
}