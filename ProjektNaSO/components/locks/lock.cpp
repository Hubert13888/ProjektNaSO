#include "lock.h"

// klasa zamek
Lock::Lock()
{
	this->lock_open = true;
	this->process_id;
	this->lock_queue;
}

// informacja o stanie zamka
bool Lock::get_lock_open()
{
	return lock_open;
}

// informacja kto zaj¹³ zamek
PCB* Lock::get_process_id()
{
	return process_id;
}

// informacja o rozmiarze kolejki
int Lock::get_queue_size()
{
	return this->lock_queue.size();
}

// ustawianie stanu zamka
void Lock::set_lock_open(bool b)
{
	this->lock_open = b;
}

// ustawianie pid (process identyficator) procesu zajmuj¹cego zamek
void Lock::set_process_id(PCB* process)
{
	if (!this->lock_open)
	{
		this->process_id = process;
		std::cout << "[Sync] Proces o pid " << process->PID << " zamknal zamek.\n";
	}
	else std::cout << "[Sync] Zamek otwarty";
}

// dodawanie pid procesu na koniec kolejki
bool Lock::add_to_lock_queue(PCB *process)
{
	if (!this->is_open)
	{
		this->lock_queue.push(process);
		return 1;
	}
	else return 0; //funkcja zwraca czy proces dodal sie do kolejki
}

// usuwanie pid procesu z pocz¹tku kolejki
PCB* Lock::remove_from_lock_queue()
{
	PCB* process = this->lock_queue.front();
	this->lock_queue.pop();
	return process; // w tej f. nastepuje usuniecie procesu z kolejki (ktory czekal na swoja kolej by moc pracowac na danych wspoldzielonych - zostaje on wywolywany przez
	//poprzedzajacy go proces, ktory wlasnie otweozryl zamek) return jest po to zeby procesor wiedzial ktory proces zostal wybudzony czyli przeszedl to stanu gotowosci 
}

// zamykanie zamka
void Lock::lock_lock(Lock *l, PCB *process) //zamek zawsze jest wskaznikiem, proces tez
{
	if (l->get_is_open()) //jezeli zamek otwarty
	{
		l->set_is_open(false); //zamknij zamek
		l->set_who_closed(process);  //ustaw jaki proces go zamknal
		// proces wykonuje sekcjê krytyczn¹ - poczytaj
	}

	else // czyli jak jest zamkniety
	{
		if (l->get_process_id() != process) // jezeli jest zamkniety przez inny proces, niz ten ktory chce zaczal dzialac na wpoldzielonych danych
		{
			if (l->add_to_lock_queue(process)) //jesli proces sie dodal do kolejki to
			{
				process->set_state(WAITING); //ustala stan procesu na oczekujacy
			}
			std::cout << "[Sync] Zamek zamkniety. Proces laduje w kolejce.\n";
		}
		// proces zmienia stan na waiting.
		else // moze sie zdarzyc, kiedy proces ktory zamknal zamek chce go znowusz zamknac 
		{
			std::cout << "[Sync] Zamek jest juz zajety przez ten proces.\n";
		}
	}
}

// otwieranie zamka
void Lock::lock_unlock(Lock* l)
{
	if (l->get_is_open())
	{
		std::cout << "[Sync] Zamek jest juz otwarty.\n";
	}
	else
	{
		if (l->get_queue_size()) //jezeli kolejka jest wieksza od 0 to
		{
			PCB *process;
			process = l->remove_from_lock_queue(); // usuwa pierwszy proces z kolejki i zwraca ktory usunal
			process->set_state(READY); //ustala stan tego procesu na gotowosc
			if (l->get_queue_size() == 1)
				std::cout << "[Sync] Nastepny proces: " << process->PID << ". W kolejce oczekuje jeszcze 1 proces.\n";
			else
				std::cout << "[Sync] Nastepny proces: " << process->PID << ". W kolejce oczekuje jeszcze " << l->get_queue_size() << " procesow.\n";
		}
		else // jezeli kolejka jest rowna 0
		{
			l->set_is_open(true); //otwieram zamek
			std::cout << "[Sync] Brak procesow w kolejce. Otwieranie zamka.\n";
		}
	
	}
	
}