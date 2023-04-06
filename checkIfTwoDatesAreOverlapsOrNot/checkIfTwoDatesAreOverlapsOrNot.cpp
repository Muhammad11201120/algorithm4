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
bool checkTwoDatesAreEqual( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year == DateTwo.year ) && ( DateOne.month == DateTwo.month ) && ( DateOne.day == DateTwo.day );
}
bool checkIfFirstDateBeforeSecondDate( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year < DateTwo.year ) ? true : ( ( DateOne.year == DateTwo.year ) ? ( DateOne.month < DateTwo.month ? true : ( DateOne.month == DateTwo.month ? DateOne.day < DateTwo.day : false ) ) : false );
}
bool checkIfDateOneAfterDateTwo( stDate DateOne , stDate DateTwo ) {
	return( !checkIfFirstDateBeforeSecondDate( DateOne , DateTwo ) && !checkTwoDatesAreEqual( DateOne , DateTwo ) );
}
enDateCompare compareDatesFunction( stDate DateOne , stDate DateTwo ) {
	if ( checkIfFirstDateBeforeSecondDate( DateOne , DateTwo ) )
	{
		return enDateCompare::Before;
	}
	else if ( checkTwoDatesAreEqual( DateOne , DateTwo ) ) {
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

	return 0;
}

