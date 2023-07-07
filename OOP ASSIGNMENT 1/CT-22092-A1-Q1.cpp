#include <iostream>

class SavingsAccount {
private:
    static double annualInterestRate;
    double savingsBalance;

public:
    SavingsAccount(double balance) {
        savingsBalance = balance;
    }

    void calculateMonthlyInterest() {
        double monthlyInterest = savingsBalance * (annualInterestRate / 12);
        savingsBalance += monthlyInterest;
    }

    static void modifyInterestRate(double newInterestRate) {
        annualInterestRate = newInterestRate;
    }

    double getBalance() {
        return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0.0;

int main() {
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);
    SavingsAccount::modifyInterestRate(0.03);
    
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "Saver1 Balance after 1 month: Rs." << saver1.getBalance() << std::endl;
    std::cout << "Saver2 Balance after 1 month: Rs." << saver2.getBalance() << std::endl;

    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "Saver1 Balance after 2 months: Rs." << saver1.getBalance() << std::endl;
    std::cout << "Saver2 Balance after 2 months: Rs." << saver2.getBalance() << std::endl;

    return 0;
}
