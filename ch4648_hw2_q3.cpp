#include <iostream>

using namespace std;

/*Please enter the number of days John has worked: 2
Please enter the number of hours John has worked: 12
Please enter the number of minutes John has worked: 15
Please enter the number of days Bill has worked: 3 Please enter the number of hours Bill has worked: 15 Please enter the number of minutes Bill has worked: 20
The total time both of them worked together is: 6 days, 3 hours and 35 minutes.*/

int main(){

    int John_days, John_hours, John_minutes, Bill_days, Bill_hours, Bill_minutes;
    cout << "Please enter the number of days John has worked: ";
    cin >> John_days;

    cout << "Please enter the number of hours John has worked: ";
    cin >> John_hours;

    cout << "Please enter the number of minutes John has worked: ";
    cin >> John_minutes;

    cout << "\n";

    cout << "Please enter the number of days Bill has worked: ";
    cin >> Bill_days;

    cout << "Please enter the number of hours Bill has worked: ";
    cin >> Bill_hours;

    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> Bill_minutes;

    cout << "\n";

    int total_minutes = (John_days + Bill_days) * 24 * 60 + \
                        (John_hours + Bill_hours) * 60 + \
                        (John_minutes + Bill_minutes);
    int days = total_minutes / (60 * 24);
    int r_minutes = total_minutes % (60 * 24);
    int hours = r_minutes / 60;
    int minutes = r_minutes % 60;
    
    cout << "The total time both of them worked together is: " \
         << days << " days, " << hours << " hours and " << minutes << " minutes.\n";

    return 0;    
}