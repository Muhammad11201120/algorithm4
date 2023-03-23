#include <iostream>
using namespace std;
int readNumber() {
	int number;
	cout << "Enter A Year To Check If Is it A Leap Year Or Not: ";
	cin >> number;
	return number;
}
bool isAleapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInMonth(short year) { return isAleapYear(year) ? 29 : 28; }
short numberOfHoursInMonth(short year) { return numberOfDaysInMonth(year) * 24; }
int numberOfMinutesInMonth(short year) { return numberOfHoursInMonth(year) * 60; }
int numberOfSecondsInMonth(short year) { return numberOfMinutesInMonth(year) * 60; }
int main()
{
	int year = readNumber();
	short month = readNumber();
	cout << "Number Of Days " << month << " => " << numberOfDaysInMonth(year) << endl;
	cout << "Number Of Hours " << month << " => " << numberOfHoursInMonth(year) << endl;
	cout << "Number Of Minutes " << month << " => " << numberOfMinutesInMonth(year) << endl;
	cout << "Number Of Seconds " << month << " => " << numberOfSecondsInMonth(year) << endl;
}
