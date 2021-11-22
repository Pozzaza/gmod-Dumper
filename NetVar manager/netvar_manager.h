#pragma once
#include "SDK.h"
#include <iostream>

class netvar_manager
{
public:
	static DWORD GetOffset(RecvTable* Recvtable, const char* TableName, const char* NetVarName);

	static DWORD GetNetVarOffset(const char* TableName, const char* NetVarName, ClientClass* clientclass);

	static DWORD GetAll(ClientClass* clientclass);
};

