#include <iostream>

using namespace std;
/*Please enter two positive integers, separated by a space:
14 4
14 + 4 = 18
14 – 4 = 10 14 * 4 = 56 14 / 4 = 3.5 14 div 4 = 3 14 mod 4 = 2*/

int main(){
    unsigned x, y;
    cout << "Please enter two positive integers, separated by a space:\n"; 
    cin >> x >> y;

    cout << x << " + " << y << " = " << x + y << "\n";
    cout << x << " - " << y << " = " << x - y << "\n";
    cout << x << " * " << y << " = " << x * y << "\n";
    cout << x << " / " << y << " = " << (float)x / y << "\n";
    cout << x << " div " << y << " = " << x / y << "\n";
    cout << x << " mod " << y << " = " << x % y << "\n";

    return 0;
}