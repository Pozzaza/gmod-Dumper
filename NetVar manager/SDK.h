#pragma once
#include <Windows.h>

class RecvTable;

class RecvProp
{
public:
	char* m_pVarName;
	void* m_RecvType;
	int                     m_Flags;
	int                     m_StringBufferSize;
	int                     m_bInsideArray;
	const void* m_pExtraData;
	RecvProp* m_pArrayProp;
	void* m_ArrayLengthProxy;
	void* m_ProxyFn;
	void* m_DataTableProxyFn;
	RecvTable* m_pDataTable;
	int                     m_Offset;
	int                     m_ElementStride;
	int                     m_nElements;
	const char* m_pParentArrayPropName;
};

class RecvTable
{
public:

	RecvProp* m_pProps;
	int            m_nProps;
	void* m_pDecoder;
	char* m_pNetTableName;
	bool        m_bInitialized;
	bool        m_bInMainList;
};


class ClientClass
{
public:
	void*			m_pCreateFn; //1
	void*			m_pCreateEventFn; //2
	char*			m_pNetworkName; //3
	RecvTable*		m_pRecvTable; //4
	ClientClass*	m_pNext; //4
	int				m_ClassID; //5
};

class IBaseClientDLL
{
public:
	virtual void* Init(void) = 0; //1
	virtual void* PostInit(void) = 0; //2
	virtual void* Shutdown(void) = 0; //3
	virtual void* ReplayInit(void* (*)(char const*, int*)) = 0; //4
	virtual void* ReplayPostInit(void) = 0; //5
	virtual void* LevelInitPreEntity(char const*) = 0; //6
	virtual void* LevelInitPostEntity(void) = 0; //7
	virtual void* LevelShutdown(void) = 0; //8
	virtual ClientClass* GetAllClasses(void) = 0; //9
};

