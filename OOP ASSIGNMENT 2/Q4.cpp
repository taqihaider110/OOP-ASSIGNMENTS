#include <iostream>
#include <cstring>
using namespace std;

class InvalidDataException
{
private:
    string message;

public:
    InvalidDataException(const string &errorMessage) : message(errorMessage) {}
    string getMessage() const
    {
        return message;
    }
};

class Person
{
protected:
    string name;
    int age;

public:
    Person(const string& personName, int personAge) : name(personName), age(personAge) {}
    virtual void display() const = 0;
    string getName() const
    {
        return name;
    }
};

class Student : public Person
{
private:
    string studentId;

public:
    Student(const string& studentName, int studentAge, const string& id)
        : Person(studentName, studentAge), studentId(id) {}
    void display() const override
    {
        cout << "Student Name: " << name << ", Age: " << age << ", Student ID: " << studentId << endl;
    }
};

class Professor : public Person
{
private:
    string course;

public:
    Professor(const string& professorName, int professorAge, const string& professorCourse)
        : Person(professorName, professorAge), course(professorCourse) {}
    void display() const override
    {
        cout << "Professor Name: " << name << ", Age: " << age << ", Course: " << course << endl;
    }
};

class Staff : public Person
{
private:
    string role;

public:
    Staff(const string& staffName, int staffAge, const string& staffRole)
        : Person(staffName, staffAge), role(staffRole) {}
    void display() const override
    {
        cout << "Staff Name: " << name << ", Age: " << age << ", Role: " << role << endl;
    }
};

template <class T>
class Database
{
private:
    T **data;
    int capacity;
    int size;

public:
    Database(int initialCapacity = 10) : capacity(initialCapacity), size(0)
    {
        data = new T *[capacity];
    }

    ~Database()
    {
        clear();
        delete[] data;
    }

    void addRecord(T *record)
    {
        if (size == capacity)
        {
            throw InvalidDataException("Database is full. Cannot add more records.");
        }

        data[size] = record;
        size++;
    }

    bool removeRecord(T *record)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == record)
            {
                delete data[i];
                size--;
                for (int j = i; j < size; j++)
                {
                    data[j] = data[j + 1];
                }
                return true;
            }
        }
        return false;
    }

    T *searchRecord(const string& name) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i]->getName() == name)
            {
                return data[i];
            }
        }
        return nullptr;
    }

    void displayAllRecords() const
    {
        for (int i = 0; i < size; i++)
        {
            data[i]->display();
        }
    }

    void clear()
    {
        for (int i = 0; i < size; i++)
        {
            delete data[i];
        }
        size = 0;
    }
};

int main()
{
    try
    {
        Database<Person> database;

        Person *student1 = new Student("Taqi", 20, "CT-092");
        Person *student2 = new Student("Wajihn-ur-Rehman", 20, "CT-084");
        Person *professor = new Professor("Sir Furqan", 35, "Computer Science");
        Person *staff = new Staff("Ali", 28, "Floor incharge");

        database.addRecord(student1);
        database.addRecord(student2);
        database.addRecord(professor);
        database.addRecord(staff);

        cout << "Displaying all records:" << endl;
        database.displayAllRecords();

        Person *foundRecord = database.searchRecord("Taqi");
        if (foundRecord)
        {
            cout << "Found record:" << endl;
            foundRecord->display();
        }
        else
        {
            cout << "Record not found." << endl;
        }

        database.removeRecord(staff);
        cout << "After removing a record:" << endl;
        database.displayAllRecords();

        database.clear();

        return 0;
    }
    catch (const InvalidDataException &e)
    {
        cout << "Invalid Data: " << e.getMessage() << endl;
        return 1;
    }
}
