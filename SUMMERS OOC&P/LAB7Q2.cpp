#include <iostream>
using namespace std;

class CarParts
{
protected:
    string Brand;

public:
    CarParts(string brand) : Brand(brand) {}

    string get_brand()
    {
        return Brand;
    }

    virtual void info()
    {
        cout << "The name of " << Brand << endl;
    }
};

class Doors : public CarParts
{
    string location;

public:
    Doors(string loc, string brand) : CarParts(brand), location(loc) {}

    void open()
    {
        cout << location << " door is opened." << endl;
    }

    void close()
    {
        cout << location << " door is closed." << endl;
    }

    void info() override
    {
        cout << "This is a " << get_brand() << " at " << location << endl;
    }
};

class Windows : public CarParts
{
    string location;

public:
    Windows(string loc, string brand) : CarParts(brand), location(loc) {}

    void open()
    {
        cout << location << " window is opened." << endl;
    }

    void close()
    {
        cout << location << " window is closed." << endl;
    }

    void info() override
    {
        cout << "This is a " << get_brand() << " at " << location << endl;
    }
};

class Engine : public CarParts
{
    string horsepower;

public:
    Engine(string hp, string brand) : CarParts(brand), horsepower(hp) {}

    void start()
    {
        cout << "The Engine of Horsepower " << horsepower << " is started." << endl;
    }

    void stop()
    {
        cout << "The Engine of Horsepower " << horsepower << " is stopped." << endl;
    }

    void info() override
    {
        cout << "This is a " << get_brand() << " & the hp of " << horsepower << endl;
    }
};

class Wheels : public CarParts
{
    string mirror;

public:
    Wheels(string m, string brand) : CarParts(brand), mirror(m) {}

    void rotate()
    {
        cout << "Wheels are rotated" << endl;
    }

    void setMirror(string m)
    {
        if (m == "yes")
        {
            cout << "Mirror is on" << endl;
        }
        else
        {
            cout << "Mirror is off" << endl;
        }
    }

    void info() override
    {
        cout << "This is a " << get_brand() << " & Mirror status : " << mirror << endl;
    }
};

class Car
{
    Doors frontDoor;
    Doors rearDoor;
    Windows frontWindow;
    Windows rearWindow;
    Engine engine;
    Wheels wheels;

public:
    Car(string doorLocation, string windowLocation, string engineHP, string wheelMirror)
        : frontDoor(doorLocation, "BMW"),
          rearDoor(doorLocation, "BMW"),
          frontWindow(windowLocation, "Mercedes"),
          rearWindow(windowLocation, "Mercedes"),
          engine(engineHP, "Audi"),
          wheels(wheelMirror, "Civic") {}

    void start()
    {
        engine.start();
    }

    void stop()
    {
        engine.stop();
    }

    void openFrontDoor()
    {
        frontDoor.open();
    }

    void closeFrontDoor()
    {
        frontDoor.close();
    }

    void openRearDoor()
    {
        rearDoor.open();
    }

    void closeRearDoor()
    {
        rearDoor.close();
    }

    void openFrontWindow()
    {
        frontWindow.open();
    }

    void closeFrontWindow()
    {
        frontWindow.close();
    }

    void openRearWindow()
    {
        rearWindow.open();
    }

    void closeRearWindow()
    {
        rearWindow.close();
    }

    void rotateWheels()
    {
        wheels.rotate();
    }

    void setWheelMirror(string m)
    {
        wheels.setMirror(m);
    }

    void carInfo()
    {
        cout << "Car Brand: " << wheels.get_brand() << endl;
        cout << "Car Parts Information:" << endl;
        frontDoor.info();
        rearDoor.info();
        frontWindow.info();
        rearWindow.info();
        engine.info();
        wheels.info();
    }
};

int main()
{
    Car myCar("Front", "Front", "300hp", "yes");
    myCar.carInfo();
    myCar.start();
    myCar.openFrontDoor();
    myCar.openFrontWindow();
    myCar.rotateWheels();
    myCar.stop();
    myCar.closeFrontDoor();
    myCar.closeFrontWindow();

    return 0;
}
