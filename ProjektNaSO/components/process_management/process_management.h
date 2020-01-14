#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum State { UNDECLARED, RUNNING, SLEEPING, ZOMBIE, INIT };

class PCB {
public:
	int A, B, C, D;
	int PID;
	string process_name;
	string program_instructions;
	State status;
	int priority; // <100, 139>
	int task_number;
	int done_task_num;
	float Q;

	PCB() {
		this->status = UNDECLARED;
		this->task_number = 0;
		this->done_task_num = 0;
	}

	PCB(int a) {
		this->PID = a;
		this->program_instructions = "";
		this->process_name = "INIT";
		this->status = INIT;
		this->task_number = 0;
		this->done_task_num = 0;
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
	bool fork(PCB* proc, const string& name, const string& instructions, const int& priorytet);


	void values_enter(PCB& proc, const string& process_name);
	void values_enter(PCB& proc, const string& process_name, const string& instructions);
	void values_enter(PCB& proc, const string& process_name, const string& instructions, const int& priorytet);


	PCB* find_process(const int& PID);
	PCB* find_process(const string& name);
};

//stworzyæ proces o podanym id operuj¹cy na podanym pliku