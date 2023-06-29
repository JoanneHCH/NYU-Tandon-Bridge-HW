#include <iostream>
using namespace std;

int main(){
    double real_number, differ;
    int round_method, floor, ceiling, nearest;

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    cout << "Please enter a Real number: \n";
    cin >> real_number;
    cout << "Choose your rounding method:\n"
    "1. Floor round\n"
    "2. Ceiling round\n"
    "3. Round to the nearest whole number\n";
    cin >> round_method;

    switch(round_method){
        case FLOOR_ROUND:
            if ((real_number >= 0) || (real_number == (int)real_number))
                floor = real_number;
            else
                floor = real_number - 1;
            cout << floor << endl;
            break;
        case CEILING_ROUND:
            if ((real_number <= 0) || (real_number == (int)real_number))
                ceiling = real_number;
            else
                ceiling = real_number + 1;
            cout << ceiling << endl;
            break; 
        case ROUND:
            differ = real_number-(int)real_number;
            if (real_number >= 0){
                if (differ < 0.5)
                    nearest = real_number;
                else
                    nearest = real_number + 1;
            } 
            else
                if (differ > -0.5)
                    nearest = real_number;
                else
                    nearest = real_number - 1;
            cout << nearest << endl;
            break; 
    }

    return 0;
}