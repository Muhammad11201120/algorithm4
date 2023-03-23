#include <iostream>
using namespace std;
int readNumber() {
    int number;
    cout << "Enter A Year To Check If Is it A Leap Year Or Not: ";
    cin >> number;
    return number;
}
bool isAleapYear(int year) {
    //if year % 4 = 0 (true) && if century yars that %400(true)
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInYear(short year){return isAleapYear(year) ? 366 : 365;}
short numberOfHoursInYear(short year){return numberOfDaysInYear(year) * 24;}
int numberOfMinutesInYear(short year) { return numberOfHoursInYear(year) * 60; }
int numberOfSecondsInYear(short year) { return numberOfMinutesInYear(year) * 60; }
int main()
{
    int year = readNumber();
    cout << "Number Of Days => " << numberOfDaysInYear(year) << endl;
    cout << "Number Of Hours => " << numberOfHoursInYear(year) << endl;
    cout << "Number Of Minutes => " << numberOfMinutesInYear(year) << endl;
    cout << "Number Of Seconds => " << numberOfSecondsInYear(year) << endl;
}
