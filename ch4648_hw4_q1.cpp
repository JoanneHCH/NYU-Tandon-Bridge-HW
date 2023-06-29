#include <iostream>
using namespace std;

int main(){

    cout << "section a" << endl;

    int integer, count;
    cout << "Please enter a positive integer: ";
    cin >> integer;

    count = 1;
    while(count <= integer){
            cout << count * 2 << endl;
            count++;
    }

    cout << "section b" << endl;
    
    int integer_b, count_b;
    cout << "Please enter a positive integer: ";
    cin >> integer_b;

    for(count_b = 1; count_b <= integer_b; count_b++)
        cout << count_b * 2 << endl;

    return 0;
}