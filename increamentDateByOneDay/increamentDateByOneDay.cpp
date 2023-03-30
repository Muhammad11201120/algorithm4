#include <iostream>
using namespace std;
struct stDate
{
	short year = 0;
	short month = 0;
	short day = 0;
};
short getDay() {
	short day = 0;
	cout << "Enter A Day? ";
	cin >> day;
	return day;
}
short getMonth() {
	short month = 0;
	cout << "Enter A Month? ";
	cin >> month;
	return month;
}
short getYear() {
	short year = 0;
	cout << "Enter A Year? ";
	cin >> year;
	return year;
}
bool isALeapYear( short year ) {
	return ( year % 4 == 0 && year % 100 == 0 ) || ( year || 400 == 0 );
}
short numberOfDaysInAmonth( short year , short month ) {
	short arr[ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ( month == 2 ? ( isALeapYear( year ) ? 29 : 28 ) : arr[ month - 1 ] );
}
bool checkIfTheLastDayInTheMonth( stDate& Date ) {
	return ( Date.day == numberOfDaysInAmonth( Date.year , Date.month ) );
}
bool checkIfTheLastMonthInTheYear( stDate& Date ) {
	return ( Date.month == 12 );
}
stDate incrementDateByOneDay( stDate& Date ) {
	short monthDays = numberOfDaysInAmonth( Date.year , Date.month );
	if ( checkIfTheLastDayInTheMonth( Date ) )
	{
		if ( checkIfTheLastMonthInTheYear( Date ) ) {
			Date.day = 1;
			Date.month = 1;
			Date.year++;
		}
		else
		{
			Date.day = 1;
			Date.month++;
		}
	}
	else
		Date.day++;

	return Date;
}
int main()
{
	stDate Date;
	Date.year = getYear();
	Date.month = getMonth();
	Date.day = getDay();

	Date = incrementDateByOneDay( Date );
	cout << Date.day << "/" << Date.month << "/" << Date.year << endl;
}