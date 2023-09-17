#include <iostream>
using namespace std;

class management_system
{
    float meal_bill;
    float sales_tax;
    float Total_bill;
    float payment;
    float change;
    float current_balance;
    string name;
    string Student_Id;

public:
    management_system(float u, string v, string w) : current_balance(u), name(v), Student_Id(w)
    {
        cout << "Enter Meal Bill: ";
        cin >> meal_bill;
    }

    void bill()
    {
        cout << "Bill" << endl;
        cout << "\tMeal Bill: " << meal_bill << endl;
        sales_tax = (meal_bill * 0.06); // sale tax is 16%
        cout << "\tTax: " << sales_tax << endl;
        cout << "\tTip: " << (meal_bill * 0.15) << endl;
        Total_bill = meal_bill + sales_tax + (meal_bill * 0.15);
        cout << "\tTotal cost: " << Total_bill << endl;
        cout << endl;
    }
    void updateBalance()
    {

        current_balance = current_balance + Total_bill;
        current_balance = current_balance - payment;
    }
    void receipt()
    {
        cout << "Charger the meal to " << name << "'s account \n" << endl;
        cout << "Enter Payment Paid: ";
        cin >> payment;
        updateBalance();
        cout << "Receipt" << endl;
        cout << "\t Total cost: " << Total_bill << endl;
        cout << "\t Payment: " << payment << endl;
        if (payment == 0)
        {
            change = payment;
        }
        else
        {

            change = payment - Total_bill;
        }
        cout << "\t Change: " << change << endl
             << endl;
        cout << "\t Thank you for dining at University Summit " << endl;
        cout<<endl;
    }
    void showStudentData()
    {
        cout << "Current Status of Ahmed's account:" << endl;
        cout << "ID: " << Student_Id << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << current_balance << endl;
    }
};

int main()
{
    management_system Ahemd_Ali(2000, "Ahmed", "CT-22099");
    Ahemd_Ali.bill();
    Ahemd_Ali.receipt();
    Ahemd_Ali.showStudentData();
    return 0;
}
