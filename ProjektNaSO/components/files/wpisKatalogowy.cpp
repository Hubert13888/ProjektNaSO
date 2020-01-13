#include "wpisKatalogowy.h"
#include <iostream>

wpis::wpis()
{
	this->nazwa.empty();
	this->rozszerzenie.empty();
	this->numerIwezela = -1;
}

wpis::wpis(string nazwa, string rozszerzenie, short numer)
{
	this->nazwa = nazwa;
	this->rozszerzenie = rozszerzenie;
	this->numerIwezela = numer;
}

void wpis::czysc()
{
	this->nazwa.empty();
	this->rozszerzenie.empty();
	this->numerIwezela = -1;
}

void wpis::wypisz()
{
	cout << " - nazwa pliku: " << nazwa << endl;
	cout << " - rozszerzenie pliku: " << rozszerzenie << endl;
	cout << " - iwezel pliku: " << numerIwezela << "\n";

}

void wpis::ustawNazwe(string nazwa)
{
	this->nazwa = nazwa;
}

string wpis::pobierzNazwe()
{
	return nazwa;
}

void wpis::ustawRozszrzenie(string rozszerzenie)
{
	this->rozszerzenie = rozszerzenie;
}

string wpis::pobierzRozszerzenie()
{
	return rozszerzenie;
}

void wpis::ustawNumerIwezla(short numer)
{
	this->numerIwezela = numer;
}

short wpis::pobierzNumer()
{
	return numerIwezela;
}