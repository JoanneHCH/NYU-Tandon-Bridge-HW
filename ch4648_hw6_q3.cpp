#include <iostream>
using namespace std;
// Enter a positive integer n, and returns an approximation of e, calculated by 
// the sum of the first (n+1) addends of the infinite sum above.
double eApprox(int n);
int main() {
    cout.precision(30);
    for (int n = 1; n <= 15; n++) 
        cout << "n = " << n << '\t' << eApprox(n) <<endl; 

    return 0;
}
double eApprox(int n){
    double result = 1, denom = 1;
    for (int i = 1; i <= n; i++){
        denom = denom * i;
        result = result + (1 / denom);
    }
    return (result);
}


