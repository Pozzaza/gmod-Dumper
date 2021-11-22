#include "netvar_manager.h"

 intptr_t GetOffset(RecvTable* Recvtable, const char* TableName, const char* NetVarName)
{
for (int i = 0; i < Recvtable->m_nProps; i++) {
	RecvProp prop = Recvtable->m_pProps[i];
	if (!_stricmp(prop.m_pVarName, NetVarName)) {
		return prop.m_Offset;
	}

	if (prop.m_pDataTable) {
		intptr_t offset = GetOffset(prop.m_pDataTable, TableName, NetVarName);

		if (offset) {
			return offset + prop.m_Offset;
		}
	}
}
return 0;
}

 DWORD GetAllVarName(const char* TableName, ClientClass* clientclass)
 {
	 for (ClientClass* curr = clientclass; curr; curr = curr->m_pNext) {
		 if (!_stricmp(curr->m_pRecvTable->m_pNetTableName, TableName)) {
			 for (int i = 0; i < curr->m_pRecvTable->m_nProps; i++) {
				 RecvProp prop = curr->m_pRecvTable->m_pProps[i];


				 std::cout << TableName << " m_pVarName " << i << ": " << prop.m_pVarName << std::endl;
			 }
		 }
	 }
	 std::cout << " " << std::endl;
	 return 0;
 }

 intptr_t GetNetVarOffset(const char* TableName, const char* NetVarName, ClientClass* clientclass)
{
	for (ClientClass* curr = clientclass; curr; curr = curr->m_pNext) {
		if (!_stricmp(curr->m_pRecvTable->m_pNetTableName, TableName)) {
			return GetOffset(curr->m_pRecvTable, TableName, NetVarName);
		}
	}
	return 0;
}