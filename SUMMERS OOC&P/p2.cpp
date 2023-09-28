#include<iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void area() override {
        double result = 3.1415 * radius * radius;
        cout << "Area of the circle: " << result << endl;
    }
};

int main() {
    // Shape* shape = new Shape(); 
    // Will throw Error: Cannot create object of an abstract class
    Circle circle(5.0);
    circle.area(); // Calls Circle's area function

    return 0;
}
