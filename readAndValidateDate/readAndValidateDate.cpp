#include <iostream>
using namespace std;
struct stDate {
	short Year = 0;
	short Month = 0;
	short Day = 0;
};
bool isLeapYear( short Year )
{
	return ( Year % 4 == 0 && Year % 100 != 0 ) || ( Year % 400 == 0 );
}
short NumberOfDaysInAMonth( short Month , short Year )
{
	if ( Month < 1 || Month>12 )
		return  0;
	int days[ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ( Month == 2 ) ? ( isLeapYear( Year ) ? 29 : 28 ) : days[ Month - 1 ];
}
short ReadDay() {
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth() {
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear() {
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}
bool IsValidDate( stDate Date )
{
	short ValidDate = NumberOfDaysInAMonth( Date.Month , Date.Year );
	return !( Date.Day > ValidDate || Date.Day < 1 ) && !( Date.Month > 12 || Date.Month < 1 );
}
int main()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	if ( IsValidDate( Date ) )
	{
		cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	}
	else
	{
		cout << "It Is Not Valid Date..";
	}

	return 0;
}