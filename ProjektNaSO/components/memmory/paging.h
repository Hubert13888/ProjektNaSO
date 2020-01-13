#pragma once
#include <string>
#include <bitset>
#include "tab_str_ram.h"
class paging
{
	tab_str_ram ram;
	int adrPag, offset;
	void convAdr(int adrL);									//zamiana adresu logicznego na fizyczny( zwraca adresz fizyczny, numer stronicy i offset)
public:
	paging();
	~paging();
	void writeM(int pid, int adr, char data);				//zapis
	char readM(int pid, int adr);							//odczyt
	void clearM(int pid);									//wywolanie przy usuwaniu procesu (czyszczenie pamieci z wszelkich danych procesu)
	void display();
};