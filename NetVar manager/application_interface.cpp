#include "application_interface.h"



void application_interface::DelConsole()
{
	fclose(file);
	FreeConsole();
}

bool application_interface::SetColor(int TextColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TextColor);
	return true;
}

void application_interface::TextArt(int TextColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TextColor);
	std::cout << "\t _   _        _ __      __            _____                                       " << std::endl;
	std::cout << "\t| \\ | |      | |\\ \\    / /           |  __ \\                                      " << std::endl;
	std::cout << "\t|  \\| |  ___ | |_\\ \\  / /__ _  _ __  | |  | | _   _  _ __ ___   _ __    ___  _ __ " << std::endl;
	std::cout << "\t| . ` | / _ \\| __|\\ \\/ // _` || '__| | |  | || | | || '_ ` _ \\ | '_ \\  / _ \\| '__|" << std::endl;
	std::cout << "\t| |\\  ||  __/| |_  \\  /| (_| || |    | |__| || |_| || | | | | || |_) ||  __/| |   " << std::endl;
	std::cout << "\t|_| \\_| \\___| \\__|  \\/  \\__,_||_|    |_____/  \\__,_||_| |_| |_|| .__/  \\___||_|   " << std::endl;
	std::cout << "\t                                                               | |                " << std::endl;
	std::cout << "\t                                                               |_|                " << std::endl;
}

void application_interface::TextFunctionals(int TextColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TextColor);

	std::cout << "\t\t+-----------------------------------+\n";
	std::cout << "\t\t|   [F8] - print all NetVar         |\n";
	std::cout << "\t\t|                                   |\n";
	std::cout << "\t\t|   [END] - Close console           |\n";
	std::cout << "\t\t+-----------------------------------+\n" << std::endl;
}


