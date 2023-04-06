#include <iostream>
using namespace std;

struct stDate
{
	short year = 0;
	short month = 0;
	short day = 0;
};
struct stPeriod
{
	stDate periodStart;
	stDate periodEnd;
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
bool checkTwoDatesAreEqual( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year == DateTwo.year ) && ( DateOne.month == DateTwo.month ) && ( DateOne.day == DateTwo.day );
}
bool checkIfFirstDateBeforeSecondDate( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year < DateTwo.year ) ? true : ( ( DateOne.year == DateTwo.year ) ? ( DateOne.month < DateTwo.month ? true : ( DateOne.month == DateTwo.month ? DateOne.day < DateTwo.day : false ) ) : false );
}
bool checkIfDateOneAfterDateTwo( stDate DateOne , stDate DateTwo ) {
	return( !checkIfFirstDateBeforeSecondDate( DateOne , DateTwo ) && !checkTwoDatesAreEqual( DateOne , DateTwo ) );
}
bool checkIfTheDateInPeriod( stPeriod period , stDate Date ) {
	return  ( checkIfFirstDateBeforeSecondDate( period.periodStart , Date ) && checkIfDateOneAfterDateTwo( period.periodEnd , Date ) );
}
int main()
{
	stPeriod periodOne;
	stDate Date;
	cout << "Period Starts: " << endl;
	periodOne.periodEnd.day = readDay();
	periodOne.periodStart.month = readMonth();
	periodOne.periodStart.year = readYear();
	cout << "Period Ends: " << endl;
	periodOne.periodEnd.day = readDay();
	periodOne.periodEnd.month = readMonth();
	periodOne.periodEnd.year = readYear();

	cout << "Date To Check:" << endl;
	Date.day = readDay();
	Date.month = readMonth();
	Date.year = readYear();
	if ( checkIfTheDateInPeriod( periodOne , Date ) )
	{
		cout << "Yesss" << endl;
	}
	else
	{
		cout << "NOOOOOOOOOOOO" << endl;
	}
	return 0;
}