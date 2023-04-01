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
short getDaysToAdd() {
	short d = 0;
	cout << "Enter Days To Sub? ";
	cin >> d;
	return d;
}
short getWeeksToAdd() {
	short w = 0;
	cout << "Enter A Weeks To Sub? ";
	cin >> w;
	return w;
}
short getMonthsToADD() {
	short m = 0;
	cout << "Enter A Months To Sub? ";
	cin >> m;
	return m;
}
short getYearsToAdd() {
	short y = 0;
	cout << "Enter A Years To Sub? ";
	cin >> y;
	return y;
}
short getDecadesToAdd() {
	short d = 0;
	cout << "Enter A Decades To Sub? ";
	cin >> d;
	return d;
}
bool isALeapYear( short year ) {
	return ( year % 4 == 0 && year % 100 == 0 ) || ( year || 400 == 0 );
}
short numberOfDaysInAmonth( short year , short month ) {
	short arr[ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ( month == 2 ? ( isALeapYear( year ) ? 29 : 28 ) : arr[ month - 1 ] );
}
bool checkIfTheFirstDayInTheMonth( stDate& Date ) {
	return  ( Date.day == 1 );
}
bool checkIfTheFirstMonthInTheYear( stDate& Date ) {
	return ( Date.month == 1 );
}
stDate decreaseDateByOneDay( stDate Date ) {
	if ( checkIfTheFirstDayInTheMonth( Date ) )
	{
		if ( checkIfTheFirstMonthInTheYear( Date ) )
		{
			Date.day = numberOfDaysInAmonth( Date.year , Date.month );
			Date.month = 12;
			Date.year--;
		}
		else
		{
			Date.day = numberOfDaysInAmonth( Date.year , Date.month );
			Date.month--;
		}
	}
	else
	{
		Date.day--;
	}
	return Date;
}
stDate decreaseDateByXDays( stDate Date , short daysToSub ) {
	for ( short i = 0; i < daysToSub; i++ )
	{
		Date = decreaseDateByOneDay( Date );
	}
	return Date;
}
stDate decreaseDateByOneWeek( stDate Date ) {
	for ( short i = 0; i < 7; i++ )
	{
		Date = decreaseDateByOneDay( Date );
	}
	return Date;
}
stDate decreaseDateByXWeeks( stDate Date , short weeksToSub ) {
	for ( short i = 0; i < weeksToSub; i++ )
	{
		Date = decreaseDateByOneWeek( Date );
	}
	return Date;
}
stDate decreaseDateByOneMonth( stDate Date ) {
	if ( Date.month == 1 )
	{
		Date.month = 12;
		Date.year--;
	}
	else
	{
		Date.month--;
	}
	short numberOfDaysInCurrentMonth = numberOfDaysInAmonth( Date.year , Date.month );
	if ( Date.day > numberOfDaysInCurrentMonth )
	{
		Date.day = numberOfDaysInCurrentMonth;
	}
	return Date;
}
stDate decreaseDateByXMonths( stDate Date , short monthsToAdd ) {
	for ( short i = 0; i < monthsToAdd; i++ )
	{
		Date = decreaseDateByOneMonth( Date );
	}
	return Date;
}
int main()
{
	stDate Date;
	Date.day = getDay();
	Date.month = getMonth();
	Date.year = getYear();

	short daysToAdd = getDaysToAdd();
	short weeksToSub = getWeeksToAdd();
	short monthsToAdd = getMonthsToADD();


	Date = decreaseDateByOneDay( Date );
	cout << "1-Increase Date By One Day = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = decreaseDateByXDays( Date , daysToAdd );
	cout << "2-Increase Date By X Day = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = decreaseDateByOneWeek( Date );
	cout << "3-Decrease Date By One Month = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = decreaseDateByXWeeks( Date , monthsToAdd );
	cout << "4-Decrease Date By " << weeksToSub << " = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = decreaseDateByOneMonth( Date );
	cout << "3-Decrease Date By One Month = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = decreaseDateByXMonths( Date , monthsToAdd );
	cout << "4-Decrease Date By " << monthsToAdd << " = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	return 0;
}

