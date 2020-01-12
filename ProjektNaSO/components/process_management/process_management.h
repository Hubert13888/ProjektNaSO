#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum State { UNDECLARED, RUNNABLE, SLEEPING, ZOMBIE, INIT };

class PCB {
public:
	int PID;
	string process_name;
	string program_instructions;
	State status;
	int priority; // <100, 139>
	int task_number;

	PCB() {}

	void print();
	void set_state(State stat);
};

class Process_Tree {
public:
	PCB process;
	PCB* daddy;
	vector<Process_Tree*> children;

	bool fork(PCB* proc, const string& name);

	void values_enter(PCB& proc, const string& process_name);
	PCB* find_process(const int& PID);
	PCB* find_process(const string& name);
};

//stworzyæ proces o podanym id operuj¹cy na podanym pliku
