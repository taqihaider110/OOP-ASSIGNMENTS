#include <iostream>
using namespace std;
class BOX
{
    double width, length, height;

public:
    BOX() : width(0.0), length(0.0), height(0.0) {}
    BOX(double w, double l, double h) : width(w), length(l), height(h) {}
    void showdata()
    {
        cout << "The width of the BOX: " << width << endl;
        cout << "The length of the BOX: " << length << endl;
        cout << "The height of the BOX: " << height << endl;
    }
    void calcVolume()
    {
        cout << "The volume is :" << width * length * height << endl;
    }
    BOX operator+(BOX &b)
    {
        return BOX(width + b.width, length + b.length, height + b.height);
    }
    BOX operator-(BOX &b)
    {
        return BOX(width - b.width, length - b.length, height - b.height);
    }
    BOX operator*(double scalar)
    {
        return BOX(width * scalar, length * scalar, height * scalar);
    }
    BOX operator/(double scalar) const
    {
        if (scalar == 0.0)
        {
            std::cerr << "Error: Division by zero." << endl;
            return *this;
        }
        return BOX(width / scalar, length / scalar, height / scalar );
    }
};
int main()
{
    BOX box1(2.0, 3.0, 4.0);
    BOX box2(1.0, 1.5, 2.0);

    // Display data of box1 and box2
    cout << "Box1 data: ";
    box1.showdata();

    cout << "Box2 data: ";
    box2.showdata();

    // Perform operations on boxes
    BOX additionResult = box1 + box2;
    BOX subtractionResult = box1 - box2;
    BOX multiplicationResult = box1 * 2.0;
    BOX divisionResult = box1 / 2.0;

    // Display results
    cout << "Addition Result: " << endl;
    additionResult.showdata();
    cout << "Subtraction Result: " << endl;
    subtractionResult.showdata();
    cout << "Multiplication Result: " << endl;
    multiplicationResult.showdata();
    cout << "Division Result: " << endl;
    divisionResult.showdata();
}