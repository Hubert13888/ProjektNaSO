#include "assembler.hpp"

PCB *currPCB;
vector<string> wykonywany_rozkaz;

regex dla_wartosci("[\d]+");
regex dla_adresu("[[][0-9]+[]]");
regex dla_rejestru("[ABCD]");

map<string, int> ilosc_arg = {
	{"PN", 2}, //przeniesienie
	{"DD", 2}, //dodawanie
	{"OD", 2}, //odejmowanie
	{"MN", 2}, //mnożenie
	{"IK", 1}, //inkrementacja
	{"DK", 1}, //dekrementacja

	{"JR", 3}, //==
	{"JN", 3}, //!=
	{"JW", 3}, //>
	{"JM", 3}, //<
	{"SK", 1}, //skok bezwarunkowy
	{"ZT", 0}, //zatrzymaj proces

	{"OT", 3}, //otwarcie pliku
	{"ZP", 4}, //zapis do pliku
	{"OP", 3}, //odczyt z pliku
	{"ZM", 1}, //zamknięcie pliku

	{"TP", 2}, //tworzy proces
	{"UP", 1}, //usuwa proces
	{"WD", 3}, //wysyła dane do procesu
	{"PD", 3}  //odbiera dane z procesu
};

int adres_logiczny(string argument) {
	string liczba;
	for (int i = 1; i < argument.length() - 2; i++)
		liczba.push_back(argument[i]);
	return stoi(liczba);
}

//1-dodawanie
//2-odejmowanie
//3-mnożenie

void operacja_matematyczna(int operacja) {
	int l1, l2;

	if (regex_match(wykonywany_rozkaz[2], dla_adresu)) {
		//l1 = czytaj_pamiec(currPCB, adres_logiczny(wykonywany_rozkaz[2]));
	}
	else if (regex_match(wykonywany_rozkaz[2], dla_wartosci))
		l1 = stoi(wykonywany_rozkaz[2]);

	else if (regex_match(wykonywany_rozkaz[2], dla_rejestru))
		l1 = odczytaj_rejestr(wykonywany_rozkaz[2]);

	if (regex_match(wykonywany_rozkaz[1], dla_adresu)) {
		//l2 = czytaj_pamiec(currPCB, adres_logiczny(wykonywany_rozkaz[1]));

		switch (operacja) {
		case 1:
			//zapisz_do_pamieci(currPCB, gdzie_zapisac, l2+l1);
			break;
		case 2:
			//zapisz_do_pamieci(currPCB, gdzie_zapisac, l2-l1);
			break;
		case 3:
			//zapisz_do_pamieci(currPCB, gdzie_zapisac, l2*l1);
			break;
		}
	}
	else if (regex_match(wykonywany_rozkaz[1], dla_rejestru)) {
		l2 = odczytaj_rejestr(wykonywany_rozkaz[1]);

		switch (operacja) {
		case 1:
			zapisz_do_rejestru(wykonywany_rozkaz[1], l2+l1);
			break;
		case 2:
			zapisz_do_rejestru(wykonywany_rozkaz[1], l2-l1);
			break;
		case 3:
			zapisz_do_rejestru(wykonywany_rozkaz[1], l2*l1);
			break;
		}
	}
}

//1 - Inkrementacja
//2 - Dekrementacja

void ink_dek(int operacja) {
	if (regex_match(wykonywany_rozkaz[1], dla_adresu)) {
		int a_logiczny = adres_logiczny(wykonywany_rozkaz[1]);
		//int do_zapisania = czytaj_pamiec(currPCB, a_logiczny);
		if (operacja == 1) {
			//zapisz_do_pamieci(currPCB, a_logiczny, do_zapisania++);
		}
		else if (operacja == 2) {
			//zapisz_do_pamieci(currPCB, a_logiczny, do_zapisania--);
		}
	}
	else if (regex_match(wykonywany_rozkaz[1], dla_rejestru)) {
		int do_zapisania = odczytaj_rejestr(wykonywany_rozkaz[1]);

			 if (operacja == 1) zapisz_do_rejestru(wykonywany_rozkaz[1], do_zapisania++);
		else if (operacja == 2) zapisz_do_rejestru(wykonywany_rozkaz[1], do_zapisania--);
	}
}

//1 - równe
//2 - nierówne
//3 - większe
//4 - mniejsze

