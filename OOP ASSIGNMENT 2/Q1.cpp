#include<iostream>
#include<cstring>
using namespace std;
class Book{
    public:
    virtual void add_book()=0;
    virtual void remove_book()=0;
    virtual void update_book()=0;
    virtual void display_book()=0;
};
class Textbook:public Book{
    string subject;
    string author;
    public:
    string n,au;
    Textbook(){}
    void add_book() override{
        cout<<"Enter TextBook name :"<<endl;
        getline(cin>>ws, n);
        subject=n;
        cout<<"Enter Author name :"<<endl;
        getline(cin>>ws, au);
        author=au;
    }
    void remove_book() override{
        cout<<"Enter TextBook name to remove :"<<endl;
        getline(cin>>ws, n);
        subject=n;
        cout<<"Enter Author name to remove :"<<endl;
        getline(cin>>ws, au);
        author=au;
    }
    void update_book() override {
        cout<<"Enter TextBook name to update :"<<endl;
        getline(cin>>ws, au);
        author=au;
        cout<<"Enter Publisher name to update :"<<endl;
        getline(cin>>ws, au);
        author=au;
    }
    void display_book() override{
        cout<<"Text Book name :"<<subject<<endl;
        cout<<"Author name :"<<author<<endl;
    }
};

class Novel:public Book{
    string name;
    string author;
    public:
    string nm,au;
    Novel(){}
    void add_book() override{
        cout<<"Enter Novel name :"<<endl;
        getline(cin>>ws, nm);
        name = nm;
        cout<<"Enter Novel Author name :"<<endl;
        getline(cin>>ws, au);
        author = au;
    }
    void remove_book() override{
        cout<<"Enter Novel name to remove:"<<endl;
        getline(cin>>ws, nm);
        name = nm;
        cout<<"Enter Novel Author name to remove :"<<endl;
        getline(cin>>ws, au);
        author = au;
    }
    void update_book() override{
        cout<<"Enter Novel name to update:"<<endl;
        getline(cin>>ws, nm);
        name = nm;
        cout<<"Enter Novel Author name to update :"<<endl;
        getline(cin>>ws, au);
        author = au;
    }
    void display_book() override{
        cout<<"Novel name :"<<name<<endl;
        cout<<"Novel Author name :"<<author<<endl;
    }
};

class LibraryMember{
    public:
    virtual void get_data()=0;
    virtual void display_data()=0;

};
class StudentMember:public LibraryMember{
    private:
    int Id;
    string name;
    public:
    int id;
    string nm;
    StudentMember(){}
    void get_data(){
        cout<<"Enter Student member Id :"<<endl;
        cin>>id;
        Id=id;
        cout<<"Enter Student member Name :"<<endl;
        getline(cin>>ws, nm);
        name = nm;
        }
    void display_data(){
        cout<<"Student member Id :"<<Id<<endl;
        cout<<"Student member Name :"<<name<<endl;
        }
};
class FacultyMember:public LibraryMember{
    private:
    int Id;
    string name;
    string designation;
    public:
    int id;
    string nm,dsg;
    FacultyMember(){}
    void get_data(){
        cout<<"Enter Faculty member Id :"<<endl;
        cin>>id;
        Id=id;
        cout<<"Enter Faculty member Name :"<<endl;
        getline(cin>>ws, nm);
        name = nm;
        cout<<"Enter Faculty member Designation :"<<endl;
        getline(cin>>ws, dsg);
        designation = dsg;
        }
    void display_data(){
        cout<<"Faculty member Id :"<<Id<<endl;
        cout<<"Faculty member Name :"<<name<<endl;
        cout<<"Faculty member Designation :"<<designation<<endl;
        }
};

int main(){
    Textbook t;
    t.add_book();
    t.display_book();
    return 0;
}