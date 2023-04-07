#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stDate
{
	int day = 0;
	int month = 0;
	int year = 0;
};
vector <string> seprateString( string text , string seperator = " " ) {
	int position = 0;
	string word = "";
	vector <string> words;

	while ( ( position = text.find( seperator ) ) != string::npos )
	{
		word = text.substr( 0 , position );

		if ( word != "" )
		{
			words.push_back( word );
		}

		text.erase( 0 , position + seperator.length() );
	}

	if ( text != "" )
	{
		words.push_back( text );
	}

	return words;
}
stDate stringDateToDate( string Date ) {

	stDate speratedDate;
	vector <string> vDate;

	vDate = seprateString( Date , "/" );
	speratedDate.day = stoi( vDate[ 0 ] );
	speratedDate.month = stoi( vDate[ 1 ] );
	speratedDate.year = stoi( vDate[ 2 ] );

	return speratedDate;
}
string dateToString( stDate Date ) {
	return to_string( Date.day ) + "/" + to_string( Date.month ) + "/" + to_string( Date.year );
}
string ReadDaate() {
	string D;
	cout << "\nPlease enter a Date ( dd/mm/yy ) ? ";
	getline( cin >> ws , D );
	return D;
}
int main()
{
	string strDate = ReadDaate();
	stDate speratDate = stringDateToDate( strDate );
	cout << "Day => " << speratDate.day << "\nMonth => " << speratDate.month << "\nYear => " << speratDate.year << endl;
	string toStringDate = dateToString( speratDate );
	cout << toStringDate << endl;

	return 0;
}
