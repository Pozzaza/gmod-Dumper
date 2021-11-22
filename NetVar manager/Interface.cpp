#include "Interface.h"

void* CreateInterface(const char* modulename, const char* interfaceName) //реалізуємо функцію.
     
{
	int rtncode = 0;
	tCreateInterface CreateInterface = (tCreateInterface)GetProcAddress(GetModuleHandle(modulename), "CreateInterface");

	void* Interface = CreateInterface(interfaceName, rtncode);

	return Interface;

}