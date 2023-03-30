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
int main()
{
	stDate DateOne;
	stDate DateTwo;

	DateOne.year = getYear();
	DateOne.month = getMonth();
	DateOne.day = getDay();

	DateTwo.year = getYear();
	DateTwo.month = getMonth();
	DateTwo.day = getDay();

	cout << "The Different Between Two Days Is => [" << DifferentBetweenTwoDates( DateOne , DateTwo ) << "] Day/s" << endl;
	cout << "The Different Between Two Days Is => [" << DifferentBetweenTwoDates( DateOne , DateTwo , true ) << "] Day/s" << endl;

	return 0;
}