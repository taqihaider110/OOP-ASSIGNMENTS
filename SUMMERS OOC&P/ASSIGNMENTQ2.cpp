// Q2. Apply OOP concepts to write a program to find maximum out of two numbers using friend
// function and also note one number is a member of one class and other number is member of
// some other class. By using set function set values of data members.
#include<iostream>
using namespace std;
class num2;
class num1{
    int number1;
    public:
    num1():number1(0){}
    void set_value(int n){
        number1=n;
    }
    void get_value(){
        cout<<"Number 1 Value:"<<number1<<endl;
    }
    friend int max(num1,num2);
};
class num2{
    int number2;
    public:
    num2():number2(0){}
    void set_value(int n){
        number2=n;
    }
    void get_value(){
        cout<<"Number 2 Value:"<<number2<<endl;
    }
    friend int max(num1,num2);
};
int max(num1 n1,num2 n2){
    if(n1.number1>n2.number2){
        return n1.number1;
    }
    else {
        return  n2.number2;
    }
}
int main(){
    num1 a;
    num2 b;

    a.set_value(10);
    a.get_value();

    b.set_value(20);
    b.get_value();

    int maximum = max(a, b);

    cout << "Maximum: " << maximum << endl;
    return 0;
}