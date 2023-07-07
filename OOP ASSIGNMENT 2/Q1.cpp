#include<iostream>
#include<cstring>
using namespace std;
class Book{
    public:
    virtual void add_book()=0;
    virtual void remove_book()=0;
    virtual void update_book()=0;
};
class Textbook:public Book{
    string subject;
    string author;
    public:
    Textbook(string n,string au):subject(n),author(au){}
    void add_book() override{
        cout<<"Enter Text Book name :"<<endl;
        cin>>subject;
        cout<<"Enter Author name :"<<endl;
        cin>>author;
    }
    void remove_book() override{
        cout<<"Enter Book name to remove :"<<endl;
        cin>>subject;
        cout<<"Enter Author name to remove :"<<endl;
        cin>>author;
    }
    void update_book() override {
        cout<<"Enter Text Book name to update :"<<endl;
        cin>>subject;
        cout<<"Enter Publisher name to update :"<<endl;
        cin>>author;
    }
};

class Novel:public Book{
    string name;
    string author;
    public:
    Novel(string nm,string au):name(nm),author(au){}
    void add_book() override{
        cout<<"Enter Novel name :"<<endl;
        cin>>name;
        cout<<"Enter Novel Author name :"<<endl;
        cin>>author;
    }
    void remove_book() override{
        cout<<"Enter Novel name to remove:"<<endl;
        cin>>name;
        cout<<"Enter Novel Author name to remove :"<<endl;
        cin>>author;
    }
    void update_book() override{
        cout<<"Enter Novel name to update:"<<endl;
        cin>>name;
        cout<<"Enter Novel Author name to update :"<<endl;
        cin>>author;
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