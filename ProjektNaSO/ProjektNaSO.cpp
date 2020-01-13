#include "pch.h"
#include <iostream>
#include "components/shell/Shell.h"
#include "components/files/dysk.h"
#include "components/files/iwezel.h"
#include "components/files/wpisKatalogowy.h"
#include "components/files/katalog.h"
int main()
{
	dysk::dysk();
	katalog::katalog();
	iWezel::iWezel();
	Shell shell;
	shell.run();
}