#pragma once
#include <ios>
#include <iostream>
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
		SetConsoleTitle("NetVar Dumper");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	}

	
	void DelConsole();

	bool SetColor(int TextColor);

	void TextArt(int TextColor = FOREGROUND_GREEN);

	void TextFunctionals(int TextColor = 15);

	
};

