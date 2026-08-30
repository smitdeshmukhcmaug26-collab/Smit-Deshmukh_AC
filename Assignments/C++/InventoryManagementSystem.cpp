#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Product {
private:
    int productID;
    string name;
    double price;
    int quantity;
    static int productCount;

public:
    Product() {
        productCount++;
        productID = 1000 + productCount;
        name = "Unassigned";
        price = 0.0;
        quantity = 0;
    }

    void setName(string n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "Name cannot be empty!" << endl;
        }
    }

    string getName() const {
        return name;
    }

    void setPrice(double p) {
        if (p <= 0) {
            cout << "Price cannot be negative or zero!" << endl;
        } else {
            price = p;
        }
    }

    double getPrice() const {
        return price;
    }

    void setQuantity(int q) {
        if (q < 0) {
            cout << "Quantity cannot be negative!" << endl;
        } else {
            quantity = q;
        }
    }

    int getQuantity() const {
        return quantity;
    }

    void acceptDetails() {
        string inName;
        double inPrice;
        int inQuantity;

        while (true) {
            cout << "Enter the name of the product: ";
            cin >> ws; 
            getline(cin, inName);
            setName(inName);
            if (name == inName)
                break;
        }

        while (true) {
            cout << "Enter the price of the product: ";
            cin >> inPrice;
            setPrice(inPrice);
            if (price == inPrice)
                break;
            else {
            cout << "Invalid input! Please enter a valid numeric price." << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            }
        }

        while (true) {
            cout << "Enter the quantity of the product: ";
            cin >> inQuantity;
            setQuantity(inQuantity);
            if (quantity == inQuantity)
                break;
            else {
            cout << "Invalid input! Please enter a valid numeric quantity." << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            }
        }
    }

    double totalValue() const {
        return price * quantity;
    }


    void displayDetails() const {
        cout << left << setw(8)  << productID
             << setw(14) << name
             << setw(10) << fixed << setprecision(2) << price
             << setw(8)  << quantity
             << setw(12) << totalValue();
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }
};


int Product::productCount = 0;

int main() {
    Product inventory[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nEnter Details for Product " << (i + 1) << endl;
        inventory[i].acceptDetails();
    }

    cout << "\n===== INVENTORY REPORT =====\n";
    cout << left << setw(8)  << "ID"
         << setw(14) << "Name"
         << setw(10) << "Price"
         << setw(8)  << "Qty"
         << setw(12) << "Total Value" << endl;

    int threshold = 10;

    for (int i = 0; i < 5; i++) {
        inventory[i].displayDetails();
        if (inventory[i].isLowStock(threshold)) {
            cout << "    <----LOW STOCK";
        }
        cout << endl;
    }

    int maxVal = 0;
    for (int i = 1; i < 5; i++) {
        if (inventory[i].totalValue() > inventory[maxVal].totalValue()) {
            maxVal = i;
        }
    }

    cout << "\nHighest Value Product : " << inventory[maxVal].getName() 
         << " (Rs. " << fixed << setprecision(2) << inventory[maxVal].totalValue() << ")" << endl;

    cout << "Low Stock (threshold: " << threshold << ") : ";
    bool first = true;
    for (int i = 0; i < 5; i++) {
        if (inventory[i].isLowStock(threshold)) {
            if (!first) cout << ", ";
            cout << inventory[i].getName();
            first = false;
        }
    }
    if (first) {
        cout << "None";
    }
    cout << endl;

    return 0;
}