#include <windows.h>
#include <stdint.h>
#include <conio.h>
#include <algorithm>
#include <math.h>

#include "interop.h"

/*
00000000 struct_1        struc ; (sizeof=0x50, mappedto_282)
00000000                                         ; XREF: ComputeDeltaTime+39/o
00000000                                         ; ComputeDeltaTime+49/o ...
00000000 startCounter    dq ?
00000008 maxFrameRateMs  dd ?
0000000C anonymous_1     dd ?
00000010 scaledDeltaTime dd ?
00000014 anonymous_3     dd ?
00000018 deltaTime       dq ?
00000020 startTimestamp  dq ?
00000028 deltaMinusDelta dq ?
00000030 deltaUnknown    dq ?
00000038 counter         dd ?
0000003C bChangeTimeMultSlowly dd ?
00000040 anonymous_10    dd ?
00000044 anonymous_11    dd ?
00000048 anonymous_12    dd ?
0000004C anonymous_13    dd ?
00000050 struct_1        ends
*/

#pragma pack(push, 1)
struct TimeData_t
{
    uint64_t startCounter;
    float maxFrameRateMs;
    float anonymous_1;
    float scaledDeltaTime;
    float unscaledDeltaTime;
    int64_t deltaTime;
    uint64_t startTimestamp;
    uint64_t delta1;
    uint64_t delta2;
    float counter;
    uint32_t bChangeTimeMultSlowly;
};
#pragma pack(pop)

float *gTimeScale = nullptr;
float *gDeltaTime = nullptr;
uint64_t *gFrequency = nullptr;

uint64_t gLastUpdateTime = 0;

constexpr uintptr_t AddressToRVA(uintptr_t addr)
{
    return addr - 0x140000000;
}

uintptr_t GetDynamicAddressHelper(uintptr_t hMod, uintptr_t addr)
{
    return hMod + AddressToRVA(addr);
}

template<typename T>
void ProtectedWrite(T *v, T val)
{
    DWORD oldProt;
    VirtualProtect(v, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProt);

    *v = val;

    DWORD oldProt2;
    VirtualProtect(v, sizeof(T), oldProt, &oldProt2);
}

template<typename T>
T* GetDynamicAddress(uintptr_t hMod, uintptr_t addr)
{
    return (T*)GetDynamicAddressHelper(hMod, addr);
}

// elapsedTime = 1000 * (now.QuadPart - timeData->startTimestamp) / gFrequency
extern "C" __declspec(dllexport) int64_t ComputeDeltaTime(void *data, uint32_t elapsedTime)
{
    TimeData_t *timeData = (TimeData_t*)data;

    int64_t res;

    if ((uint32_t)timeData->counter)
    {
        res = 0;
        timeData->scaledDeltaTime = 0.0f;
    }
    else
    {
        int64_t delta = elapsedTime - timeData->startTimestamp;

        float elapsed = (float)delta * 0.001f;
        if (timeData->maxFrameRateMs == 0.0f)
        {
            // Uncapped.
            res = 166;
            int64_t v7 = delta - timeData->deltaTime;
            if (v7 <= 166)
            {
                res = delta - timeData->deltaTime;
                if(v7 < 8)
                    res = 8;

                float v8 = (float)res;
                if(res < 0)
                    v8 += 1.8446744e19f;

                timeData->unscaledDeltaTime = v8 * 0.001f;
            }
        }
        else
        {
            // Capped.
            float v5 = timeData->maxFrameRateMs + timeData->anonymous_1;
            
            timeData->unscaledDeltaTime = timeData->maxFrameRateMs * 0.001f;
            res = (unsigned int)(signed int)v5;

            delta = timeData->deltaTime + res;
            timeData->anonymous_1 = v5 - (float)v5;
        }

        timeData->deltaTime = delta;
        timeData->scaledDeltaTime = timeData->unscaledDeltaTime * (*gTimeScale);
    }

    return res;
}

void HookFunction(void *src, void *target)
{
    DWORD oldProt;
    VirtualProtect(src, 1024, PAGE_EXECUTE_READWRITE, &oldProt);

    uint8_t *buf = (uint8_t*)src;
    buf[0] = 0xFF;
    buf[1] = 0x25;
    buf[2] = 0x00;
    buf[3] = 0x00;
    buf[4] = 0x00;
    buf[5] = 0x00;
    *(uintptr_t*)(buf + 6) = (uintptr_t)target;

    DWORD oldProt2;
    VirtualProtect(src, 1024, oldProt, &oldProt2);

    FlushInstructionCache(GetCurrentProcess(), src, 1024);
}

void FixConstants(uintptr_t hModule)
{
    float *minFrameDelta = GetDynamicAddress<float>(hModule, 0x142CC1340);

    ProtectedWrite(minFrameDelta, 1.0f / 144.0f);
}

void InitializeGlobals(uintptr_t hModule)
{
    gTimeScale = GetDynamicAddress<float>(hModule, 0x14387D7D0);
    gFrequency = GetDynamicAddress<uint64_t>(hModule, 0x145B946B0);
    gDeltaTime = GetDynamicAddress<float>(hModule, 0x142E67244);
}

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

