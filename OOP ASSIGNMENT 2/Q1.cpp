#include<iostream>
#include<cstring>
using namespace std;
class Book{
    protected:
    string title;
    string author;
    public:
    virtual void add_book()=0;
    virtual void remove_book()=0;
    virtual void update_book()=0;
};
class Textbook:public Book{
    int id;
    string name;
    public:
    Textbook(int i,string n):id(i),name(n){}
    void add_book(){
        cout<<"Enter Text Book name :"<<endl;
        cin>>name;
        cout<<"Enter Text Book Id :"<<endl;
        cin>>id;
    }
    void remove_book(){
        cout<<"Enter Text Book name :"<<endl;
        cin>>name;
        cout<<"Enter Text Book Id :"<<endl;
        cin>>id;
    }
    void update_book(){
        cout<<"Enter Text Book name :"<<endl;
        cin>>name;
        cout<<"Enter Text Book Id :"<<endl;
        cin>>id;
    }
};

class Novel:public Book{
    int id;
    string name;
    public:
    Novel(int i,string n):id(i),name(n){}
    void Book::add_book(){
        cout<<"Enter Text Book name :"<<endl;
        cin>>name;
        cout<<"Enter Text Book Id :"<<endl;
        cin>>id;
    }
    void Book::remove_book(){
        cout<<"Enter Text Book name :"<<endl;
        cin>>name;
        cout<<"Enter Text Book Id :"<<endl;
        cin>>id;
    }
    void Book::update_book(){
        cout<<"Enter Text Book name :"<<endl;
        cin>>name;
        cout<<"Enter Text Book Id :"<<endl;
        cin>>id;
    }
};

class LibraryMember{
    protected:
    string name;
    int Id;
    public:

};
class StudentMember:public LibraryMember{

};
class FacultyMember:public LibraryMember{

};

int main(){
    
    return 0;
}