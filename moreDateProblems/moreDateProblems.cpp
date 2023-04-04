#pragma warning( disable : 4996 )

#include <iostream>
#include <ctime>
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
//overload theDayOfWeekOrder to take date structure.
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
bool isALeapYear( short year ) {
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
bool checkTwoDates( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year == DateTwo.year ) && ( DateOne.month == DateTwo.month ) && ( DateOne.day == DateTwo.day );
}
bool checkIfFirstDateGreaterThanSecondDate( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year > DateTwo.year ) ? true : ( ( DateOne.year == DateTwo.year ) ? ( DateOne.month > DateTwo.month ? true : ( DateOne.month == DateTwo.month ? DateOne.day > DateTwo.day : false ) ) : false );
}
bool isDateOneBeforeDateTwo( stDate dateOne , stDate dateTwo ) {
	return !checkIfFirstDateGreaterThanSecondDate( dateOne , dateTwo );
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
short DifferentBetweenTwoDates( stDate DateOne , stDate DateTwo , bool InclusingEndDay = false ) {
	short days = 0;
	if ( !isDateOneBeforeDateTwo( DateOne , DateTwo ) )
	{
		return 0;
	}
	while ( isDateOneBeforeDateTwo( DateOne , DateTwo ) )
	{
		days++;
		DateOne = incrementDateByOneDay( DateOne );
	}

	return InclusingEndDay ? ++days : days;
}
void curretnDate( stDate Date ) {
	cout << "Today is => " << getDay( calculateDayOfYear( Date.year , Date.month , Date.day ) );
	cout << " - " << Date.day << "/" << Date.month << "/" << Date.year << endl;
}
//IsEndOfWeek.
bool isEndOfWeek( stDate Date ) {
	if ( getDay( calculateDayOfYear( Date.year , Date.month , Date.day ) ) == "Friday" )
	{
		return true;
	}
	return false;
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
////DaysUntilTheEndOfWeek.
short daysUntilTheEndOfWeek( stDate Date ) {
	short counter = 0;
	while ( !isEndOfWeek( Date ) )
	{
		counter++;
		Date.day++;
	}
	return counter;
}
////DaysUntiTheEndOfMonth.
short daysUntilTheEndOfMonth( stDate Date ) {
	short counter = 0;
	while ( Date.day != numberOfDaysInAmonth( Date.year , Date.month ) )
	{
		Date.day++;
		counter++;
	}
	return counter;
}
////DaysUntilTheEndOfYear
short daysUntilTheEndOfYear( stDate Date ) {
	stDate endOfYearDate;
	endOfYearDate.day = 31;
	endOfYearDate.month = 12;
	endOfYearDate.year = Date.year;

	return DifferentBetweenTwoDates( Date , endOfYearDate , true );
}
int main()
{
	stDate Date = GetSystemDate();
	curretnDate( Date );
	if ( isEndOfWeek( Date ) )
	{
		cout << "Yes Is End Of Week.." << endl;
	}
	else
	{
		cout << "No It Is Not End Of Week.." << endl;
	}
	if ( isWeekEnd( Date ) )
	{
		cout << "Yes Is Week End.." << endl;
	}
	else
	{
		cout << "No It Is Not Week End.." << endl;
	}
	if ( isBusinessDay( Date ) )
	{
		cout << "Yes Is Business Day.." << endl;
	}
	else
	{
		cout << "No It Is Not Business Day.." << endl;
	}
	cout << "There Are : " << daysUntilTheEndOfWeek( Date ) << " Day(s) Until The End Of Week.." << endl;
	cout << "There Are : " << daysUntilTheEndOfMonth( Date ) << " Day(s) Until The End Of Month.." << endl;
	cout << "There Are : " << daysUntilTheEndOfYear( Date ) << " Day(s) Until The End Of Year.." << endl;
	return 0;
}