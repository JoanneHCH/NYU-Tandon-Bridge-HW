#include <iostream>
#include <cmath>
using namespace std;

// Enter a positive integer num, and prints all of num’s divisors in an 
// ascending order, separated by a space.
void printDivisors(int num);

int main() {
    int n, output;
    cout << "Please enter a positive integer >= 2: ";
    cin >> n;
    
    printDivisors(n);

    cout << endl;
    return 0;
}

void printDivisors(int num) {
    for (int divisor = 1; divisor <= sqrt(num); divisor++) {
        if (num % divisor == 0)
            cout << divisor << ' '; 
    }
    for (int divisor = sqrt(num); divisor > 0; divisor--) {    
        if(num % divisor == 0) {
            if (divisor != num / divisor)
                cout << num / divisor << ' '; 
        }        
    }   
}