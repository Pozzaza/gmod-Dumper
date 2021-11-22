#include <ios>
#include "SDK.h"
#include "Interface.h"
#include "netvar_manager.h"
#include "application_interface.h"

struct varialbles
{
    IBaseClientDLL* BaseClientDLL = (IBaseClientDLL*)CreateInterface("client.dll", "VClient017");
    DWORD client = (DWORD)GetModuleHandle("client.dll");
    DWORD server = (DWORD)GetModuleHandle("server.dll");
    ClientClass* ClientClasses = (ClientClass*)BaseClientDLL->GetAllClasses();
    DWORD entity = client + 0x6ADF2C;
    DWORD MAX_PLAYERS = server + 0x984BA4;
}var;



DWORD WINAPI MAIN_THREAD(HMODULE hmodule)
{
    application_interface AppInterface;

    while (!(GetAsyncKeyState(VK_END) & 1))
    {

        if (GetAsyncKeyState(VK_F8) & 1) {
            netvar_manager::GetAll(var.ClientClasses);
        }

    }
    AppInterface.DelConsole();
    FreeLibraryAndExitThread(hmodule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        HANDLE handle = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)MAIN_THREAD, hModule, 0, nullptr);
        if (handle)
            CloseHandle(handle);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

