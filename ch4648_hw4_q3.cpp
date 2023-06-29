#include <iostream>
using namespace std;

int main(){
    int number, in_binary, mod, count;
    const int base = 10;

    cout << "Enter decimal number:\n";
    cin >> number;
    cout << "The binary representation of " << number;
    
    count = 1;
    for(in_binary = 0; number >= 1; count *= 10){
        mod = number % 2;
        number = number / 2;
        in_binary = in_binary + mod * count;
    }

    cout << " is " << in_binary << endl;
    
    return 0;
}