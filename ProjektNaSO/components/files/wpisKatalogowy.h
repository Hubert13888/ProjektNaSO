#pragma once
#include <string>
#include <iostream>
using namespace std;

class wpis
{
public:
	wpis();
	wpis(string nazwa, string rozszerzenie, short numer);
	void czysc();
	void wypisz();
	void ustawNazwe(string nazwa);
	string pobierzNazwe();
	void ustawRozszrzenie(string rozszerzenie);
	string pobierzRozszerzenie();
	void ustawNumerIwezla(short numer);
	short pobierzNumer();
private:
	string nazwa;
	string rozszerzenie;
	short numerIwezela;
};