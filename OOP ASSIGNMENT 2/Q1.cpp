#include<iostream>
#include<cstring>
using namespace std;
class Book{
    double id;
    string name;
    public: 
    int set(int id,string name);
    void get();
};
class Textbook:public Book{
    int id;
    string name;
    public:
    Textbook(int i,string n):id(i),name(n){}

    overide int set(int id,string name){
        id=this->id;
        name=this->name;
    }
    overide void get(){
        cout<<"The Id is "<<this->id<<endl;
        cout<<"The Name is "<<this->name<<endl;
    }
};

class Novel:public Book{
    int id;
    string name;
    public:
    Novel(int i,string n):id(i),name(n){}
    overide int set(int id,string name){
        id=this->id;
        name=this->name;
    }
    overide void get(){
        cout<<"The Id is "<<this->id<<endl;
        cout<<"The Name is "<<this->name<<endl;
    }
};

class LibraryMember{
    
};
class StudentMember:public LibraryMember{

};
class FacultyMember:public LibraryMember{

};

int main(){
    
    return 0;
}