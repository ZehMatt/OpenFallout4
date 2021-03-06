#include <windows.h>
#include <conio.h>

#include "interop/interop.h"

interop::var<HINSTANCE, 0x145ADD2E0> ghInstance;
interop::var<LPSTR, 0x145ADD2E8> gCmdLine;

interop::func<bool(), 0x140D35F80> InitializeGame;
interop::func<void(), 0x140D36C30> MainGameLoop;
interop::func<void(), 0x140D36D30> ShutdownGame;

template<typename T>
void writeProtected(T& val, T newVal)
{
    DWORD oldProt;
    VirtualProtect(&val, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProt);
    val = newVal;
    VirtualProtect(&val, sizeof(T), oldProt, &oldProt);
}

void fixConstants()
{
    // 142CC1340 = 0.016666668
    interop::var<float, 0x142CC1340> flt_142CC1340;
    writeProtected(flt_142CC1340.get(), 1.0f/144.0f);
}

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    fixConstants();

    ghInstance = hInstance;
    gCmdLine = lpCmdLine;

    if (InitializeGame())
    {
        MainGameLoop();
        ShutdownGame();
    }

    Sleep(2000);
    return 0;
}
HOOK_FUNCTION(0x140D35810, WinMain);
