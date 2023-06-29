#include <iostream>
#include <string>
using namespace std;

int main(){
    string name, status;
    int graduation_year, current_year, year;
    
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> graduation_year;
    cout << "Please enter current year: ";
    cin >> current_year;

    year = graduation_year-current_year;
    if(year > 4)
        status = "not in college yet";
    else if (year == 4)
        status = "a Freshman";
    else if (year == 3)
        status = "a Sophomore";
    else if (year == 2)
        status = "a Junior";
    else if (year == 1)
        status = "a Senior";
    else
        status = "graduated"; 
    
    cout << name << ", " << "you are " << status << endl;
    
    return 0;
}