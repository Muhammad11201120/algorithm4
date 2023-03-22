#include <iostream>
#include <string>
using namespace std;
int readNumber() {
	int number = 0;
	cout << "Enter A Number: ";
	cin >> number;
	return number;
}
string convertNumberToText(int number) {
	if (number == 0)
	{
		return "";
	}
	if (number >= 1 && number <= 19)
	{
		string arr[] = { "","One","Two","Three",
			"Four","Five","Six","Seven",
			"Eight","Nine","Ten","Eleven","Twelve",
			"Thirteen","Fourteen","Fiveteen","Sixteen",
			"SevenTeen","Eighteen","Nineteen" };

		return arr[number] + " ";
	}
	if (number >=20 && number <= 99)
	{
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninty" };
		return arr[number / 10] + " " + convertNumberToText(number % 10);
	}
	if (number >=100 && number <= 199)
	{
		return "One Hundred " + convertNumberToText(number % 100);
	}
	if (number >=200 && number <= 999)
	{
		return convertNumberToText(number/100) + "Hundreds " + convertNumberToText(number % 100);
	}
	if (number >=1000 && number <= 1999)
	{
		return  "One Thousand " + convertNumberToText(number % 1000);
	}
	if (number >=2000 && number <= 999999)
	{
		return convertNumberToText(number/1000)+ "Thousands " + convertNumberToText(number % 1000);
	}
	if (number >=1000000 && number <= 1999999)
	{
		return "One Million " + convertNumberToText(number % 1000000);
	}
	if (number >=2000000 && number <= 999999999)
	{
		return convertNumberToText(number/1000000)+ "Millions " + convertNumberToText(number % 1000000);
	}
	if (number >= 1000000000 && number <= 1999999999)
	{
		return "One Billion " + convertNumberToText(number % 1000000000);
	}
	else {
		return convertNumberToText(number / 1000000000) + "Billions " + convertNumberToText(number % 1000000000);
	}
}


int main()
{
	int number = readNumber();
	cout << convertNumberToText(number);
}
