#include "process_management.h"

int available_pid = 2;
vector<PCB*> PQ;

void PCB::print() {
	cout << "PID = " << this->PID << endl;
	cout << "name = " << this->process_name << endl;
	cout << "state = " << this->status << endl;

}

bool Process_Tree::fork(PCB* proc, const string& name) {
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

	return false;
}

void Process_Tree::values_enter(PCB& proc, const string& process_name) {
	proc.PID = available_pid;
	available_pid++;
	proc.process_name = process_name;
	proc.status = UNDECLARED;
	proc.task_number = 0;
}

PCB* Process_Tree::find_process(const int& PID) {
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