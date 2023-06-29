#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int num[10], input[5];
    int pin[5] = {1, 2, 3, 4, 5};
    cout << "Please enter your PIN according to the following mapping:\n";
    cout << "PIN: 0 1 2 3 4 5 6 7 8 9\n";
    cout << "NUM: ";
    
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        num[i] = rand() % 3 + 1;
        cout << num[i] << " ";
    }
    cout << endl;

    int number;
    cin >> number;
    for (int i = 4; i >= 0; i--) {
        input[i] = number % 10;
        number = number / 10;
    }

    bool correct = true;
    for (int i = 0; i < 5; i++) {
        if (num[pin[i]] != input[i]){
            correct = false;
            break;
        }
    }

    if (correct)
        cout << "Your PIN is correct\n";
    else
        cout << "Your PIN is not correct\n";
        
    return 0;
}