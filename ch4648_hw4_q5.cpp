#include <iostream>
using namespace std;

int main(){

    int n, space, line, star;

    cout << "Pleace input a positive integer n: ";
    cin >> n;
    
    for(line = n ; line >= 1 ; line--) {
        for(space = 0 ; space < (n - line) ; space++)
            cout << " ";

        for(star = 2 * line - 1 ; star > 0; star--)
            cout << "*";

        cout << endl;
    }

     
    for(line = 1 ; line <= n ; line++){
        
        for(space = 1 ; space <= (n - line) ; space++)
            cout << " ";

        for(star = 1 ; star <= 2 * line - 1 ; star++)
            cout << "*";
        
        cout << endl;        
    }

    return 0;
}