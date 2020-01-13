#include "katalog.h"
#include <iostream>

katalog::katalog()
{
	this->nazwa.empty();
	this->podfoldery = 0; // podczas tworzenia brak podfolderow
	wskaznikNaOjca = -1; // brak ojca
	for (short wskaznik_na_syna : wskaznikNaPodfolder)
	{
		wskaznik_na_syna = -1; // brak synow czyli podfolderow
	}
}

katalog::katalog(string nazwa)
{
	this->nazwa = nazwa;
	wskaznikNaOjca = -1; //brak ojca
	for (int i = 0; i<wskaznikNaPodfolder.size(); i++)
	{
		wskaznikNaPodfolder[i] = -1; // brak synow czyli podfolderow
	}
}

katalog::katalog(string nazwa, short wskaznikNaOjca)
{
	this->nazwa = nazwa;
	this->wskaznikNaOjca = wskaznikNaOjca;
	for (int i = 0; i<wskaznikNaPodfolder.size(); i++)
	{
		wskaznikNaPodfolder[i] = -1;
	}
}

void katalog::wypiszKatalog()
{
	cout << " - nazwa: " << nazwa << endl;
	cout << " - i-wezyly w katalogu: " << endl;
	for (short element : this->numeryIwezlow)
	{
		cout << element << " ";//wyspisuje wszytskie iwezly zawarte w danym katalogu
	}
	cout << endl;;
}

void katalog::ustawNazwe(string nazwa)
{
	this->nazwa = nazwa;
}

string katalog::pobierzNazwe()
{
	return this->nazwa;
}

void katalog::dodajNumerIwezela(short numer)
{
	this->numeryIwezlow.push_back(numer);
}

void katalog::usunNumerIwezla(short numer)
{
	this->numeryIwezlow.erase(find(this->numeryIwezlow.begin(), this->numeryIwezlow.end(), numer) + 0);
}

vector<short> katalog::pobierzNumery()
{
	return this->numeryIwezlow;
}

void katalog::ustawOjca(short ojciec)
{
	this->wskaznikNaOjca = ojciec;
}

short katalog::pobierzOjca()
{
	return this->wskaznikNaOjca;
}

void katalog::ustawSyna(short syn)
{
	for (int i = 0; i<wskaznikNaPodfolder.size(); i++){
		if (wskaznikNaPodfolder[i] == -1){
			wskaznikNaPodfolder[i] = syn;
			break;
		}
	}
}

array<short, 32> katalog::pobierzSynow()
{
	return this->wskaznikNaPodfolder;
}

void katalog::usunSyna(short syn)
{
	for (int i = 0; i<wskaznikNaPodfolder.size(); i++){
		if (wskaznikNaPodfolder[i] == syn){
			wskaznikNaPodfolder[i] = -1;
		}
	}
}

short katalog::ilePodfolderow()
{
	return podfoldery;
}

void katalog::ustawPodfoldery(int i)
{
	podfoldery = i;
}