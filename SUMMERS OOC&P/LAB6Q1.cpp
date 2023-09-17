#include <iostream>
using namespace std;

class rectangle {
    float length, width, area, parameter;

public:
    rectangle() : length(0), width(0) {}
    void setData(float len, float wid) {
        length = len;
        width = wid;
    }
    void calculateArea() {
        area = length * width;
    }
    void calculateParameter() {
        parameter = 2 * (length + width);
    }
    float getArea() const {
        return area;
    }
    float getParameter() const {
        return parameter;
    }
    void display() {
        cout << "Area Of Rectangle is: " << getArea() << endl;
        cout << "Parameter of Rectangle is: " << getParameter() << endl;
    }
};

class dormRoom {
    int room_no;
    int capacity;
    bool isOccupied;

public:
    dormRoom(int x, int y) : room_no(x), capacity(y), isOccupied(false) {}
    int getRoomNumber() const {
        return room_no;
    }
    int getRoomCapacity() const {
        return capacity;
    }
    void occupy() {
        isOccupied = true;
        cout << "Room is occupied: " << isOccupied << endl;
    }
    void vacate() {
        isOccupied = false;
        cout << "Room is occupied: " << isOccupied << endl;
    }
};

int main() {
    rectangle r1;
    float len, wid;
    cout << "Enter Length Of Rectangle: ";
    cin >> len;
    cout << "Enter Width Of Rectangle: ";
    cin >> wid;
    r1.setData(len, wid);
    r1.calculateArea();
    r1.calculateParameter();
    r1.display();
    cout << endl;

    cout << "Dorm Room Information:" << endl;
    dormRoom d1(5, 3);
    cout << "Room Number:  " << d1.getRoomNumber() << endl;
    cout << "Room Capacity: " << d1.getRoomCapacity() << endl;
    d1.occupy();
    d1.vacate();

    return 0;
}
