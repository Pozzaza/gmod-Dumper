#pragma once
#include <ios>
#include <Windows.h>
class application_interface
{
private:
	FILE* file = nullptr;
public:
	application_interface()
	{
		AllocConsole();
		freopen_s(&file, "CONOUT$", "w", stdout);

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	}

	void DelConsole();
	
	
};

