#include <iostream>
using namespace std;

/*
Please enter number of coins:
# of quarters: 13
# of dimes: 4
# of nickels: 11
# of pennies: 17
The total is 4 dollars and 37 cents
*/

int main() {

	int quarters, dimes, nickels, pennies;

	cout << "Please enter number of coins:\n";
	cout << "# of quarters: ";
	cin >> quarters; //0.25
	
	cout << "# of dimes: ";
	cin >> dimes; //0.1

	cout << "# of nickels: ";
	cin >> nickels; //0.05

	cout << "# of pennies: ";
	cin >> pennies; //0.01

    int total_cents = (25 * quarters) + (10 * dimes) + (5 * nickels) + (1 * pennies);
	int dollars = total_cents / 100;
	int cents = total_cents % 100;

	cout << "The total is " << dollars << " dollars and " << cents << " cents\n";
	
	return 0;
}
