#include <iostream>
using namespace std;
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
int main()
{
	short year = readYear();
	short month = readMonth();
	short day = readDay();
	cout << "The Day is => (" << daysFromBeginingOfTheYear( year , month , day ) << ") Of The Year.." << endl;
}