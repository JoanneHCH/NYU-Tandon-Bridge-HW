#include <iostream>
#include <cmath>

using namespace std;

int main(){
     double a, b, c, value, x_value1, x_value2;

     cout << "Please enter value of a: ";
     cin >> a;
     cout << "Please enter value of b: ";
     cin >> b;
     cout << "Please enter value of c: ";
     cin >> c;

     value = pow(b,2) - 4 * a * c;
     x_value1 = (-b + sqrt(value)) / (2 * a);
     x_value2 = (-b - sqrt(value)) / (2 * a);

     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);
     cout.precision(1);

     if((a==0) && (b==0) && (c==0))
        cout << "This equation has infinite number of solutions \n";
     else if(a == 0)  
        cout << "This equation has no solution \n";
     else if(value > 0) 
        cout << "This equation has two real solutions x=" << x_value1 << " or x=" << x_value2 << endl;
     else if(value == 0) 
        cout << "This equation has a single real solution x=" << x_value1 << endl;
     else if (value < 0)
        cout << "This equation has no real solution \n";
    
    return 0;
}