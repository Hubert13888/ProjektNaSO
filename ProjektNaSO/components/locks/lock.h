#pragma once
#include <iostream>
#include <queue>

class Lock
{
protected:

	bool lock_open;
	PCB* process_id; //PCB - identyfikator procesu
	std::queue<PCB*> lock_queue; 

public:

	Lock();

	bool get_lock_open();

	PCB* get_process_id(); //przydatne przy wybudzaniu

	int get_queue_size(); //rozmiar kolejki - jesli wiekszy od 0 to zamek zamkniety, a jezeli rowny 0, to otwiera zamek

	void set_lock_open(bool b); //ustawiam stan zamka

	void set_process_id(PCB* process); //ustawiam kto go zamknal

	bool add_to_lock_queue(PCB *process); // dodaj proces do kolejki (ten co chce zamkn¹c i nie mo¿e, czyli oczekuje)

	PCB* remove_from_lock_queue(); //usun z kolejki pierwszy proces ktory czeka³

};


void lock_lock(Lock *l, PCB *process); // zamyka zamek

void lock_unlock(Lock *l); //otwiera zamek