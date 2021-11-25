#include "netvar_manager.h"


 DWORD netvar_manager::GetAll(ClientClass * clientclass, DWORD client)
 {
	 for (ClientClass* curr = clientclass; curr; curr = curr->m_pNext) {
			 for (int i = 0; i < curr->m_pRecvTable->m_nProps; i++) {
				 RecvProp prop = curr->m_pRecvTable->m_pProps[i];

				 std::cout << curr->m_pRecvTable->m_pNetTableName << ": " << prop.m_pVarName <<
					 " = " << std::hex << "0x" << prop.m_Offset << std::endl;
			 }
			 std::cout << " " << std::endl;
	 }
	 return 0;
 }


