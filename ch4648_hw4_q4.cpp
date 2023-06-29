#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout<< "section a" <<endl;

    int lenth, sequence, count, in_pow = 1;
    double geometric;

    cout << "Please enter the length of the sequence: ";
    cin >> lenth;
    cout << "Please enter your sequence:\n";
    
    for (count = 1 ; count <= lenth ; count++){
        cin >> sequence;
        in_pow = in_pow * sequence;
    }

    geometric = pow(in_pow , (1 / (double)lenth));

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    cout << "The geometric mean is: " << geometric << endl;


    cout<< "section b" <<endl;

    int sequence_2, count_2, in_pow_2 = 1;
    double geometric_2;

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your \n"
         << "sequence by typing -1:\n";
    
    count_2 = 0;
    while (sequence_2 >= 0){
        cin >> sequence_2;
        if (sequence_2 == -1)
            break;
        in_pow_2 = in_pow_2 * sequence_2;
        count_2++;
    }
    
    geometric_2 = pow(in_pow_2 , 1.0 / count_2);
    cout << "The geometric mean is: " << geometric_2 << endl;

    return 0;
}