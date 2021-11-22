#include "application_interface.h"

void application_interface::DelConsole()
{
	fclose(file);
	FreeConsole();
}