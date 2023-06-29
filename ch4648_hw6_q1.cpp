#include <iostream>
using namespace std;

int fib(int n);
//Returns the n-th element of the Fibonacci sequence.

int main() {
    int num, value;
    cout << "Please enter a positive integer: ";
    cin >> num;
    value = fib (num);
    cout << value << endl;

    return 0;
}

int fib(int n) {
    int F1 = 1, F2 = 1, value = 0;
    
    if(n < 3) 
        return 1;
    else {
        for (int count = 3; count <= n; count ++) {
            value = F1 + F2;
            F1 = F2;
            F2 = value;
        }
        return(value); 
    }
}

