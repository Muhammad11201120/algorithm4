// how to print out hello world in c++

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
enum enDays
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};
int readNumber(string msg)
{
    int number;
    cout << msg;
    cin >> number;
    return number;
}
bool isAleapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
string date(int year, short month, short day)
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}
short numberOfDaysInMonth(int year, short month)
{
    if (month < 1 || month > 12)
    {
        return 0;
    }
    short arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (isAleapYear(year) ? 29 : 28) : arr[month - 1];
}
enDays calculateDayOfYear(int year, short month, short day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + (12 * a) - 2;
    int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return (enDays)d;
}
string getDay(enDays day)
{
    switch (day)
    {
    case enDays::Sunday:
        return "Sunday";
    case enDays::Monday:
        return "Monday";
    case enDays::Tuesday:
        return "Tuesday";
    case enDays::Wednesday:
        return "Wednesday";
    case enDays::Thursday:
        return "Thursday";
    case enDays::Friday:
        return "Friday";
    case enDays::Saturday:
        return "Saturday";
    }
}
string monthName(short month)
{
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}

void printMonthClaender(int year, short month)
{
    int numberOfDays;
    int current = calculateDayOfYear(year, month, 1);
    numberOfDays = numberOfDaysInMonth(year, month);
    cout << "--------------------" << monthName(month).c_str() << "----------------------" << endl;
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
    int i;
    for (i = 0; i < current; i++)
    {
        printf("   ");
    }
    for (int j = 1; j <= numberOfDays; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            cout << endl;
        }
    }
    cout << "\n----------------------------------------------" << endl;
}

int main()
{
    int year = readNumber("Enter A Year: ");
    short month = readNumber("Enter A Month: ");
    short day = readNumber("Enter A Day: ");
    printMonthClaender(year, month);
    return 0;
}
