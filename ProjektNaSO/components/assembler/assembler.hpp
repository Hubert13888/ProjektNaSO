#include <map>
#include <vector>
#include <functional>
#include <string>
#include <regex>

#include "../memmory/paging.h"
#include "../process_management/process_management.h"
#include "../files/dysk.h"

using namespace std;

int logical_address(string argument);

void math_operation(int operacja);

void inc_dec(int operacja);

int conditional_jumps(int operacja);

void save_to_register(string regFrom, int value);

int read_register(string rejestr);

void interpret(PCB *pcb);

vector<string> read_bytes(int ilosc);