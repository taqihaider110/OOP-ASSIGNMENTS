#include <iostream>
using namespace std;

class Cities {
protected:
    int populationCount;
    float budget, expenses;

public:
    int getPopulationCount() {
        return populationCount;
    }

    float getBudget() {
        return budget;
    }

    float getExpenses() {
        return expenses;
    }

    void setPopulationCount(int populationCount) {
        this->populationCount = populationCount;
    }

    void setBudget(float budget) {
        this->budget = budget;
    }

    void setExpenses(float expenses) {
        this->expenses = expenses;
    }
};

class Provinces {
protected:
    int compArray[4];
    int populationCount, citiesCount;
    float budget, expenses;
    Cities citiesInProvinces[4];
    int profitLoss;

public:
    int getPopulationCount() {
        return populationCount;
    }

    float getBudget() {
        return budget;
    }

    float getExpenses() {
        return expenses;
    }

    float getCitiesCount() {
        return citiesCount;
    }

    int getBudgetOfCity() {
        return citiesInProvinces[0].getBudget();
    }

    int getProfitLoss() {
        return profitLoss;
    }

    void setCitiesCount(float citiesCount) {
        this->citiesCount = citiesCount;
    }

    void setPopulationCount(int populationCount) {
        this->populationCount = populationCount;
    }

    void setBudget(float budget) {
        this->budget = budget;
        for (int i = 0; i < citiesCount; i++) {
            totalExpenses(i);
            citiesInProvinces[i].setBudget(budget / citiesCount);
            this->expenses += citiesInProvinces[i].getExpenses();
        }
    }

    void totalExpenses(int i) {
        int n;
        cout << "\nEnter People Count: ";
        cin >> n;
        citiesInProvinces[i].setPopulationCount(n);
        citiesInProvinces[i].setExpenses(n * 100);
    }

    void setExpenses(float expenses) {
        this->expenses = expenses;
    }

    int calculateProfitLoss() {
        return (budget - expenses);
    }
};

class Country {
protected:
    int populationCount, n, provincesCount;
    float budget, expenses;
    Provinces provincesInCountry[4];

public:
    Country(int np, int bd, int cc) {
        setProvincesCount(np);
        provincesInCountry[np];
        setBudget(bd);
        for (int i = 0; i < np; i++) {
            cout << "\nProvince " << i + 1 << endl;
            provincesInCountry[i].setCitiesCount(cc);
            provincesInCountry[i].setBudget(budget / np);
        }
    }

    void show(int np) {
        for (int i = 0; i < np; i++) {
            cout << "   " << i + 1 << "              " << provincesInCountry[i].getCitiesCount() << "            " << provincesInCountry[i].getBudget() << "             " << provincesInCountry[i].getBudgetOfCity() << "          " << provincesInCountry[i].getExpenses() << endl;
            totalExpenses2(i);
        }
        cout << "\nCountry's Expenses: " << expenses << endl;
        highestExpensesProvince();
        cout << "\nProvince    Profit\n";
        for (int p = 0; p < np; p++) {
            cout << " " << p + 1 << "           " << provincesInCountry[p].calculateProfitLoss() << endl;
        }
    }

    void highestExpensesProvince() {
        int highestExpenseProvinceIndex = 0;
        float highestExpense = provincesInCountry[0].getExpenses();

        for (int i = 1; i < provincesCount; i++) {
            if (provincesInCountry[i].getExpenses() > highestExpense) {
                highestExpense = provincesInCountry[i].getExpenses();
                highestExpenseProvinceIndex = i;
            }
        }

        cout << "\nProvince with Highest Expense is : " << highestExpenseProvinceIndex + 1 << "              " << provincesInCountry[highestExpenseProvinceIndex].getCitiesCount() << "            " << provincesInCountry[highestExpenseProvinceIndex].getBudget() << "             " << provincesInCountry[highestExpenseProvinceIndex].getBudgetOfCity() << "          " << provincesInCountry[highestExpenseProvinceIndex].getExpenses() << endl;
    }

    int getPopulationCount() {
        return populationCount;
    }

    float getBudget() {
        return budget;
    }

    float getExpenses() {
        return expenses;
    }

    float getProvincesCount() {
        return provincesCount;
    }

    void setProvincesCount(float provincesCount) {
        this->provincesCount = provincesCount;
    }

    void setPopulationCount(int populationCount) {
        this->populationCount = populationCount;
    }

    void setBudget(float budget) {
        this->budget = budget;
    }

    void totalExpenses2(int i) {
        this->expenses += provincesInCountry[i].getExpenses();
    }
};

int main() {
    Country pakistan(5, 22092, 4);
    cout << "Province    Cities Count    Province Budget    Cities Budget    Expense\n";
    pakistan.show(5);
    return 0;
}
