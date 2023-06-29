#include <iostream>

using namespace std;
/*Please enter your amount in the format of dollars and cents separated by a space:
4 37
4 dollars and 37 cents are:
17 quarters, 1 dimes, 0 nickels and 2 pennies
*/
int main() {

    int dollars, cent;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";
    cin >> dollars >> cent;
    cout << dollars << " dollars and " << cent << " cents are:\n";

    int total_cent = (dollars * 100) + cent;
    int quarters = total_cent / 25;
    int r_quarters = total_cent % 25;
    int dimes = r_quarters / 10;
    int r_dimes = r_quarters % 10;
    int nickels = r_dimes / 5;
    int pennies = r_dimes % 5;

    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies\n";

    return 0;
}
