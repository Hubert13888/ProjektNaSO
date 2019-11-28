#include <map>
#include <vector>
#include <functional>
#include <string>
#include <regex>

using namespace std;

//Tymczasowy obiekt PCB
class PCB {
public:
	int A, B, C, D, l_rozkazow;
};

void zapisz_do_rejestru(string regFrom, int value);

void interpretuj(PCB *pcb);

vector<string> pobierz_bajty_z_pamieci(int ilosc);