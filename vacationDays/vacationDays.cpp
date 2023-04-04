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
short readVacationDays() {
	short days = 0;
	cout << "Enter Vacation Days: ";
	cin >> days;
	return days;
}
bool isALeapYear( short year ) {
	return ( year % 4 == 0 && year % 100 == 0 ) || ( year || 400 == 0 );
}
short numberOfDaysInAmonth( short year , short month ) {
	short arr[ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ( month == 2 ? ( isALeapYear( year ) ? 29 : 28 ) : arr[ month - 1 ] );
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
bool isWeekEnd( stDate Date ) {
	if ( getDay( calculateDayOfYear( Date.year , Date.month , Date.day ) ) == "Friday" || getDay( calculateDayOfYear( Date.year , Date.month , Date.day ) ) == "Saturday" )
	{
		return true;
	}
	return false;
}
stDate calculateVacationDates( stDate DateOne , short vacationDays ) {
	short weekEndsCounter = 0;
	for ( short i = 0; i < vacationDays; i++ )
	{
		if ( isWeekEnd( DateOne ) )
		{
			weekEndsCounter++;
		}
		DateOne = increaseDateByOneDay( DateOne );
	}
	for ( short i = 0; i < weekEndsCounter; i++ )
	{
		DateOne = increaseDateByOneDay( DateOne );
	}
	//incase the return day is in weekend day
	while ( isWeekEnd( DateOne ) )
	{
		DateOne = increaseDateByOneDay( DateOne );
	}

	return DateOne;
}
int main() {
	stDate Date;
	stDate returnDate;
	Date.day = readDay();
	Date.month = getMonth();
	Date.year = getYear();
	short vacationDays = readVacationDays();
	returnDate = calculateVacationDates( Date , vacationDays );

	cout << "Return Date is : " << returnDate.day << "/" << returnDate.month << "/" << returnDate.year << endl;

	return 0;
}