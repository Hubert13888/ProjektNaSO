#include "pch.h"
#include <iostream>
#include "components/shell/Shell.h"
#include "components/memmory/tab_str_ram.h"

int main()
{
	tab_str_ram::tab_str_ram();
	Shell shell;
	shell.run();
}