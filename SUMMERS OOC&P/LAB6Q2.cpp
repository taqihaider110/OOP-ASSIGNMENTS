#include <iostream>
using namespace std;

class mealBill
{
    float meal_bill,sales_tax,Total_bill,payment,change;
    string restaurant_name;

public:
    mealBill(string x) : restaurant_name(x)
    {
        cout << "Enter Meal Bill: ";
        cin >> meal_bill;
    }

    void bill()
    {
        cout << "Bill" << endl;
        cout << "\tMeal Bill: " << meal_bill << endl;
        sales_tax = (meal_bill * 0.16); // sale tax is 16%
        cout << "\tTax: " << sales_tax << endl;
        cout << "\tTip: " << (meal_bill * 0.15) << endl;
        Total_bill = meal_bill + sales_tax + (meal_bill * 0.15);
        cout << "\tTotal cost: " << Total_bill << endl;
        cout << endl;
    }
    void receipt()
    {
        cout << "Enter Payment Paid: ";
        cin >> payment;
        cout << "Receipt" << endl;
        cout << "\t Total cost: " << Total_bill << endl;
        cout << "\t Payment: " << payment << endl;
        change = payment - Total_bill;
        cout << "\t Change: " << change << endl
             << endl;
        cout << "\t Thank you for dining at " << restaurant_name << endl;
    }
};

int main()
{
    mealBill customer("Taqi_Haider");
    customer.bill();
    customer.receipt();
    return 0;
}
