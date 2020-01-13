#include "paging.h"
#include <string>

paging::paging()
{
	tab_str_ram::tab_str_ram();
}


paging::~paging()
{
}

void paging::writeM(int pid, int adr, char data)
{
	convAdr(adr);
	ram.writeM(pid, this->adrPag, this->offset, data);
}

char paging::readM(int pid, int adr)
{
	convAdr(adr);
	return ram.readM(pid, this->adrPag, this->offset);
}

void paging::clearM(int pid)
{
	ram.clearM(pid);
}

void paging::display()
{
	ram.display();
}

void paging::convAdr(int adrL)
{
	this->adrPag = adrL / 16;
	this->offset = adrL % 16;
}