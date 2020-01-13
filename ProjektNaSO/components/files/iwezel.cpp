#include "iwezel.h"
#include <cstdio>

iWezel::iWezel()
{
	this->indeksowyBlok = -1;
	this->rozmiarPliku = 0;
	this->pierwszyBlok = -1;
	this->drugiBlok = -1;
	
}

void iWezel::wypiszIwezel()
{
	cout << " - blok indeksowy: " << indeksowyBlok << endl;
	cout << " - pierwszy bezposredni blok: " << pierwszyBlok << endl;
	cout << " - drugi bezposredni blok: " << drugiBlok << endl;
	cout << " - rozmiar pliku: " << rozmiarPliku << endl;
	
}

void iWezel::czysc()
{
	this->rozmiarPliku = 0;
	this->pierwszyBlok = -1;
	this->drugiBlok = -1;
	this->indeksowyBlok = -1;
}

void iWezel::ustawRozmiarPliku(short rozmiar)
{
	this->rozmiarPliku = rozmiar;
}

int iWezel::pobierzRozmiarPliku()
{
	return this->rozmiarPliku;
}

void iWezel::ustawPierwszyBlok(short blok)
{
	this->pierwszyBlok = blok;
}

short iWezel::pobierzPierwszyBlok()
{
	return this->pierwszyBlok;
}

void iWezel::ustawDrugiBlok(short blok)
{
	this->drugiBlok = blok;
}

short iWezel::pobierzDrugiBlok()
{
	return this->drugiBlok;
}

void iWezel::ustawIndeksowyBlok(short blok)
{
	this->indeksowyBlok = blok;
}

short iWezel::pobierzIndeksowyBlok()
{
	return this->indeksowyBlok;
}
