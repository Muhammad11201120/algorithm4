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
int main()
{
    int year = readNumber();
    if (isAleapYear(year))
    {
        cout << year << " It Is A Leap Year.." << endl;
    }
    else
    {
        cout << year << " It Is Not A Leap Year.." << endl;
    }
}
