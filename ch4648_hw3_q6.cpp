#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string day;
    char temp;
    int hour, minute, length;
    double cost;

    cout << "Please enter the day of the week (Mo/Tu/We/Th/Fr/Sa/Su): ";
    cin >> day;
    cout << "Please enter the time the call started in 24-hour notation: ";
    cin >> hour >> temp >> minute;
    cout << "Please enter the length of the call in minutes: ";
    cin >> length;

    if ((day == "Sa") || (day == "Su"))
        cost = length * 0.15;
    else{
        if ((hour >= 8) && (hour < 18))
            cost = length * 0.4;
        else 
            cost = length * 0.25;
        }
        
    cout << "The cost of the call: $" << cost << endl;

    return 0;
}