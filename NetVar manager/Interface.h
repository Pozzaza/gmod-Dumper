#pragma once
#include <Windows.h>
class IClientEntityList
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual IClientEntityList* GetClientEntity(int i);
	virtual IClientEntityList* GetClientEntityFromHandle(HANDLE hEnt);
	virtual int NumberOfEntities(bool bIncludeNonNetworkable);
	virtual int GetHighestEntityIndex(void);
	virtual void SetMaxEntities(int n);
	virtual int GetMaxEntities();
};

class ent
{
public:
	char buff[144];
	int health;
};

typedef void*(__cdecl * tCreateInterface)(const char* modulename, int rtncode); //шаблон + зможемо робити так: (tCreateInterface)AnyFuncORclasses().

void* CreateInterface(const char* modulename, const char* interfaceName); //об'являємо функцію.
