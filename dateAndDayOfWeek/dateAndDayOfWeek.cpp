#include <iostream>
#include <string>
using namespace std;
enum enDays
{
	Sunday, Monday, Tuesday, Wednesday, Thuresday, Friday, Saturday
};
int readNumber(string msg) {
	int number;
	cout << msg;
	cin >> number;
	return number;
}
bool isAleapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
string date(int year, short month, short day) {
	return  to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}
short numberOfDaysInMonth(int year, short month) {
	if (month < 1 || month > 12)
		return 0;
	short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isAleapYear(year) ? 29 : 28) : arr[month - 1];
}
enDays calculateDayOfYear(int year, short month, short day) {
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + (12 * a) - 2;

	int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return (enDays)d;
}
string getDay(enDays day) {
	switch (day)
	{
	case enDays::Sunday:
		return "Sunday";
	case enDays::Monday:
		return "Monday";
	case enDays::Tuesday:
		return "Tuesday";
	case enDays::Wednesday:
		return "Wedensday";
	case enDays::Thuresday:
		return "Thuresday";
	case enDays::Friday:
		return "Friday";
	case enDays::Saturday:
		return "Saturday";
	}
}
int main()
{
	int year = readNumber("Enter A Year: ");
	short month = readNumber("Enter A Month: ");
	short day = readNumber("Enter A Day: ");
	cout << "Date: " << date(year, month, day) << endl;
	cout << "Day Order Is: " << calculateDayOfYear(year, month, day) << endl;
	cout << "Day is: " << getDay(calculateDayOfYear(year, month, day)) << endl;
	return 0;
}
