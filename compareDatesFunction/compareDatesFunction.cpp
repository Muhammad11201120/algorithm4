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
bool checkTwoDatesAreEqual( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year == DateTwo.year ) && ( DateOne.month == DateTwo.month ) && ( DateOne.day == DateTwo.day );
}
bool checkIfFirstDateGreaterThanSecondDate( stDate& DateOne , stDate& DateTwo ) {
	return  ( DateOne.year > DateTwo.year ) ? true : ( ( DateOne.year == DateTwo.year ) ? ( DateOne.month > DateTwo.month ? true : ( DateOne.month == DateTwo.month ? DateOne.day > DateTwo.day : false ) ) : false );
}
bool checkIfDateOneAfterDateTwo( stDate DateOne , stDate DateTwo ) {
	return( checkIfFirstDateGreaterThanSecondDate( DateOne , DateTwo ) && !checkTwoDatesAreEqual( DateOne , DateTwo ) );
}
short compareDatesFunction( stDate DateOne , stDate DateTwo ) {
	if ( checkIfDateOneAfterDateTwo( DateOne , DateTwo ) )
	{
		return 1;
	}
	else if ( !checkIfFirstDateGreaterThanSecondDate( DateOne , DateTwo ) && !checkTwoDatesAreEqual( DateOne , DateTwo ) ) {
		return -1;
	}
	return 0;
}
int main()
{
	stDate DateOne;
	DateOne.day = readDay();
	DateOne.month = readMonth();
	DateOne.year = readYear();
	stDate DateTwo;
	DateTwo.day = readDay();
	DateTwo.month = readMonth();
	DateTwo.year = readYear();
	cout << compareDatesFunction( DateOne , DateTwo );
}