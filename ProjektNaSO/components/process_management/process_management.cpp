#include "process_management.h"

int available_pid = 2;
vector<PCB*> PQ;

void PCB::print() {
	cout << "____________________" << endl;
	cout << "PID = " << this->PID << endl;
	cout << "Nazwa = " << this->process_name << endl;
	if (this->status == 0) cout << "Status = UNDECLARED" << endl;
	if (this->status == 1) cout << "Status = RUNNING" << endl;
	if (this->status == 2) cout << "Status = SLEEPING" << endl;
	if (this->status == 3) cout << "Status = ZOMBIE" << endl;
	if (this->status == 4) cout << "Status = INIT" << endl;
	cout << "Priorytet = " << this->priority << endl;
	cout << "Nazwa pliku = " << this->program_instructions << endl;
	cout << "____________________" << endl;

}


bool Process_Tree::fork(PCB* proc, const string& name) {
	if (find_process(name))
	{
		cout << "Proces o danej nazwie juz istnieje" << endl;
		return false;
	}
	else {
		if (proc->PID == process.PID)
		{
			Process_Tree* new_proc = new Process_Tree();
			new_proc->daddy = proc;
			values_enter(new_proc->process, name);
			children.push_back(new_proc);
			cout << "proces z inita" << endl;
		}
		else {
			//szukanie procesu ktorego wskazalismy jako ojca wsrod potomkow procesu init
			for (Process_Tree* temp1 : children)
			{
				if (temp1->process.PID == proc->PID)
				{
					Process_Tree* new_proc = new Process_Tree();
					new_proc->daddy = proc;
					values_enter(new_proc->process, name);
					temp1->children.push_back(new_proc);
					break;
				}
				//szukanie procesu ktorego wskazalismy jako ojca wsrod dzieci potomkow procesu init
				else if (temp1->children.size() != 0)
				{
					for (Process_Tree* temp2 : temp1->children)
					{
						if (temp2->process.PID == proc->PID)
						{
							Process_Tree* new_proc = new Process_Tree();
							new_proc->daddy = proc;
							values_enter(new_proc->process, name);
							temp2->children.push_back(new_proc);
							break;
						}
					}
				}
			}
		}
		return true;
	}
}

//bool fork(PCB* proc, const string& name, const string& instructions) {
//
//}

void Process_Tree::values_enter(PCB & proc, const string & process_name) {
	proc.PID = available_pid;
	available_pid++;
	proc.process_name = process_name;
	proc.program_instructions = "";
	proc.priority = 120;
	proc.status = UNDECLARED;
	proc.task_number = 0;
}

PCB* Process_Tree::find_process(const int& PID){
	if (process.PID == PID)
	{
		return &process;
	}
	else
	{
		for (Process_Tree* i : children)
		{
			if (i->process.PID == PID)
			{
				return &i->process;
			}
		}
		for (Process_Tree* i : children)
		{
			PCB* foundPCB = i->find_process(PID);
			if (foundPCB != nullptr)return foundPCB;
		}
		return nullptr;
	}
}

PCB* Process_Tree::find_process(const string& name) {
	if (process.process_name == name)
	{
		return &process;
	}
	else
	{
		for (Process_Tree* i : children)
		{
			if (i->process.process_name == name)

				return &i->process;
			;
		}
		for (Process_Tree* i : children)
		{
			PCB* foundPCB = i->find_process(name);
			if (foundPCB != nullptr)return foundPCB;
		}
		return nullptr;
	}
}


void PCB::set_state(State stat) {
	switch (stat) {
	case UNDECLARED:
	{
		this->status = stat;
		break;
	}
	case RUNNING:
	{
		if (this->status == SLEEPING || this->status == RUNNING) break;
		else
		{
			this->status = SLEEPING;
			PQ.push_back(this);
			break;
		}
	}
	case SLEEPING:
	{
		if (this->status == SLEEPING || this->status == RUNNING) break;
		else
		{
			if (this->process_name != "") {
				this->status = SLEEPING;
				PQ.push_back(this);
				break;
			}
			else break;
		}
	}
	case ZOMBIE:
	{
		auto it = find(PQ.begin(), PQ.end(), this);
		if (it != PQ.end()) {
			this->status = ZOMBIE;
		}
		else {
			PQ.erase(it);
			this->status = ZOMBIE;
		}
	}
	}
}