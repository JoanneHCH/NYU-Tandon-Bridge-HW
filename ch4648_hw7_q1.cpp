#include <iostream>
using namespace std;
int printMonthCalender(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);
bool leapYear (int year);
int main() {
    int year, firstDay;
    cout << "Please enter a year and the starting day: ";
    cin >> year >> firstDay;
    cout << endl;

    printYearCalender(year, firstDay);

    return 0;
}

bool leapYear (int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

void printYearCalender(int year, int startingDay) {
    int monthDays, lastDay;
    int IfleapYear = leapYear (year);
    
    for (int month = 1; month < 13; month++){
        if (month == 1){
            cout << "January " << year << endl;
            monthDays = 31;

        }else if (month == 2){
            cout << "February " << year << endl;
            if (IfleapYear == 1)
                monthDays = 29;
            else
                monthDays = 28;
        }else if (month == 3){
            cout << "March " << year << endl;
            monthDays = 31;
        }else if (month == 4){
            cout << "April " << year << endl;
            monthDays = 30;
        }else if (month == 5){
            cout << "May " << year << endl;
            monthDays = 31;
        }else if (month == 6){
            cout << "June " << year << endl;
            monthDays = 30;
        }else if (month == 7){
            cout << "July " << year << endl;
            monthDays = 31;
        }else if (month == 8){
            cout << "August " << year << endl;
            monthDays = 31;
        }else if (month == 9){
            cout << "September " << year << endl;
            monthDays = 30;
        }else if (month == 10){
            cout << "October " << year << endl;
            monthDays = 31;
        }else if (month == 11){
            cout << "November " << year << endl;
            monthDays = 30;
        }else if (month == 12){
            cout << "December " << year << endl;
            monthDays = 31;
        }
        lastDay = printMonthCalender(monthDays, startingDay);
        startingDay = lastDay + 1;
        cout << endl;
    }
}

int printMonthCalender(int numOfDays, int startingDay) {
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";
    
    for (int space = 1; space < startingDay; space++)
        cout << " \t";
        
    int daySpace = startingDay - 1;
    for (int day = 1; day <= numOfDays; day++) {
        cout << day << "\t";
        if ((daySpace + day) % 7 == 0)
            cout << endl;    
    }    
    cout << endl;
    return ((daySpace + numOfDays) % 7);
}