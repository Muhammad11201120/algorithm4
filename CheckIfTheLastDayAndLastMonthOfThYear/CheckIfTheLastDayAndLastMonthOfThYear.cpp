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
bool checkIfTheLastDayInTheMonth( stDate& Date ) {
	return ( Date.day == numberOfDaysInMonth( Date.year , Date.month ) );
}
bool checkIfTheLastMonthInTheYear( stDate& Date ) {
	return ( Date.month == 12 );
}
int main()
{
	stDate Date;
	Date.year = readYear();
	Date.month = readMonth();
	Date.day = readDay();
	if ( checkIfTheLastDayInTheMonth( Date ) )
		cout << "Yes It Is The Last Day In The Month.." << endl;
	else
		cout << "No It Is Not The Last Day In The Month.." << endl;
	if ( checkIfTheLastMonthInTheYear( Date ) )
		cout << "Yes It Is The Last Month In The Year.." << endl;
	else
		cout << "No It Is Not The Last Month In The Year.." << endl;
	return 0;
}