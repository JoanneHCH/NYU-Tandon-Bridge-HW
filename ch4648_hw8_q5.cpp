#include <iostream>
#include <string>
using namespace std;
int main() {
    string first, middle, last;
    cout << "Please enter your first name, then middle name or initial, and "
         << "then last name.\n";
    cin >> first >> middle >> last;
    
    int length = middle.length(); 
    string m_initial = middle.erase(1,length - 1); 
    cout << last << ", " << first << " " << m_initial << ".\n";

    return 0;
}