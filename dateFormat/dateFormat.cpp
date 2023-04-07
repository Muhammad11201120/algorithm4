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
string replaceWordsUsingBuiltInFunction( string text , string wordToreplace , string wordToreplaceTo ) {

	int position = text.find( wordToreplace );

	while ( position != string::npos )
	{
		text = text.replace( position , wordToreplace.length() , wordToreplaceTo );
		position = text.find( wordToreplace );
	}
	return text;
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

string ReadDaate() {
	string D;
	cout << "\nPlease enter a Date ( dd/mm/yyyy ) ? ";
	getline( cin >> ws , D );
	return D;
}
string dateFormaing( stDate Date , string dateFormat = "dd/mm/yyyy" ) {
	string formatString = "";

	formatString = replaceWordsUsingBuiltInFunction( dateFormat , "dd" , to_string( Date.day ) );
	formatString = replaceWordsUsingBuiltInFunction( formatString , "mm" , to_string( Date.month ) );
	formatString = replaceWordsUsingBuiltInFunction( formatString , "yyyy" , to_string( Date.year ) );

	return formatString;
}
int main()
{
	string strDate = ReadDaate();
	stDate speratDate = stringDateToDate( strDate );
	cout << dateFormaing( speratDate ) << endl;
	cout << dateFormaing( speratDate , "yyyy/dd/mm" ) << endl;
	cout << dateFormaing( speratDate , "mm/dd/yyyy" ) << endl;
	cout << dateFormaing( speratDate , "dd-mm-yyyy" ) << endl;
	cout << dateFormaing( speratDate , "yyyy-mm-dd" ) << endl;


	cout << dateFormaing( speratDate , "\nDay=> dd, Month=> mm, Year=> yyyy" ) << endl;
	return 0;
}
