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
	cout << "Enter Days To Add? ";
	cin >> d;
	return d;
}
short getWeeksToAdd() {
	short w = 0;
	cout << "Enter A Weeks To Add? ";
	cin >> w;
	return w;
}
short getMonthsToADD() {
	short m = 0;
	cout << "Enter A Months To Add? ";
	cin >> m;
	return m;
}
short getYearsToAdd() {
	short y = 0;
	cout << "Enter A Years To Add? ";
	cin >> y;
	return y;
}
short getDecadesToAdd() {
	short d = 0;
	cout << "Enter A Decades To Add? ";
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
bool checkIfTheLastDayInTheMonth( stDate& Date ) {
	return ( Date.day == numberOfDaysInAmonth( Date.year , Date.month ) );
}
bool checkIfTheLastMonthInTheYear( stDate& Date ) {
	return ( Date.month == 12 );
}
stDate increaseDateByOneDay( stDate& Date ) {
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
stDate increaseDateByXDays( stDate& Date , short numberOfDaysToAdd ) {
	for ( short i = 0; i < numberOfDaysToAdd; i++ )
	{
		Date = increaseDateByOneDay( Date );
	}
	return Date;
}
stDate increaseDateByOneWeek( stDate& Date ) {
	for ( short i = 0; i < 7; i++ )
	{
		Date = increaseDateByOneDay( Date );
	}
	return Date;
}
stDate increaseDateByXWeeks( stDate& Date , short numberOfWeeksToAdd ) {
	for ( short i = 0; i < numberOfWeeksToAdd; i++ )
	{
		Date = increaseDateByOneWeek( Date );
	}
	return Date;
}
stDate increaseDateByOneMonth( stDate& Date ) {
	short numberOfDaysToAdd = numberOfDaysInAmonth( Date.year , Date.month );
	if ( Date.month == 12 )
	{
		Date.month = 1;
		Date.year++;
	}
	else
	{
		Date.month++;
	}
	short numberOfDaysInCurrentMonth = numberOfDaysInAmonth( Date.month , Date.year );
	if ( Date.day > numberOfDaysInCurrentMonth )
	{
		Date.day = numberOfDaysInCurrentMonth;
	}
	return Date;
}
stDate increaseDateByXmonths( stDate& Date , short numberOfMonthsToAdd ) {
	for ( short i = 0; i < numberOfMonthsToAdd; i++ )
	{
		Date = increaseDateByOneMonth( Date );
	}
	return Date;
}
stDate increaseDateByOneYear( stDate& Date ) {
	Date.year++;
	return Date;
}
stDate increaseDateByXYears( stDate& Date , short numberOfYearsToAdd ) {
	for ( short i = 0; i < numberOfYearsToAdd; i++ )
	{
		Date = increaseDateByOneYear( Date );
	}
	return Date;
}
stDate increaseDateByXYearsFaster( stDate& Date , short numberOfYeasrToAdd ) {
	Date.year += numberOfYeasrToAdd;
	return Date;
}
stDate increaseDateByOneDecade( stDate& Date ) {
	for ( short i = 0; i < 10; i++ )
	{
		Date = increaseDateByOneYear( Date );
	}
	return Date;
}
stDate increaseDateByXDecades( stDate& Date , short numberOfYearsToAdd ) {
	for ( short i = 0; i < numberOfYearsToAdd; i++ )
	{
		Date = increaseDateByOneDecade( Date );
	}
	return Date;
}
stDate increaseDateByXDecadesFaster( stDate& Date , short numberOfYeasrToAdd ) {
	Date.year += numberOfYeasrToAdd * 10;
	return Date;
}
stDate increaseDateByOneCentury( stDate& Date ) {
	for ( short i = 0; i < 10; i++ )
	{
		Date = increaseDateByOneDecade( Date );
	}
	return Date;
}
stDate increaseDatByOneMillennium( stDate& Date ) {
	for ( short i = 0; i < 10; i++ )
	{
		Date = increaseDateByOneCentury( Date );
	}
	return Date;
}
int main() {
	stDate Date;
	Date.day = getDay();
	Date.month = getMonth();
	Date.year = getYear();

	short daysToAdd = getDaysToAdd();
	short weeksToAdd = getWeeksToAdd();
	short monthsToAdd = getMonthsToADD();
	short yearsToadd = getYearsToAdd();
	short decadesToadd = getDecadesToAdd();


	Date = increaseDateByOneDay( Date );
	cout << "1-Increase Date By One Day = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByXDays( Date , daysToAdd );
	cout << "2-Increase Date By X Day = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByOneWeek( Date );
	cout << "3-Increase Date By One Week = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByXWeeks( Date , weeksToAdd );
	cout << "4-Increase Date By X Weeks = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByOneMonth( Date );
	cout << "5-Increase Date By One Month = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByXmonths( Date , monthsToAdd );
	cout << "6-Increase Date By X Months = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByOneYear( Date );
	cout << "7-Increase Date By One Year = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByXYears( Date , yearsToadd );
	cout << "8-Increase Date By X Years = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByXYearsFaster( Date , yearsToadd );
	cout << "9-Increase Date By X Years Faster = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByOneDecade( Date );
	cout << "10-Increase Date By One Decade = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByXDecades( Date , decadesToadd );
	cout << "11-Increase Date By X Decades = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByXDecadesFaster( Date , decadesToadd );
	cout << "12-Increase Date By X Decades Faster = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDateByOneCentury( Date );
	cout << "13-Increase Date By One Century = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	Date = increaseDatByOneMillennium( Date );
	cout << "14-Increase Date By On Millennium = " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	return 0;
}