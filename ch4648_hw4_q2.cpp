#include <iostream>
#include <string>
using namespace std;

int main(){

    int number, Value;
    string M, D, C, L, X, V, I;

    cout << "Enter decimal number:\n";
    cin >> Value;
    number = Value;
    
    while (number >= 1000){
        number = number - 1000;
        M = M + "M";
    }

    if (number % 1000 >= 500)
        D = "D";
    
    int number_500R = number % 500;
    while  (number_500R > 100){
        number_500R = number_500R - 100;
        C = C + "C";
    }

    if (number % 100 >= 50)
        L = "L";
    
    int number_50R = number % 50;
    while  (number_50R > 10){
        number_50R = number_50R - 10;
        X = X + "X";
    }

    if (number % 10 >= 5)
        V = "V";

    int number_5R = number % 5;
    while  (number_5R >= 1){
        number_5R = number_5R - 1;
        I = I + "I";
    }

    string Roman_digits = M + D + C + L + X + V + I;
    cout << Value << " is " << Roman_digits << endl;

    return 0;
}