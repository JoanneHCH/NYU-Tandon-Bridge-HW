#include <iostream>
//#include <iomanip> // input output manipulation library
using namespace std;

int main(){

    int n, line, count;
    cout << "Please enter a positive integer: \n";
    cin >> n;

    // for (int row = 1; row <= n; ++row) {
    //     for (int col = 1; col <= n; ++col) {
    //         cout << setw(6) << left << row * col;
    //     }
    //     cout << endl;
    // }

    for (line = 1; line <= n; line++) {
        for (count = 1; count<= n; count++) {
            cout << count * line << "\t";
        }
        cout << endl;
    }
    return 0;
}