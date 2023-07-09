#include <iostream>
#include<cstring>
using namespace std;
class CustomException{
private:
    string errorMessage;
public:
    CustomException(const string& message) : errorMessage(message) {}
    string getMessage() const{
        return errorMessage;
    }
};
class Person{
protected:
    string name;
    int age;
public:
    Person(const string& personName, int personAge) : name(personName), age(personAge) {}
    virtual void displayInfo() const = 0;
    string getName() const{
        return name;
    }
};
class Student : public Person{
private:
    string studentId;
public:
    Student(const string& studentName, int studentAge, const string& id)
        : Person(studentName, studentAge), studentId(id) {}
    void displayInfo() const override{
        cout << "Student Name: " << name << ", Age: " << age << ", Student ID: " << studentId << endl;
    }
};
class Professor : public Person{
private:
    string course;
public:
    Professor(const string& professorName, int professorAge, const string& professorCourse)
        : Person(professorName, professorAge), course(professorCourse) {}
    void displayInfo() const override{
        cout << "Professor Name: " << name << ", Age: " << age << ", Course: " << course << endl;
    }
};
class Staff : public Person{
private:
    string designation;
public:
    Staff(const string& staffName, int staffAge, const string& staffRole)
        : Person(staffName, staffAge), designation(staffRole) {}
    void displayInfo() const override{
        cout << "Staff Name: " << name << ", Age: " << age << ", Designation: " << designation << endl;
    }
};
template <class T>
class Database{
private:
    T** data;
    int capacity;
    int size;
public:
    explicit Database(int initialCapacity = 10) : capacity(initialCapacity), size(0){
        data = new T*[capacity];
    }
    ~Database(){
        remove();
        delete[] data;
    }
    void Add_Record(T* record){
        if (size == capacity){
            throw CustomException("Database is full. Cannot add more records.");
        }
        data[size] = record;
        size++;
    }
    bool Remove_Record(T* record){
        for (int i = 0; i < size; i++){
            if (data[i] == record){
                delete data[i];
                size--;
                for (int j = i; j < size; j++){
                    data[j] = data[j + 1];
                }
                return true;
            }
        }
        return false;
    }
    T* Search_Record(const string& name) const{
        for (int i = 0; i < size; i++){
            if (data[i]->getName() == name){
                return data[i];
            }
        }
        return nullptr;
    }
    void Displaying_Records() const{
        for (int i = 0; i < size; i++){
            data[i]->displayInfo();
        }
    }
    void remove(){
        for (int i = 0; i < size; i++){
            delete data[i];
        }
        size = 0;
    }
};
int main(){
    try{
        Database<Person> db;
        Person* student1 = new Student("Taqi Haider", 20, "CT-092");
        Person* student2 = new Student("Wajih-ur -rehman", 20, "CT-083");
        Person* student3 = new Student("Abbas Haider", 19, "CE-121");
        Person* professor = new Professor("Sir Furqan", 35, "Computer Science");
        Person* staff = new Staff("Michael Johnson", 28, "Floor Manager");
        db.Add_Record(student1);
        db.Add_Record(student2);
        db.Add_Record(student3);
        db.Add_Record(professor);
        db.Add_Record(staff);
        cout << "---------------------Displaying all records-------------------" << endl;
        db.Displaying_Records();
        Person* foundRecord = db.Search_Record("Taqi");
        if (foundRecord){
            cout << "The Record you enter is Found:" << endl;
            foundRecord->displayInfo();
        }
        else{
            cout << "Record not found. " << endl;
        }
        db.Remove_Record(staff);
        cout << "After removing a record:" << endl;
        db.Displaying_Records();
        db.remove();
        return 0;
    }
    catch (const CustomException& t)
    {
        cout << "The Error of the code is : " << t.getMessage() << endl;
        return 1;
    }
}
