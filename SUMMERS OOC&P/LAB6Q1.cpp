#include <iostream>
using namespace std;

class rectangle
{
    float length;
    float width;
    float area;
    float parameter;

public:
    rectangle() : length(0), width(0) {}

    void setData(float len, float wid)
    {
        length = len;
        width = wid;
    }
    pair<float, float> getdata()
    {
        return make_pair(length, width);
    }
    void area_of_rectangle()
    {
        area = getdata().first * getdata().second;
    }
    void parameter_of_rectangle()
    {
        parameter = 2 * getdata().first + 2 * getdata().second;
    }
    void display()
    {
        cout << "Area Of Rectangle is: " << area << endl;
        cout << "Parameter of Rectangle is: " << parameter << endl;
    }
};

class dormRoom
{
    int room_no;
    int capacity;
    bool isOccupied;

public:
    dormRoom(int x, int y) : room_no(x), capacity(y), isOccupied(false) {}
    int get_room_no()
    {
        return room_no;
    }
    int get_room_capacity()
    {
        return capacity;
    }
    void IsOccupied()
    {
        isOccupied = true;
        cout << "Room is free true/false: " << isOccupied << endl;
    }
    void isvacant()
    {
        isOccupied = false;
        cout << "Room is free true/false: " << isOccupied << endl;
    }
};
int main()
{
    rectangle r1;
    float len, wid;
    cout << "Enter Length Of Rectangle: ";
    cin >> len;
    cout << "Enter Width Of Rectangle: ";
    cin >> wid;
    r1.setData(len, wid);
    r1.area_of_rectangle();
    r1.parameter_of_rectangle();
    r1.display();
    cout << endl;
    cout << "Dorm Room Information:" << endl;
    dormRoom d1(101, 5);
    cout << "Room Number:  " << d1.get_room_no() << endl;
    cout << "Room Capacity: " << d1.get_room_capacity() << endl;
    d1.IsOccupied();
    d1.isvacant();

    return 0;
}
