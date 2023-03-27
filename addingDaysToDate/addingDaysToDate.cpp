#include <iostream>
using namespace std;
struct stDate
{
	short year = 0;
	short month = 0;
	short day = 0;
};
short readYear() {
	short y = 0;
	cout << "Enter A Year? ";
	cin >> y;
	return y;
}
short readMonth() {
	short m = 0;
	do
	{
		cout << "Enter A Month? ";
		cin >> m;
	} while ( m < 0 || m > 12 );

	return m;
}
short readDay() {
	short d;
	cout << "Enter A Day? ";
	cin >> d;
	return d;
}
bool isAleapYear( int year )
{
	return ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 );
}
short numberOfDaysInMonth( short year , short month ) {
	if ( month < 1 || month > 12 )
		return 0;
	short arr[ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ( month == 2 ) ? ( isAleapYear( year ) ? 29 : 28 ) : arr[ month - 1 ];
}
short daysFromBeginingOfTheYear( short year , short month , short day ) {
	short days = 0;
	for ( short i = 1; i <= month - 1; i++ )
	{
		days += numberOfDaysInMonth( year , i );
	}

	return days += day;
}
stDate getDateOfDays( short year , short daysNumberInYear ) {
	stDate Date;
	short remainingDays = daysNumberInYear; // to increment days from.
	short monthDays = 0;

	Date.month = 1;
	Date.year = year;

	while ( true )
	{
		monthDays = numberOfDaysInMonth( year , Date.month );
		if ( remainingDays > monthDays )
		{
			remainingDays -= monthDays;
			Date.month++;
		}
		else
		{
			Date.day = remainingDays;
			break;
		}
	}
	return Date;
}

stDate addingDaysToDate( stDate& Date , int addingDays ) {
	int monthDays = 0;
	while ( addingDays > 0 )
	{
		monthDays = numberOfDaysInMonth( Date.year , Date.month );
		Date.day++;
		if ( Date.day == monthDays )
		{
			Date.day = 1;
			Date.month++;
		}if ( Date.month == 12 )
		{
			Date.month = 1;
			Date.year++;
		}
		addingDays--;
	}
	return Date;
}
int main() {

	stDate Date;
	stDate newDate;
	short year = readYear();
	short month = readMonth();
	short day = readDay();
	short addingDays = readDay();
	short daysNumberInYear = daysFromBeginingOfTheYear( year , month , day );
	Date = getDateOfDays( year , daysNumberInYear );

	newDate = addingDaysToDate( Date , addingDays );

	cout << "Date After Adding (" << addingDays << ") is : " << newDate.day << "/" << newDate.month << "/" << newDate.year << endl;

	return 0;
}