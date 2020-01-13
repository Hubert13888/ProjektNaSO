#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum State{ UNDECLARED, RUNNING, SLEEPING, ZOMBIE, INIT };

class PCB {
public:
	int PID;
	string process_name;
	string program_instructions;
	State status;
	int priority; // <100, 139>
	int task_number;
	int done_task_number;
	float Q;
	
	PCB() { this->status = UNDECLARED; }

	PCB(int a) {
		this->PID = a;
		this->program_instructions = "";
		this->process_name = "Dummy";
		this->status = INIT;
	}
	
	void print();
	void set_state(State stat);
};

class Process_Tree {
public:
	PCB process;
	PCB* daddy;
	vector<Process_Tree*> children;

	bool fork(PCB* proc, const string& name);
	bool fork(PCB* proc, const string& name, const string& instructions);
	
	void values_enter(PCB& proc, const string& process_name);
	PCB* find_process(const int& PID);
	PCB* find_process(const string& name);
};

//stworzy� proces o podanym id operuj�cy na podanym pliku