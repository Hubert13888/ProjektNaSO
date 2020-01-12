#pragma once
#include "stdafx.h"
#include <array>
#include "iwezel.h"
#include "katalog.h"
#include "wpisKatalogowy.h"
class dysk
{
public:
	dysk();
	//aby wpisac dane na dysk nalezy najpierw wyowalc funkcje 'utworzPlik' (tworzy pusty), a nastepnie 'zapiszDoPliku', aby zapisal dane
	void utworzPlik(string nazwa, string rozszerzenie, string nazwaFolderu ); //funkcja zajmuje jeden blok dyskowy i tworzy  iwezel i wpis katalogowy
																			  //na poczatu za nazwe folderu nalezy podac "Dysk"
	void zapiszDoPliku(string nazwa, string rozszerzenie, string dane, string nazwaFolderu ); //funkcja wpisuje odpowiedniu dane na bloki dyskowe
	void usunPlik(string nazwa, string rozszerzenie, string nazwaFolderu); // funkcja zwalnia bloki, czyœci wpis na dysku
	void utworzFolder(string nazwa, string nazwaNadrzednego); // funkcja tworzy folder podrzêdny w danym folderze 
	void dodajPlikDoKatalogu(string nazwaDolcelowego, string nazwaPliku, string rozszerzenie, string nazwaFolderuZPlikiem ); //dodawanie pliku do katalogu
	void usunFolder(int pozycja);// funkcja usuwajaca katalog o danej pozycji wywolywanie razem z 'znajdzFolder',np: dysk.usunFolder(dysk.znajdzFolder("nowyFolder"));
	short znajdzFolder(string nazwa); //funckja zwraca miejsce w tablicy folderow/klatalogow
	void wypiszDrzewo(); // funkcja wypisuje wszytkie informacje i plikach i katalogach
	void wypiszDysk(); // funkcja wypisuje na konsole wypelniony dysk
	void wypiszWektorBitowy(); //funkcja wypisuje na  konsole wektor bitowy
	void wypiszTabliceIwezelow(); //funkcja wypisuje na konsole tablice i-ewzlow
	void wypiszTabliceWpisow();// funkcja wypisuje na konsole tablice aktualnych wpoisow
private:
	array<iWezel, 32> tablicaIwezlow; // tablica przechowujaca i-wezly
	array<char, 1024> tablicaDysk; // rzeczywisty 'dyk'
	array<katalog, 1024> tablicaKatalogow; //tablica przechowujaca katalogi/foldery
	array<wpis, 32> tablicaWpisow; // tablica przechowujaca wpisy
	array<bool, 32> wektorBitowy; // tablica mowiaza to dostepomnosci miejsca na bloku dyskowym ->1 Blok wolny, 0 Blok zajêty
	short wielkoscBloku; //deklaracja wielkosci bloku
	int wielkoscDysku; //deklaracja wielkosci dysku
	short wolneBloki;  //itp
	int ileFolderow;
	void ileWolnych();//funkcja mowiaca o ilosci wolnych blokow indeksowych
	short znajdzPlik(string nazwa, string rozszerzenie); // funkcja zwraca numer i-wez³a w którym znajduje siê plik, jeœli plik nie istenieje -1
	short znajdzWolnyBlok(); // funkcja zwracajca numer pierwszego wolnego bloku na dysku, jeœli brak zwraca -1
	short znajdzIwezel(); // funkcja zwracajaca numer pierwszego wolnego i-wêz³a, jeœli brak zwraca -1
	string pobierzNazweFolder(short pom); //funjca zwracajca nazwe folderu, kiedy za argument podajmy pozycje w tablicy katalogow
};