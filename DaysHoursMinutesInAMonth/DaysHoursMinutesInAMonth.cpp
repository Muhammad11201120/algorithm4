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
short numberOfDaysInMonth(int year, short month) {
	if (month < 1 || month>12)
	{
		return 0;
	}
	if (month == 2)
	{
		if (isAleapYear(year))
		{
			return 29;
		}
		return  28;
	}
	short arr[7] = { 1,3,5,7,8,10,12 };//months that have 31 days
	for (short i = 0; i <= 7; i++)
	{
		if (arr[i - 1] == month)
		{
			return 31;
		}
	}
	return 30; // if not month 2 or month with 31 days 
}
bool shortHandNumberOfDaysInMonth(int year, short month) {
	if (month < 1 || month > 12)
		return 0;
	short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isAleapYear(year) ? 29 : 28) : arr[month - 1];
}
short numberOfHoursInMonth(int year, short month) { return numberOfDaysInMonth(year, month) * 24; }
int numberOfMinutesInMonth(int year, short month) { return numberOfHoursInMonth(year, month) * 60; }
int numberOfSecondsInMonth(int year, short month) { return numberOfMinutesInMonth(year, month) * 60; }
int main()
{
	int year = readNumber();
	short month = readNumber();
	cout << "Number Of Days " << month << " => " << numberOfDaysInMonth(year, month) << endl;
	cout << "Number Of Hours " << month << " => " << numberOfHoursInMonth(year, month) << endl;
	cout << "Number Of Minutes " << month << " => " << numberOfMinutesInMonth(year, month) << endl;
	cout << "Number Of Seconds " << month << " => " << numberOfSecondsInMonth(year, month) << endl;
}
