#pragma once
#include <string>
#include <vector>
#include <array>
#include <iostream>
using namespace std;


class katalog
{
public:
	katalog();
	katalog(string nazwa);
	katalog(string nazwa, short wskaznikNaOjca);
	void wypiszKatalog();
	void ustawNazwe(string nazwa);
	string pobierzNazwe();
	void dodajNumerIwezela(short numer); // Dodaje przekazany numer iWezela do kolekcji numeryIwezlow
	void usunNumerIwezla(short numer); // Usuwa przekazany numer z kolejcji numeryIwezlow
	vector<short> pobierzNumery(); // Zwraca kolekcje numeryIwezlow
	void ustawOjca(short ojciec);
	short pobierzOjca();
	void ustawSyna(short syn);
	array<short, 32> pobierzSynow(); // Zwraca kolekcj� podfolder�w
	void usunSyna(short syn);
	short ilePodfolderow();
	void ustawPodfoldery(int i);
private:
	string nazwa;
	vector<short> numeryIwezlow; // vektor przechowujacy numery i-wezlow w katalogu
	short wskaznikNaOjca;
	array<short, 32> wskaznikNaPodfolder; // folder moze miec podfoldery
	short podfoldery;
};