#include <iostream>
using namespace std;

class coffee_outlet
{
private:
    int no_of_bags;
    float cost_of_order;
    int largeBoxes;
    int mediumBoxes;
    int smallBoxes;
    float const bag_price = 5.50;
    float largeB;
    float mediumB;
    float smallB;
    float total_cost;

public:
    coffee_outlet()
    {
        cout << "Enter Number Of Bags Orderd:  ";
        cin >> no_of_bags;
    }
    void costOf_order()
    {
        cost_of_order = bag_price * no_of_bags;
    }

    void no_of_boxes()
    {
        largeBoxes = no_of_bags / 20;
        mediumBoxes = (no_of_bags % 20) / 10;
        smallBoxes = ((no_of_bags % 20) % 10) / 5;
    }
    void priceForboxes()
    {
        largeB = largeBoxes * 1.80;
        mediumB = mediumBoxes * 1.00;
        smallB = smallBoxes * 0.60;
        total_cost = cost_of_order + largeB + mediumB + smallB;
    }

    void display()
    {
        cout << "The Cost Of Order: $ " << cost_of_order << endl;
        cout << endl;
        cout << "BOX Used: " << endl;
        cout << "\t" << largeBoxes << " Large"
             << "- $ " << largeB << endl;
        cout << "\t" << mediumBoxes << " Medium"
             << "- $ " << mediumB << endl;
        cout << "\t" << smallBoxes << " Small"
             << "- $ " << smallB << endl;
        cout << endl;
        cout << "Your total cost is: $  " << total_cost << endl;
    }
};

int main()
{
    coffee_outlet c1;
    c1.costOf_order();
    c1.no_of_boxes();
    c1.priceForboxes();
    c1.display();
    return 0;
}
