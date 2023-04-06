#include <iostream>
using namespace std;

enum enDateCompare
{
	Before = -1 , Equal = 0 , After = 1
};
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
bool checkTwoDatesAreEqual( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year == DateTwo.year ) && ( DateOne.month == DateTwo.month ) && ( DateOne.day == DateTwo.day );
}
bool checkIfFirstDateBeforeSecondDate( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year < DateTwo.year ) ? true : ( ( DateOne.year == DateTwo.year ) ? ( DateOne.month < DateTwo.month ? true : ( DateOne.month == DateTwo.month ? DateOne.day < DateTwo.day : false ) ) : false );
}
bool checkIfDateOneAfterDateTwo( stDate DateOne , stDate DateTwo ) {
	return( !checkIfFirstDateBeforeSecondDate( DateOne , DateTwo ) && !checkTwoDatesAreEqual( DateOne , DateTwo ) );
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
enDateCompare compareDatesFunction( stDate DateOne , stDate DateTwo ) {
	if ( checkIfFirstDateBeforeSecondDate( DateOne , DateTwo ) )
	{
		return enDateCompare::Before;
	}
	if ( checkTwoDatesAreEqual( DateOne , DateTwo ) ) {
		return enDateCompare::Equal;
	}
	return enDateCompare::After;
}
bool IsOverlapPeriods( stPeriod periodOne , stPeriod periodTwo ) {
	if ( compareDatesFunction( periodTwo.periodEnd , periodOne.periodStart ) == enDateCompare::Before || compareDatesFunction( periodTwo.periodStart , periodOne.periodEnd ) == enDateCompare::After )
		return false;
	else
		return true;
}
short DifferentBetweenTwoDates( stDate DateOne , stDate DateTwo , bool InclusingEndDay = false ) {
	short days = 0;
	while ( checkIfFirstDateBeforeSecondDate( DateOne , DateTwo ) )
	{
		days++;
		DateOne = increaseDateByOneDay( DateOne );
	}
	return InclusingEndDay ? ++days : days;
}
short periodLengeth( stPeriod period , bool includingEndDay = false ) {
	return DifferentBetweenTwoDates( period.periodStart , period.periodEnd , includingEndDay );
}bool checkIfTheDateInPeriod( stPeriod period , stDate Date ) {
	return  !( compareDatesFunction( period.periodStart , Date ) == enDateCompare::Before || compareDatesFunction( period.periodEnd , Date ) == enDateCompare::After );
}

int overLapDays( stPeriod periodOne , stPeriod periodTwo ) {
	int counter = 0;
	// take each period length..
	int periodOneLength = periodLengeth( periodOne , true );
	int periodTwoLength = periodLengeth( periodTwo , true );

	// if there is no overlap no need to check... return 
	if ( !IsOverlapPeriods( periodOne , periodTwo ) )
	{
		return 0;
	}
	if ( periodOneLength < periodTwoLength ) // Here I Have To sellect The short period to check to (optimizing)..
	{
		// I will decrease the days from first day in period to last day and checking in each step if the date is in the period..
		while ( checkIfFirstDateBeforeSecondDate( periodOne.periodStart , periodOne.periodEnd ) )
		{
			// checking if the date is in the period..
			if ( checkIfTheDateInPeriod( periodTwo , periodOne.periodStart ) )
			{
				counter++;
			}
			// increasing startd day by one until reaching last day..
			periodOne.periodStart = increaseDateByOneDay( periodOne.periodStart );
		}
	}
	else
	{ // if second period is shrter than first one we will check on it.
		while ( checkIfFirstDateBeforeSecondDate( periodTwo.periodStart , periodTwo.periodEnd ) )
		{
			// checking if the date is in the period
			if ( checkIfTheDateInPeriod( periodOne , periodTwo.periodStart ) )
			{
				counter++;
			}
			// increasing startd day by one until reaching last day..
			periodTwo.periodStart = increaseDateByOneDay( periodTwo.periodStart );
		}
	}


	return counter;
}
int main()
{
	stPeriod periodOne;
	stPeriod periodTwo;

	cout << "\nPERIOD ONE:\n" << endl;
	cout << "Period One Starts: " << endl;
	periodOne.periodEnd.day = readDay();
	periodOne.periodStart.month = readMonth();
	periodOne.periodStart.year = readYear();
	cout << "Period One Ends: " << endl;
	periodOne.periodEnd.day = readDay();
	periodOne.periodEnd.month = readMonth();
	periodOne.periodEnd.year = readYear();

	cout << "\nPERIOD Two:\n" << endl;
	cout << "Period Two Starts: " << endl;
	periodTwo.periodStart.day = readDay();
	periodTwo.periodStart.month = readMonth();
	periodTwo.periodStart.year = readYear();
	cout << "Period One Ends: " << endl;
	periodTwo.periodEnd.day = readDay();
	periodTwo.periodEnd.month = readMonth();
	periodTwo.periodEnd.year = readYear();

	if ( IsOverlapPeriods( periodOne , periodTwo ) )
	{
		cout << "There Is Overlping.." << endl;
	}
	else
	{
		cout << "There is NOOO Overlaping.." << endl;
	}
	cout << "Overlap Days Are: (" << overLapDays( periodOne , periodTwo ) << ") Days/s" << endl;
	return 0;
}

