#include <iostream>
using namespace std;
class car{
private:
    string brandName;
    float price_new;
    string color;
    float odometer;
    float temp;
public:
    car(){
        cout << "Enter Brand Name: ";
        cin >> brandName;
        cout << "Enter Price When The Car Was New: ";
        cin >> price_new;
        cout << "Enter Color: ";
        cin >> color;
        cout << "Enter Current Odometer Reading: ";
        cin >> odometer;
    }
    float getPrice_afterUse(){
        temp = price_new * (1 - (odometer / 600000));
        return temp;
    }
    void updateMilage(double traveled_distance){
        double milage = traveled_distance + odometer;
        odometer = milage;
    }
    void display(){
        cout << "Brand Name: " << brandName << endl;
        cout << "New Price: " << price_new << endl;
        cout << "Price After Used: " << temp << endl;
        cout << "Odometer: " << odometer << endl;
    }
};
int main(){
    car A;
    A.getPrice_afterUse();
    cout << endl;
    A.display();
    cout << endl;
    for (int i = 0; i < 2; i++){
        double distance[2];
        cout << "Enter Distance Travelled: ";
        cin >> distance[i];
        A.updateMilage(distance[i]);
        A.getPrice_afterUse();
        A.display();
        cout << endl;
    }
    return 0;
}


