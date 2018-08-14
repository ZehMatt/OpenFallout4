#include "hooks.h"
#include "interopbase.h"

#include <windows.h>
#include <stdio.h>
#include <utility>
#include <conio.h>
#include <assert.h>

namespace interop {

// NOTE: I'm not using a vector here as it seems that the memory vanishes on DllMain and entries will be lost.
static size_t _hookQueueSize = 0;
static std::pair<uintptr_t, void*> _hookQueue[1024] = {};

bool hook(void *src, void *target)
{
    assert(isInitialized());

    DWORD oldProt;
    if (VirtualProtect(src, 16, PAGE_EXECUTE_READWRITE, &oldProt) == FALSE)
    {
        OutputDebugStringA("VirtualProtect failed!");
        return false;
    }

    uint8_t *buf = (uint8_t*)src;
    buf[0] = 0xFF;
    buf[1] = 0x25;
    buf[2] = 0x00;
    buf[3] = 0x00;
    buf[4] = 0x00;
    buf[5] = 0x00;
    *(uintptr_t*)(buf + 6) = (uintptr_t)target;

    DWORD oldProt2;
    VirtualProtect(src, 16, oldProt, &oldProt2);

    FlushInstructionCache(GetCurrentProcess(), src, 16);

    char strbuf[128] = {};
    sprintf_s(strbuf, "Hook %p => %p\n", (void*)src, (void*)target);
    _cprintf("%s\n", strbuf);
    OutputDebugStringA(strbuf);

    return true;
}

bool hookTranslated(uintptr_t src, void *target)
{
    if (!isInitialized())
    {
        size_t idx = _hookQueueSize;
        _hookQueueSize++;

        auto& pair = _hookQueue[idx];
        pair.first = src;
        pair.second = target;

        return true;
    }

    void *p = (void*)translateAddr(src);
    return hook(p, target);
}

bool hookPending()
{
    _cprintf("%zd hooks (translated) in queue %p.\n", _hookQueueSize);
    for (size_t i = 0; i < _hookQueueSize; i++)
    {
        auto& p = _hookQueue[i];
        hookTranslated(p.first, p.second);
    }
    _hookQueueSize = 0;

    return true;
}

}