int skoki_warunkowe(int operacja) {
	int l1, l2, l3; //l3 = czytaj_pamiec(currPCB, adres_logiczny(wykonywany_rozkaz[3]));

	if (regex_match(wykonywany_rozkaz[1], dla_adresu)) {
		//l1 = czytaj_pamiec(currPCB, adres_logiczny(wykonywany_rozkaz[1]));
	}
	else if (regex_match(wykonywany_rozkaz[1], dla_wartosci))
		l1 = stoi(wykonywany_rozkaz[1]);

	else if (regex_match(wykonywany_rozkaz[1], dla_rejestru))
		l1 = odczytaj_rejestr(wykonywany_rozkaz[1]);


	if (regex_match(wykonywany_rozkaz[2], dla_adresu)) {
		//l2 = czytaj_pamiec(currPCB, adres_logiczny(wykonywany_rozkaz[2]));
	}
	else if (regex_match(wykonywany_rozkaz[2], dla_wartosci))
		l2 = stoi(wykonywany_rozkaz[2]);

	else if (regex_match(wykonywany_rozkaz[2], dla_rejestru))
		l2 = odczytaj_rejestr(wykonywany_rozkaz[2]);

	switch (operacja) {
	case 1:
		if (l1 == l2) currPCB->l_rozkazow = l3;
		break;
	case 2:
		if (l1 != l2) currPCB->l_rozkazow = l3;
		break;
	case 3:
		if (l1 > l2) currPCB->l_rozkazow = l3;
		break;
	case 4:
		if (l1 < l2) currPCB->l_rozkazow = l3;
		break;
	}
}

map<string, function<void()>> wykonanie = {
	{"PN", []() {
		int do_zapisania;

		if (regex_match(wykonywany_rozkaz[2], dla_adresu)) {
			//do_zapisania = czytaj_pamiec(currPCB, adres_logiczny(wykonywany_rozkaz[2]));
		}
		else if (regex_match(wykonywany_rozkaz[2], dla_wartosci))
			do_zapisania = stoi(wykonywany_rozkaz[2]);

		else if (regex_match(wykonywany_rozkaz[2], dla_rejestru)) {
			do_zapisania = odczytaj_rejestr(wykonywany_rozkaz[2]);
		}

		if (regex_match(wykonywany_rozkaz[1], dla_adresu)) {
			//zapisz_do_pamieci(currPCB, adres_logiczny(wykonywany_rozkaz[1]), do_zapisania);
		}
		else if (regex_match(wykonywany_rozkaz[1], dla_rejestru)) {
			zapisz_do_rejestru(wykonywany_rozkaz[1], do_zapisania);
		}
	}},
	{"DO", []() {
		operacja_matematyczna(1);
	}},
	{"OD", []() {
		operacja_matematyczna(2);
	}},
	{"MN", []() {
		operacja_matematyczna(3);
	}},
	{"IK", []() {
		ink_dek(1);
	}},
	{"DK", []() {
		ink_dek(2);
	}},
	{"JR", []() {
		skoki_warunkowe(1);
	}},
	{"JN", []() {
		skoki_warunkowe(2);
	}},
	{"JW", []() {
		skoki_warunkowe(3);
	}},
	{"JM", []() {
		skoki_warunkowe(4);
	}},
	{"SK", []() {
		currPCB->l_rozkazow = adres_logiczny(wykonywany_rozkaz[1]);
	}},
	{"ZT", []() {
		//throw zatrzymujący proces
	}},
	{"OT", []() {

	}},
	{"ZP", []() {

	}},
	{"OP", []() {

	}},
	{"ZM", []() {

	}},

	{"TP", []() {

	}},
	{"UP", []() {

	}},
	{"WD", []() {

	}},
	{"PD", []() {

	}}
};

void zapisz_do_rejestru(string regTo, int value) {
		 if (regTo == "A") currPCB->A = value;
	else if (regTo == "B") currPCB->B = value;
	else if (regTo == "C") currPCB->C = value;
	else if (regTo == "D") currPCB->D = value;
}

int odczytaj_rejestr(string rejestr) {
		 if (rejestr == "A") return currPCB->A;
	else if (rejestr == "B") return currPCB->B;
	else if (rejestr == "C") return currPCB->C;
	else if (rejestr == "D") return currPCB->D;
}

vector<string> pobierz_bajty_z_pamieci(int ilosc) {
	vector<string> dane;
	for (int i = 0; i < ilosc; i++) {
		string dana;

		for (;;) {
			int bajt;
			//adres logiczny jest w: currPCB->l_rozkazow
			//bajt = czytaj_rozkaz(currPCB);
			currPCB->l_rozkazow++;

			if ((char)bajt == ' ' || (char)bajt == ';') break;
			dana.push_back(bajt);
		}

		dane.push_back(dana);
	}
	
	return dane;
}

void interpretuj(PCB *pcb) {
	currPCB = pcb;

	vector<string> rozkaz {"NULL"};
	
	//Pobieramy nazwę instrukcji
	rozkaz[0] = pobierz_bajty_z_pamieci(1)[0];

	//Dowiadujemy się z mapy ile argumentów ma dana instrukcja
	int ilosc_bajtow = ilosc_arg[rozkaz[0]];

	//Pobieramy argumenty z pamięci
	for (auto argument : pobierz_bajty_z_pamieci(ilosc_bajtow))
		rozkaz.push_back(argument);
	wykonywany_rozkaz = rozkaz;

	//Wykonujemy fukcję przypisaną do danego rozkazu
	wykonanie[rozkaz[0]]();

	//oddajemy kontrolę po wykonaniu rozkazu
}

