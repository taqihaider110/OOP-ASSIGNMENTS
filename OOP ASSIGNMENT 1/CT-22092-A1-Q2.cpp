#include <iostream>
using namespace std;

class Ship {
protected:
    string shipName;  // Variable for the name of the ship
    string yearBuilt; // Variable for the year that the ship was built

public:
    Ship() {
        fflush(stdin);
        cout << "\nEnter Name of the Ship: ";
        getline(cin, shipName);
        cout << "\nEnter The year Ship was built: ";
        getline(cin, yearBuilt);
    }

    virtual void displayShipInfo() { // Renamed the function to displayShipInfo()
        cout << "\nShip Name: " << shipName << endl;
        cout << "Year ship was built: " << yearBuilt << endl;
    }
};

class CruiseShip : public Ship {
private:
    int maxPassengers; // Member variable for the maximum number of passengers

public:
    CruiseShip() : Ship() {
        cout << "\nEnter Maximum Number of Passengers: ";
        cin >> maxPassengers;
    }

    void displayShipInfo() override { // Overridden function to display ship information
        cout << "\nShip Name: " << shipName << endl;
        cout << "Maximum Number of Passengers: " << maxPassengers << endl;
    }
};

class CargoShip : public Ship {
private:
    int cargoCapacity; // Member variable for the cargo capacity

public:
    CargoShip() : Ship() {
        cout << "Enter cargo capacity in tonnage: ";
        cin >> cargoCapacity;
    }

    void displayShipInfo() override { // Overridden function to display ship information
        cout << "\nShip Name: " << shipName << endl;
        cout << "Cargo capacity: " << cargoCapacity << endl;
    }
};

int main() {
    Ship* ships[] = {
        new Ship(),
        new CruiseShip(),
        new CargoShip()
    };

    cout << "\n\t\t_______________DATA_____________\n";
    for (int i = 0; i < 3; i++) {
        ships[i]->displayShipInfo(); // Changed the function call to displayShipInfo()
        delete ships[i];
    }

    return 0;
}
