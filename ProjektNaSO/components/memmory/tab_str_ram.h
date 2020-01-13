#pragma once
#include <string>
#include <array>
class tab_str_ram											//---wywolywanie wszystkiego za pomoca klasy paging---//
{
	std::tuple<int, int, int>pageAr[32];					//tablica stron (pozycja: 0 - identyfikator strony, 1 - identyfikator ramki, 2 - identyfikator procesu (jesl 0 ramka wolna))
	//std::pair<int, int>pagAr[32];							//tablica stron (pozycja 1 to identyfikator strony, pozycja 2 to identyfikator ramki)
	//std::pair<int, int>procAr[32];						//sluzy do oznaczania zajetosci ramki (pozycja 1 to identyfikator strony, pozycja 2 to pid(jesl 0 ramka wolna))
	char val;
	int rNr;
	std::array<char,512> ramAr;								//pamiec podzialona na 32 ramki o rozmiarze 16 znakow
	void removeP(int nr);
public:
	tab_str_ram();
	~tab_str_ram();
	char readM(int pid, int adrP, int offset);				//odczyt z pamieci
	void writeM(int pid, int adrP, int offset, char data);	//zapis do pamieci
	void clearM(int pid);									//usuwanie z pamieci danych dla danego procesu
	void display();											//wyswietlanie obrazu pamieci
	bool checkPageArR(int pid, int adrP);					//kontrola tablicy stron dla odczytu
	bool checkPageArW(int pid, int adrP);					//kontrola tablicy stron dla zapisy
	int findAdr(int adrP, int off);							//funkcja do odnajdywania komorki o danym adresie
	int findMem();											//funkcja do odnajdywania wolnych ramek
};