#include <iostream>
using namespace std;

int main(){
    float first_price, second_price, tax_rate, after_discount, total_price;
    char card;

    cout << "Enter price of first item: ";
    cin >> first_price;
    cout << "Enter price of second item: ";
    cin >> second_price;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> card;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: "; 
    cin >> tax_rate;
    
    if (first_price >= second_price){
        if (card == 'y' || card == 'Y') //wrong -> (card == ('y' | 'Y'))
            after_discount = (second_price / 2 + first_price) * 0.9;
        else
            after_discount = (second_price / 2) + first_price;
    }      
    else {
        if (card == 'y' || card == 'Y') //wrong -> (card == ('y' | 'Y'))
            after_discount = (second_price + first_price / 2) * 0.9;
        else
            after_discount = second_price + first_price / 2;
    }

    total_price = after_discount * (tax_rate / 100 + 1);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "Base price: " << first_price + second_price << endl;
    cout << "Price after discounts: " << after_discount << endl;
    
    cout.precision(5);
    cout << "Total price: " << total_price << endl;   

    return 0;
}