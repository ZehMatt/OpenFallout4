#include <windows.h>
#include <stdint.h>
#include <conio.h>

#include "interop.h"

void initialize()
{
    AllocConsole();
    _cprintf("Hello World\n");

    interop::initialize();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        initialize();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) int OpenFallout()
{
    return 0;
}

