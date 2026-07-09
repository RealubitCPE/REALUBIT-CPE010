#include <iostream>
using namespace std;

int main(){
    // Cashiering
    int price_1, price_2, price_3;
    int payment, change, total_price;

    cout << "Price of item 1: ";
    cin >> price_1;

    cout << "Price of item 2: ";
    cin >> price_2;

    cout << "Price of item 3: ";
    cin >> price_3;

    cout << "Payment: ";
    cin >> payment;

    total_price = price_1 + price_2 + price_3;
    change = payment - total_price;

    // Transaction Receipt
    cout << "\n Transaction Receipt " << endl;
    cout << "Item 1: " << price_1 << endl;

    cout << "Item 2: " << price_2 << endl;

    cout << "Item 3: " << price_3 << endl;
    
    cout << "Total: " << total_price << endl;

    cout << "Payment: " << payment << endl;

    cout << "Change: " << change << endl;

    return 0;
}