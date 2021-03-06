
#include "stdafx.h"
#include "date.hpp"
#include "date_formatter.hpp"
#include <iostream>


using namespace std;

int main()
{
	int n;
	Date data;
	Date data2;
	ComputerDateFormatter Cformatter;
	GermanDateFormatter Gformatter;
	cout << "Podaj pierwsza date(yyyy-mm-dd):";
	cin  >> data;
	cout << "Podaj druga date(yyyy-mm-dd):";
	cin >> data2;
	cout << "Podaj n:";
	cin >> n;
	system("cls");
	cout << "Pierwsza data w formacie komputerowym:" << Cformatter.format(data) << endl <<
		"Pierwsza data w formacie niemieckim:" << Gformatter.format(data) << endl <<
		"Druga data w formacie komputerowym:" << Cformatter.format(data2) << endl <<
		"Druga data w formacie niemieckim:" << Gformatter.format(data2) << endl <<
		"n:" << n << endl;
	cout << "Data pierwsza po dodaniu n dni wynosi:" << (data + n) << endl <<
		"Data druga po dodaniu do n wynosi:" << (data2 + n) << endl <<
		"Data pierwsza po odjeciu n:" << (data - n) << endl <<
		"Data druga po odjeciu n:" << (data2 - n) << endl <<
		"Roznica dni miedzy pierwsza data a druga data:" << (data - data2) << endl <<
		"Roznica dni miedzy druga data a pierwsza data:" << (data2 - data) << endl <<
		"Czy daty sa rowne:";
	if (data == data2) cout << "Tak";
	else cout << "Nie"<<endl;
	

	return 0;
}

