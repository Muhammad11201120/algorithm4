#pragma warning( disable : 4996 )
#include <iostream>
using namespace std;
enum enDays
{
	Sunday , Monday , Tuesday , Wednesday , Thuresday , Friday , Saturday
};
struct stDate
{
	short year = 0;
	short month = 0;
	short day = 0;
};
short readDay() {
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
stDate setVacationStart() {
	stDate Date;

	Date.day = readDay();
	Date.month = getMonth();
	Date.year = getYear();
	return Date;
}
stDate setVvacationEnd() {
	stDate Date;

	Date.day = readDay();
	Date.month = getMonth();
	Date.year = getYear();
	return Date;
}

stDate GetSystemDate() {
	stDate Date;
	time_t t = time( 0 );
	tm* now = localtime( &t );
	Date.year = now->tm_year + 1900;
	Date.month = now->tm_mon + 1;
	Date.day = now->tm_mday;
	return Date;
}
enDays calculateDayOfYear( int year , short month , short day ) {
	int a = ( 14 - month ) / 12;
	int y = year - a;
	int m = month + ( 12 * a ) - 2;

	int d = ( day + y + ( y / 4 ) - ( y / 100 ) + ( y / 400 ) + ( ( 31 * m ) / 12 ) ) % 7;
	return ( enDays ) d;
}
bool checkIfFirstDateGreaterThanSecondDate( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year > DateTwo.year ) ? true : ( ( DateOne.year == DateTwo.year ) ? ( DateOne.month > DateTwo.month ? true : ( DateOne.month == DateTwo.month ? DateOne.day > DateTwo.day : false ) ) : false );
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
string getDay( enDays day ) {
	switch ( day )
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
//IsWeekEnd.
bool isWeekEnd( stDate Date ) {
	if ( getDay( calculateDayOfYear( Date.year , Date.month , Date.day ) ) == "Friday" || getDay( calculateDayOfYear( Date.year , Date.month , Date.day ) ) == "Saturday" )
	{
		return true;
	}
	return false;
}
//IsBusinessDay.
bool isBusinessDay( stDate Date ) {
	if ( !isWeekEnd( Date ) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void getVacationStart( stDate Date ) {
	cout << "Vacation From: " << getDay( calculateDayOfYear( Date.year , Date.month , Date.day ) );
	cout << " => " << Date.day << "/" << Date.month << "/" << Date.year << endl;
}
void getVacationEnd( stDate Date ) {
	cout << "Vacation End: " << getDay( calculateDayOfYear( Date.year , Date.month , Date.day ) );
	cout << " => " << Date.day << "/" << Date.month << "/" << Date.year << endl;
}
short calculateVacationDates( stDate DateOne , stDate DateTwo ) {
	short Days = 0;
	while ( !checkIfFirstDateGreaterThanSecondDate( DateOne , DateTwo ) )
	{
		if ( isBusinessDay( DateOne ) )
		{
			Days++;
		}
		DateOne = increaseDateByOneDay( DateOne );
	}
	return Days;
}
int main()
{
	stDate vacationStart;
	stDate vacationEnd;

	cout << "Vaction Starts: " << endl;
	vacationStart = setVacationStart();
	cout << "\nVacation Ends: " << endl;
	vacationEnd = setVvacationEnd();

	getVacationStart( vacationStart );
	getVacationEnd( vacationEnd );
	cout << "\n\n Actual Number Of Vacation Days is => " << calculateVacationDates( vacationStart , vacationEnd ) << " Days/s.." << endl;
	return 0;
}