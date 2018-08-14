#include "interopbase.h"
#include "hooks.h"

#include <assert.h>
#include <conio.h>
#include <stdint.h>
#include <stdio.h>
#include <windows.h>
#include <vector>

namespace interop {

static bool _initialized = false;
static uintptr_t _currentImageBase = 0;
static const uintptr_t NATIVE_IMAGEBASE = 0x140000000;

bool isInitialized()
{
    return _initialized;
}

void initialize()
{
    _currentImageBase = (uintptr_t)GetModuleHandleA(nullptr);
    _initialized = true;

    hookPending();
}

uintptr_t translateAddr(uintptr_t addr)
{
    assert(_initialized == true);

    const uintptr_t rva = addr - NATIVE_IMAGEBASE;
    return _currentImageBase + rva;
}

}
