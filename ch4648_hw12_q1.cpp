#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Money {
public:
    //Returns the sum of the values of amount1 and amount2.
    friend Money operator +(const Money& amount1, const Money& amount2) {
        return Money(0, amount1.all_cents + amount2.all_cents);
    }

    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount1, const Money& amount2) {
        return Money(0, amount1.all_cents - amount2.all_cents);
    }

    //Returns the negative of the value of amount.
    friend Money operator -(const Money& amount) {
        return Money (0, -amount.all_cents);
    }

    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator ==(const Money& amount1, const Money& amount2) {
        return (amount1.all_cents == amount2.all_cents);
    }

    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    Money(long dollars, int cents) {
        all_cents = dollars * 100 + cents;
    }

    //Initializes the object so its value represents $dollars.00.
    Money(long dollars) {
        all_cents = dollars * 100;
    }

    //Initializes the object so its value represents $0.00.
    Money() {
        all_cents = 0;
    }

    //Returns the amount of money recorded in the data portion of the calling
    //object.
    double get_value() const {
        return (double)all_cents / 100;
    }

    //Overloads the >> operator so it can be used to input values of type
    //Money.
    friend istream& operator >>(istream& ins, Money& amount) {
        double dollars;
        ins >> dollars;
        amount.all_cents = dollars * 100;
        return ins;
    }

    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    friend ostream& operator <<(ostream& outs, const Money& amount) {
        int positive_cents, dollars, cents;
        positive_cents = labs(amount.all_cents);
        dollars = positive_cents / 100;
        cents = positive_cents % 100;
        if (amount.all_cents < 0)
            outs << "-$" << dollars << '.';
        else
            outs << "$" << dollars << '.';
        if (cents < 10)
            outs << '0';
        outs << cents;
        return outs;
    }

private:
    long all_cents;
};

class Checkbook {
public:
    Checkbook(int num, double amount, bool if_cashed) {
        check_num = num;
        check_amt = Money(0, (long)(amount * 100));
        cashed = if_cashed;
    }

    int getNum() {
        return check_num;
    }

    bool getCashed(){
        return cashed;
    }

    Money getAmt() {
        return check_amt;
    }

    //Returns true if amount1 is less than amount2; false otherwise.
    friend bool operator <(const Checkbook& book1, const Checkbook& book2) {
        return (book1.check_num < book2.check_num);
    }

private:
    int check_num;
    Money check_amt;
    bool cashed;
};

int main() {
    int num; 
    double amount; 
    bool if_cashed;
    vector<Checkbook> checkbook;
    Money cashed, uncashed;
    Money deposit, total_deposit;
    vector <Money> deposits;
    Money prior_balance, new_balance;

    cout << "Please enter the check number, amount on check [exclude the dollar" 
         << " sign]\n"; 
    cout << "and whether or not the check has been cashed (by typing 1(Yes) or "
         << "0(No):\n";
    cout << endl;
    cout << "Example input: 9 for check number, 40.89 for amount and 1 for "
         << "being cashed (9 40.89 1)\n";
    cout << "End output by entering 0 for check number, 0.00 for amount and 0 "
         << "for being cashed (0 0.00 0)\n";
    cout << endl;

    while (cin >> num >> amount >> if_cashed) {
        if (num == 0 && amount == 0.00 && if_cashed == 0)
            break;
        checkbook.push_back(Checkbook(num, amount, if_cashed));
    }

    for (int i = 0; i < checkbook.size(); i++) {
        if (checkbook[i].getCashed())
            cashed = cashed + checkbook[i].getAmt();
        else
            uncashed = uncashed + checkbook[i].getAmt();
    }

    cout << "The sum of the cashed checks is:\n";
    cout << cashed << endl;
    cout << "The sum of the un-cashed checks is:\n";
    cout << uncashed << endl;
    cout << "Please enter the deposits (end deposit input by typing 0):\n";
    
    while (cin >> deposit) {
        if (deposit == 0)
            break;
        deposits.push_back(deposit);
    }

    for (int i = 0; i < deposits.size(); i++) {
        total_deposit = total_deposit + deposits[i];
    }

    cout << "The sum of the deposits is:\n";
    cout << total_deposit << endl;

    cout << "Please enter the prior balance amount:\n";
    cin >> prior_balance;

    cout << "Please enter the new balance amount according to account holder:\n";
    cin >> new_balance;

    Money only_cleared = prior_balance + total_deposit - cashed;
    
    cout << endl;
    cout << "The balance according to the bank which includes only cleared "
         << "checks is: " << only_cleared << endl;

    Money difference = only_cleared - new_balance;

    cout << "The difference between the account holders balance of " 
         << new_balance << " and bank balance of " << only_cleared << " is: "
         << difference << endl;

    cout << endl;
    cout << "The cashed checks are:\n";

    sort(checkbook.begin(), checkbook.end());

    for (int i = 0; i < checkbook.size(); i++) {
        if (checkbook[i].getCashed())
            cout << "Check number: " << checkbook[i].getNum() << " with amount: " 
                 << checkbook[i].getAmt() << endl;
    }

    cout << endl;
    cout << "The un-cashed checks are:\n";

    for (int i = 0; i < checkbook.size(); i++) {
        if (!checkbook[i].getCashed())
            cout << "Check number: " << checkbook[i].getNum() << " with amount: " 
                 << checkbook[i].getAmt() << endl;
    }

    return 0;
}