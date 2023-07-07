#include<iostream>
using namespace std;

class Laptop {
    string productName;
    int modelNumber, price;
    float sellingPrice;
public:
    // Price
    void setPrice(int a) {
        price = a;
    }
    int getPrice() {
        return price;
    }
    // Model Number
    void setModelNumber(int a) {
        modelNumber = a;
    }
    int getModelNumber() {
        return modelNumber;
    }
    // Product Name
    void setProductName(string a) {
        productName = a;
    }
    string getProductName() {
        return productName;
    }
    void setSellingPrice(int a) {
        a = a / 100;
        sellingPrice = price / (1 - a);
    }
    float getSellingPrice() {
        return sellingPrice;
    }
};

class Mobile {
    string productName;
    int modelNumber, price;
    float sellingPrice;
public:
    // Price
    void setPrice(int a) {
        price = a;
    }
    int getPrice() {
        return price;
    }
    // Model Number
    void setModelNumber(int a) {
        modelNumber = a;
    }
    int getModelNumber() {
        return modelNumber;
    }
    // Product Name
    void setProductName(string a) {
        productName = a;
    }
    string getProductName() {
        return productName;
    }
    void setSellingPrice(int a) {
        a = a / 100;
        sellingPrice = price / (1 - a);
    }
    float getSellingPrice() {
        return sellingPrice;
    }
};

int main() {
    int numLaptops, numMobiles, a, b;
    float profit = 0.00;
    string name = " ";
    cout << "Enter Number of Laptops: ";
    cin >> a;
    cout << "\nEnter Number of Mobiles: ";
    cin >> b;
    Laptop laptops[a];
    Mobile mobiles[b];
    int i = 0;
    while (i < a) {
        cout << "\nEnter Laptop Name: ";
        fflush(stdin);
        getline(cin, name);
        laptops[i].setProductName(name);
        cout << "\nEnter Laptop's Model Number: ";
        cin >> numLaptops;
        laptops[i].setModelNumber(numLaptops);
        cout << "\nEnter Laptop's Price: ";
        cin >> numLaptops;
        laptops[i].setPrice(numLaptops);
        i = i + 1;
    }
    int j = 0;
    while (j < b) {
        cout << "\nEnter Mobile Name: ";
        fflush(stdin);
        getline(cin, name);
        mobiles[j].setProductName(name);
        cout << "\nEnter Mobile's Model Number: ";
        cin >> numMobiles;
        mobiles[j].setModelNumber(numMobiles);
        cout << "\nEnter Mobile's Price: ";
        cin >> numMobiles;
        mobiles[j].setPrice(numMobiles);
        j = j + 1;
    }
    cout << "\nEnter Margin: ";
    cin >> numLaptops;
    j = 0;
    while (j < 2) {
        mobiles[j].setSellingPrice(numLaptops);
        mobiles[j].setPrice(mobiles[j].getSellingPrice());
        profit = profit + mobiles[j].getPrice();
        j = j + 1;
    }
    j = 0;
    while (j < 2) {
        laptops[j].setSellingPrice(numLaptops);
        laptops[j].setPrice(laptops[j].getSellingPrice());
        profit = profit + laptops[j].getPrice();
        j = j + 1;
    }
    i = 0;
    cout << "\n     Laptops\n";
    while (i < a) {
        cout << "\n   Name: " << laptops[i].getProductName() << endl << "   Model Number: " << laptops[i].getModelNumber() << endl;
        i = i + 1;
    }
    cout << "\n     Mobiles\n";
    i = 0;
    while (i < b) {
        cout << "\n   Name: " << mobiles[i].getProductName() << endl << "   Model Number: " << mobiles[i].getModelNumber() << endl;
        i = i + 1;
    }
    cout << endl << "TOTAL PROFIT: " << profit;
    return 0;
}
