#include "Interface.h"

void* CreateInterface(const char* modulename, const char* interfaceName) //�������� �������.
     
{
	int rtncode = 0;
	tCreateInterface CreateInterface = (tCreateInterface)GetProcAddress(GetModuleHandle(modulename), "CreateInterface");

	void* Interface = CreateInterface(interfaceName, rtncode);

	return Interface;

}