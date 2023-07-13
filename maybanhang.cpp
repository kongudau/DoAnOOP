#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

class VendingMachine {
private:
    vector<Product> products;
    double balance;
public:
    VendingMachine() : balance(0.0) {
        // Thêm sản phẩm vào máy bán hàng mẫu
        products.push_back({ "Coca-Cola", 1.5, 10 });
        products.push_back({ "Pepsi", 1.4, 15 });
        products.push_back({ "Water", 1.0, 20 });
    }

    void displayProducts() {
        cout << "==== Available Products ====" << endl;
        cout << setw(20) << left << "Name" << setw(10) << "Price ($)" << setw(10) << "Quantity" << endl;
        for (const auto& product : products) {
            cout << setw(20) << left << product.name << setw(10) << product.price << setw(10) << product.quantity << endl;
        }
    }

    void insertCoin(double amount) {
        balance += amount;
        cout << "Inserted $" << amount << ". Current balance: $" << balance << endl;
    }

    void purchaseProduct(int productIndex) {
        if (productIndex < 0 || productIndex >= products.size()) {
            cout << "Invalid product index." << endl;
            return;
        }

        Product& selectedProduct = products[productIndex];

        if (selectedProduct.quantity <= 0) {
            cout << "Out of stock for " << selectedProduct.name << "." << endl;
            return;
        }

        if (balance < selectedProduct.price) {
            cout << "Insufficient balance. Please insert more money." << endl;
            return;
        }

        selectedProduct.quantity--;
        balance -= selectedProduct.price;

        cout << "Purchased " << selectedProduct.name << " for $" << selectedProduct.price << "." << endl;
        cout << "Remaining balance: $" << balance << endl;
    }

    void returnChange() {
        cout << "Returning $" << balance << " as change." << endl;
        balance = 0.0;
    }
};

int main() {
    VendingMachine vendingMachine;

    while (true) {
        cout << "==== Vending Machine ====" << endl;
        vendingMachine.displayProducts();
        cout << "=========================" << endl;
        cout << "1. Insert coin" << endl;
        cout << "2. Purchase product" << endl;
        cout << "3. Return change" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the amount to insert: $";
            double amount;
            cin >> amount;
            vendingMachine.insertCoin(amount);
            break;
        case 2:
            cout << "Enter the product index: ";
            int productIndex;
            cin >> productIndex;
            vendingMachine.purchaseProduct(productIndex);
            break;
        case 3:
            vendingMachine.returnChange();
            break;
        case 0:
            cout << "Thank you for using the vending machine. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}