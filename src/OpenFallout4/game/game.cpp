#include <windows.h>
#include <conio.h>
#include <xmmintrin.h> 

#include "../interop/interop.h"
#include "game.h"

// Data
static interop::var<GameContext_t*, 0x145ADD2C8> gGameContext;
static interop::var<TimeData_t, 0x145B946C0> gTimeData2;
static interop::var<uint32_t, 0x14370C8A0> iNumHWThreads;
static interop::var<char[0x210], 0x14370C8A0> gUserName;
static interop::var<uint64_t, 0x145A3A760> qword_145A3A760;
static interop::var<char[0x50], 0x145ADE2D0> unk_145ADE2D0;
static interop::var<void*, 0x145A3E830> qword_145A3E830;
static interop::var<char[0x08], 0x145ADE390> byte_145ADE390;
static interop::var<char[0x10], 0x145ADE398> byte_145ADE398;
static interop::var<char[0x08], 0x145ADE3A8> byte_145ADE3A8;
static interop::var<void*, 0x145907BA0> qword_145907BA0;
static interop::var<uint8_t*, 0x145909918> qword_145909918;
static interop::var<uint8_t*, 0x145ADD3A8> qword_145ADD3A8;
static interop::var<uint8_t*, 0x145909B40> qword_145909B40;
static interop::var<uint8_t*, 0x145A13170> qword_145A13170;
static interop::var<uint8_t*, 0x145ADD3D8> qword_145ADD3D8;
static interop::var<uint8_t*, 0x146038088> qword_146038088;
static interop::var<uint8_t*, 0x14591BA80> qword_14591BA80;
static interop::var<uint8_t*, 0x145A98E60> qword_145A98E60;
static interop::var<uint8_t*, 0x145ADD2D0> qword_145ADD2D0;
static interop::var<int64_t, 0x145ADD548> qword_145ADD548;
static interop::var<void*, 0x145907BA8> qword_145907BA8;
static interop::var<void*, 0x145909B28> qword_145909B28;
static interop::var<void*, 0x145ADD3E8> qword_145ADD3E8;
static interop::var<void*, 0x145A92288> qword_145A92288;
static interop::var<void*, 0x145AA4DF0> qword_145AA4DF0;
static interop::var<void*, 0x145909908> qword_145909908;
static interop::var<void*, 0x145AAC618> qword_145AAC618;
static interop::var<void*, 0x1459097F8> qword_1459097F8;
static interop::var<void*, 0x14590C388> qword_14590C388;
static interop::var<void*, 0x145A12E18> qword_145A12E18;
static interop::var<void*, 0x145A986B8> qword_145A986B8;
static interop::var<void*, 0x145A98AB0> qword_145A98AB0;
static interop::var<void*, 0x145A13268> qword_145A13268;
static interop::var<void*, 0x145A9BF90> qword_145A9BF90;
static interop::var<void*, 0x145907F18> qword_145907F18;
static interop::var<void*, 0x14590D6E0> qword_14590D6E0;
static interop::var<void*, 0x145908100> qword_145908100;
static interop::var<void*, 0x145AA0A40> qword_145AA0A40;
static interop::var<void*, 0x145909B58> qword_145909B58;
static interop::var<void*, 0x145AA0260> qword_145AA0260;
static interop::var<void*, 0x145A12E20> qword_145A12E20;
static interop::var<void*, 0x145AFF540> qword_145AFF540;
static interop::var<void*, 0x14676A740> qword_14676A740;
static interop::var<uint32_t, 0x146759304> dword_146759304;
static interop::var<uint32_t, 0x1437C63A8> dword_1437C63A8;
static interop::var<uint32_t, 0x145AFF724> dword_145AFF724;
static interop::var<uint32_t, 0x1438FDF5C> dword_1438FDF5C;
static interop::var<uint32_t, 0x1438FE1E8> dword_1438FE1E8;
static interop::var<uint32_t, 0x1438FE1EC> dword_1438FE1EC;
static interop::var<uint32_t, 0x1438FE1F0> dword_1438FE1F0;
static interop::var<uint32_t, 0x1438FE1F4> dword_1438FE1F4;
static interop::var<uint32_t, 0x1437C6528> dword_1437C6528;
static interop::var<uint32_t, 0x143905E80> dword_143905E80;
static interop::var<uint32_t, 0x14676BDF4> TlsIndex;
static interop::var<uint64_t, 0x145B946B0> gFrequency;
static interop::var<float, 0x145B00A58> gDeltaAccumulator;
static interop::var<float, 0x145B00A5C> flt_145B00A5C;
static interop::var<float, 0x1437C6528> flt_1437C6528;
static interop::var<float, 0x1437C6DC8> flt_1437C6DC8;
static interop::var<float, 0x1437C65E8> flt_1437C65E8;
static interop::var<float, 0x143889EF8> flt_143889EF8;
static interop::var<float, 0x1437C70E0> fHavokTauRatio;
static interop::var<float, 0x145ADD2B0> gScaledDeltaTime;
static interop::var<char, 0x145ADD2AD> byte_145ADD2AD;
static interop::var<char, 0x1437C6618> byte_1437C6618;
static interop::var<char, 0x145ADD550> byte_145ADD550;
static interop::var<char, 0x145ADD2B7> byte_145ADD2B7;
static interop::var<char, 0x145B14E0F> byte_145B14E0F;
static interop::var<char, 0x145ADD2FC> byte_145ADD2FC;
static interop::var<char, 0x1437C6660> byte_1437C6660;
static interop::var<char, 0x145ADD2AC> byte_145ADD2AC;
static interop::var<char, 0x1437C6960> bChangeTimeMultSlowly;
static interop::var<char[128], 0x143905A00> unk_143905A00;

// Functions.
static interop::func<void(), 0x140D3EB40> CreateGameDataDirectories;
static interop::func<void(), 0x1401CEA50> GetComputerUserName;
static interop::func<void(), 0x141B1AEA0> sub_141B1AEA0;
static interop::func<void(), 0x140D245A0> sub_140D245A0;
static interop::func<void(uint32_t), 0x141B7CE00> sub_141B7CE00;
static interop::func<void(const char*), 0x141B7D110> sub_141B7D110;
static interop::func<void(), 0x14082F020> sub_14082F020;
static interop::func<void(), 0x1414A68D0> sub_1414A68D0;
static interop::func<void(), 0x141C95C40> sub_141C95C40;
static interop::func<void(), 0x1401713F0> sub_1401713F0;
static interop::func<uint64_t(void*), 0x1406A2BF0> sub_1406A2BF0;
static interop::func<void(), 0x1401B3BA0> sub_1401B3BA0;
static interop::func<void*(void*), 0x141B10EB0> sub_141B10EB0;
static interop::func<void*(void*), 0x141B10BE0> unknown_libname_4406;
static interop::func<void*(), 0x140D4BE90> sub_140D4BE90;
static interop::func<void(uint32_t), 0x14294BD50> sub_14294BD50;
static interop::func<void(void*), 0x140D38A20> sub_140D38A20;
static interop::func<int64_t(bool, uint32_t), 0x140C8EC50> sub_140C8EC50;
static interop::func<void(void*), 0x1409E5F70> sub_1409E5F70;
//static interop::func<void(GameContext_t*), 0x140D38D40> GameUpdate;
static interop::func<void*(), 0x14287C6D0> sub_14287C6D0;
static interop::func<void(void*), 0x142853DF0> sub_142853DF0;
static interop::func<int64_t(GameContext_t*), 0x140D3B6E0> sub_140D3B6E0;
static interop::func<int64_t(int32_t), 0x14294BDB0> sub_14294BDB0;
//static interop::func<int(void), 0x140D39B50> ComputeTimeDelta;
static interop::func<int(void*), 0x141B62EA0> sub_141B62EA0;
static interop::func<void(double), 0x140267FA0> BeginFrame;
static interop::func<int64_t(), 0x140D3BE30> sub_140D3BE30;
static interop::func<bool(void*, uint32_t), 0x14124E6D0> sub_14124E6D0;
static interop::func<int64_t(GameContext_t*), 0x140D39D20> sub_140D39D20;
static interop::func<bool(), 0x140D40C90> ProcessMessages;
static interop::func<int64_t(), 0x140CBCEC0> sub_140CBCEC0;
static interop::func<int64_t(void*, uint8_t), 0x1427D4670> sub_1427D4670;
static interop::func<int64_t(void*), 0x1427D3FF0> sub_1427D3FF0;
static interop::func<int64_t(void*), 0x140DB4E60> sub_140DB4E60;
static interop::func<int64_t(void*, void*, uint8_t, uint8_t), 0x1400FB170> sub_1400FB170;
static interop::func<void(void*, uint32_t), 0x141CA38F0> sub_141CA38F0;
static interop::func<void(void*, void*, char, float, char), 0x1400FB350> sub_1400FB350;
static interop::func<bool(uint64_t), 0x1403B3700> sub_1403B3700;
static interop::func<int64_t(), 0x14282EE50> sub_14282EE50;
static interop::func<bool(void*, uint32_t), 0x1427D4B90> sub_1427D4B90;
static interop::func<int64_t(void*), 0x14018C340> sub_14018C340;
static interop::func<int64_t(void*), 0x140CF13A0> sub_140CF13A0;
static interop::func<bool(), 0x140D3C800> sub_140D3C800;
static interop::func<int64_t(void*), 0x140EA6470> sub_140EA6470;
static interop::func<uint8_t(void*, uint64_t*), 0x142042040> sub_142042040;
static interop::func<void*(), 0x14204B8B0> sub_14204B8B0;
static interop::func<void*(), 0x14204B6D0> sub_14204B6D0;
static interop::func<void*(), 0x14204BFD0> sub_14204BFD0;
static interop::func<void*(), 0x14204C330> sub_14204C330;
static interop::func<void*(), 0x14204B850> sub_14204B850;
static interop::func<void*(), 0x14204B5B0> sub_14204B5B0;
static interop::func<int64_t(), 0x140D0CCD0> sub_140D0CCD0;
static interop::func<int64_t(void*), 0x140D1D730> sub_140D1D730;
static interop::func<int64_t(void*, uint64_t), 0x140D19F30> sub_140D19F30;
static interop::func<int64_t(), 0x140CBCE50> sub_140CBCE50;
static interop::func<uint8_t(void*), 0x1427D3280> sub_1427D3280;
static interop::func<uint8_t(), 0x140D3C000> sub_140D3C000;
static interop::func<uint8_t(), 0x140D413D0> sub_140D413D0;
static interop::func<uint8_t(void*, char), 0x140D3A210> sub_140D3A210;
static interop::func<int64_t(uint8_t), 0x1403DE8C0> sub_1403DE8C0;
static interop::func<void*(), 0x14038AC50> sub_14038AC50;
static interop::func<uint64_t(void*), 0x1407ED4F0> sub_1407ED4F0;
static interop::func<int64_t(void*, void*), 0x1407F8CC0> GsDriverEntry;
static interop::func<uint64_t(void*), 0x141372030> sub_141372030;
static interop::func<uint64_t(void*), 0x141372290> sub_141372290;
static interop::func<uint64_t(void*, float, float), 0x140E146C0> sub_140E146C0;
static interop::func<int64_t(void*, char), 0x141084620> sub_141084620;
static interop::func<uint64_t(), 0x140D396C0> sub_140D396C0;
static interop::func<uint64_t(void*), 0x141B2BD10> sub_141B2BD10;
static interop::func<uint64_t(), 0x14125BE70> sub_14125BE70;
static interop::func<uint64_t(void*, void*), 0x141B2D1E0> sub_141B2D1E0;
static interop::func<uint64_t(), 0x140A51050> sub_140A51050;
static interop::func<uint64_t(void*), 0x140A510E0> sub_140A510E0;
static interop::func<void(), 0x140D39A10> sub_140D39A10;
static interop::func<void(uint32_t), 0x141B63050> sub_141B63050;
static interop::func<void(void*), 0x1401819F0> sub_1401819F0;
static interop::func<void**(), 0x1401E4B30> sub_1401E4B30;
static interop::func<int64_t(void*, float), 0x140F0DC60> sub_140F0DC60;
static interop::func<int64_t(), 0x140D24360> sub_140D24360;
static interop::func<int64_t(), 0x141BA5830> sub_141BA5830;
static interop::func<int64_t(void*, void*, char, void*), 0x1400F57C0> sub_1400F57C0;
static interop::func<__m128(void*), 0x14124D0C0> sub_14124D0C0;
static interop::func<int64_t(void*, float, char, void*), 0x1428451A0> sub_1428451A0;
static interop::func<void(float), 0x1427FC090> sub_1427FC090;
static interop::func<bool(uint32_t), 0x140CBCD50> sub_140CBCD50;
static interop::func<bool(), 0x1401EF270> sub_1401EF270;
static interop::func<uint32_t(uint32_t, uint32_t), 0x141B630F0> sub_141B630F0;
static interop::func<int64_t(), 0x140D39940> sub_140D39940;
static interop::func<int64_t(void*), 0x142572910> sub_142572910;
static interop::func<int64_t(void*, float), 0x140D3A8A0> sub_140D3A8A0;
static interop::func<int64_t(void*), 0x140D385E0> sub_140D385E0;
static interop::func<uint32_t(), 0x140CBCE80> sub_140CBCE80;
static interop::func<int64_t(void*, void*), 0x141B0F330> sub_141B0F330;
static interop::func<void*(void*), 0x141B0E350> sub_141B0E350;
static interop::func<int64_t(void*), 0x141B14600> sub_141B14600;
static interop::func<int64_t(void*), 0x140C20300> sub_140C20300;
static interop::func<int64_t(), 0x1409FD050> sub_1409FD050;
static interop::func<int64_t(void*), 0x142042310> sub_142042310;
static interop::func<int64_t(void*), 0x142043410> sub_142043410;
static interop::func<int64_t(void*), 0x1409FD260> sub_1409FD260;
static interop::func<int64_t(), 0x14125B660> sub_14125B660;
static interop::func<int64_t(void*), 0x140D3A480> EndFrame;
static interop::func<int64_t(float), 0x140268090> sub_140268090;
static interop::func<int64_t(float), 0x1409C02F0> sub_1409C02F0;
static interop::func<int64_t(float), 0x140E61300> sub_140E61300;
static interop::func<int64_t(float), 0x1409C4510> sub_1409C4510;
static interop::func<int64_t(), 0x142486E10> sub_142486E10;
static interop::func<int64_t(), 0x140C8C450> sub_140C8C450;
static interop::func<bool(void*), 0x140E00AA0> sub_140E00AA0;
static interop::func<int64_t(float), 0x140832290> sub_140832290;
static interop::func<int64_t(void*, void*), 0x140D398A0> sub_140D398A0;
static interop::func<int64_t(void*), 0x1413723D0> sub_1413723D0;
static interop::func<int64_t(), 0x1404E4C20> sub_1404E4C20;
static interop::func<int64_t(void*, float, uint32_t), 0x140D57E80> sub_140D57E80;
static interop::func<int64_t(void*, char), 0x140685940> sub_140685940;
static interop::func<int64_t(void*), 0x141B14610> sub_141B14610;
static interop::func<int64_t(), 0x1404E5070> sub_1404E5070;
static interop::func<int64_t(), 0x1404E1510> sub_1404E1510;
static interop::func<int64_t(void*), 0x1428C3690> sub_1428C3690;
static interop::func<int64_t(), 0x140D0CCA0> sub_140D0CCA0;
static interop::func<int64_t(void*), 0x14204AE30> sub_14204AE30;
static interop::func<int64_t(float), 0x141D6E8E0> TtbhkWorld_SetDeltaTime;
static interop::func<void(), 0x141B13900> SetTimeScale;
static interop::func<LARGE_INTEGER(), 0x141B13900> GetCurrentCounter;
static interop::func<int64_t(TimeData_t*, uint32_t), 0x141B137B0> sub_141B137B0;
static interop::func<int64_t(void*), 0x141371EB0> sub_141371EB0;

// Const
static const char *lpClassName = "Fallout4";

bool __stdcall InitializeGame()
{
    _cprintf("%s\n", __FUNCTION__);

    /*
    v0 = *(_QWORD *)(__readgsqword(0x58u) + 8i64 * (unsigned int)TlsIndex);
    *(_DWORD *)(v0 + 2496) = 2;
    */

    CoInitialize(nullptr);
    CreateGameDataDirectories();

    if(iNumHWThreads < 4)
        iNumHWThreads = 4;

    HWND hWnd = FindWindowA(lpClassName, nullptr);
    if (hWnd != nullptr)
    {
        SetForegroundWindow(hWnd);
        return false;
    }

    GetComputerUserName(); // Fills gUserName
    sub_141B1AEA0();
    // nullsub_701();
    sub_140D245A0();
    sub_141B7CE00(0);
    sub_141B7D110("DATA");
    sub_14082F020();
    sub_1414A68D0();
    sub_141C95C40();
    sub_1401713F0();

    if (!qword_145A3A760)
    {
        qword_145A3A760 = sub_1406A2BF0(unk_145ADE2D0.get());
    }

    sub_1401B3BA0();

    if (!qword_145A3E830)
    {
        qword_145A3E830 = &byte_145ADE390.get();
        sub_141B10EB0(&byte_145ADE398.get());
        unknown_libname_4406(&byte_145ADE3A8.get());
        qword_145A3E830 = &byte_145ADE390.get();
    }

    if (!qword_145907BA0)
        qword_145907BA0 = sub_140D4BE90();
    /*
    sub_1409C2D70();

    v4 = time64(&Time);
    sub_141B129F0(v4);
    sub_141B3F8E0(0i64);
    sub_140633150();

    v5 = *(_DWORD *)(v0 + 2496);
    *(_DWORD *)(v0 + 2496) = 59;
    v6 = sub_1414812D0();
    sub_1429514A0(v6, 0i64, 0i64, 0i64, 0, 0, 0i64, 0i64);
    *(_DWORD *)(v0 + 2496) = v5;
    sub_140D4D170();
    sub_1405502E0(qword_1460D4DC0, "Software\\Bethesda Softworks\\Fallout4");
    sub_140024120();
    v7 = qword_145F14528;
    v8 = *(_DWORD *)(v0 + 2496);
    v9 = (char *)(qword_145F14528 + 8);
    *(_DWORD *)(v0 + 2496) = 99;
    if (&Src != v9)
        strcpy_s(v9, 0x104ui64, &Src);
    if ((*(unsigned __int8(__fastcall **)(__int64, _QWORD))(*(_QWORD *)v7 + 40i64))(v7, 0i64))
    {
        (*(void(__fastcall **)(__int64))(*(_QWORD *)v7 + 72i64))(v7);
        (*(void(__fastcall **)(__int64))(*(_QWORD *)v7 + 48i64))(v7);
    }
    *(_DWORD *)(v0 + 2496) = v8;
    strcpy_s(&Src, 0x104ui64, byte_145F14640);
    strcat_s(&Src, 0x104ui64, off_1437C6418);
    sub_140024120();
    v10 = qword_145F14528;
    v11 = *(_DWORD *)(v0 + 2496);
    v12 = (char *)(qword_145F14528 + 8);
    *(_DWORD *)(v0 + 2496) = 99;
    if (&Src != v12)
        strcpy_s(v12, 0x104ui64, &Src);
    if ((*(unsigned __int8(__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 40i64))(v10, 0i64))
    {
        (*(void(__fastcall **)(__int64))(*(_QWORD *)v10 + 72i64))(v10);
        (*(void(__fastcall **)(__int64))(*(_QWORD *)v10 + 48i64))(v10);
    }
    *(_DWORD *)(v0 + 2496) = v11;
    strcpy_s(&Src, 0x104ui64, byte_145F14640);
    strcat_s(&Src, 0x104ui64, off_1437C6410);
    sub_14010A090();
    v13 = qword_145B94E58;
    v14 = *(_DWORD *)(v0 + 2496);
    v15 = (char *)(qword_145B94E58 + 8);
    *(_DWORD *)(v0 + 2496) = 99;
    if (&Src != v15)
        strcpy_s(v15, 0x104ui64, &Src);
    if ((*(unsigned __int8(__fastcall **)(__int64, _QWORD))(*(_QWORD *)v13 + 40i64))(v13, 0i64))
    {
        (*(void(__fastcall **)(__int64))(*(_QWORD *)v13 + 72i64))(v13);
        (*(void(__fastcall **)(__int64))(*(_QWORD *)v13 + 48i64))(v13);
    }
    *(_DWORD *)(v0 + 2496) = v14;
    strcpy_s(&Src, 0x104ui64, byte_145F14640);
    strcat_s(&Src, 0x104ui64, off_1437C6420);
    sub_14010A090();
    v16 = qword_145B94E58;
    v17 = *(_DWORD *)(v0 + 2496);
    v18 = (char *)(qword_145B94E58 + 8);
    *(_DWORD *)(v0 + 2496) = 99;
    if (&Src != v18)
        strcpy_s(v18, 0x104ui64, &Src);
    if ((*(unsigned __int8(__fastcall **)(__int64, _QWORD))(*(_QWORD *)v16 + 40i64))(v16, 0i64))
    {
        (*(void(__fastcall **)(__int64))(*(_QWORD *)v16 + 72i64))(v16);
        (*(void(__fastcall **)(__int64))(*(_QWORD *)v16 + 48i64))(v16);
    }
    *(_DWORD *)(v0 + 2496) = v17;
    if ((unsigned __int8)sub_140046D60())
    {
        sub_140046D80(1i64);
        sub_140046D90(1i64);
    }
    sub_140D41B90();
    sub_1414812D0();
    v19 = sub_142951A10();
    (*(void(__fastcall **)(__int64, _QWORD))(*(_QWORD *)v19 + 16i64))(v19, (unsigned __int8)byte_1437C64B0);
    sub_141B7CFE0((unsigned __int8)byte_1437C6E58);
    v20 = dword_1437C6588;
    sub_1401375A0();
    sub_141C81670();
    sub_14066C490();
    if (!qword_145909900)
        qword_145909900 = sub_140678460(&unk_145ADE3B0);
    qword_146758F80 = (__int64)sub_140D56130;
    sub_140D4D200();
    v21 = qword_145909B50 == 0;
    v22 = *(_DWORD *)(v0 + 2496);
    *(_DWORD *)(v0 + 2496) = 50;
    if (v21)
        qword_145909B50 = sub_140630AB0(&unk_145AE1980);
    v21 = qword_145A10618 == 0;
    *(_DWORD *)(v0 + 2496) = v22;
    if (v21)
        qword_145A10618 = sub_140D45020(&unk_145AEC920);
    sub_1400FDFC0();
    sub_14061AC50();
    sub_1401D6AF0();
    sub_1407CBC10();
    if (!qword_145907F18)
        qword_145907F18 = sub_140F02D50(&unk_145AECC40);
    v23 = qword_145ADD760;
    if (!qword_145ADD760)
    {
        v23 = sub_140E20E20(&unk_145AEC980);
        qword_145ADD760 = v23;
    }
    *(_QWORD *)(v23 + 16) = sub_140D7F400;
    if (!qword_145A10610)
        qword_145A10610 = sub_140F8CAF0(&unk_145AEC9A0);
    sub_140D0CAA0();
    if (!qword_145909808)
        qword_145909808 = sub_140D13890(&unk_145AF52D0);
    sub_1406B2D90();
    sub_140570460();
    if (!qword_145907BB0)
        qword_145907BB0 = sub_140CA2440(&unk_145AF5070);
    if (!qword_14591BA80)
        qword_14591BA80 = sub_140FDFA20(&unk_145AECB60);
    sub_1401E8040();
    v21 = qword_14590DA00 == 0;
    v24 = *(_DWORD *)(v0 + 2496);
    *(_DWORD *)(v0 + 2496) = 95;
    if (v21)
        qword_14590DA00 = sub_140D45160(&unk_145AE18B0);
    v21 = qword_14590C370 == 0;
    *(_DWORD *)(v0 + 2496) = 106;
    if (v21)
        qword_14590C370 = sub_140FC8E80(&unk_145AEC1C0);
    v21 = qword_145AA3DC0 == 0;
    *(_DWORD *)(v0 + 2496) = v24;
    if (v21)
        qword_145AA3DC0 = sub_140D4C120();
    if (!qword_145AA4DE0)
    {
        qword_145AA4DE0 = (__int64)&unk_145AECB40;
        sub_141B10EB0((__int64)&unk_145AECB48);
        unknown_libname_4406(&unk_145AECB58);
        qword_145AA4DE0 = (__int64)&unk_145AECB40;
    }
    if (!qword_145AA3BB0)
        qword_145AA3BB0 = sub_140C775D0(&unk_145AF6920);
    sub_1406370D0();
    qword_145B46198 = (__int64)sub_1427F6EF0;
    sub_141CE0390();
    qword_145BA03C0 = (__int64)sub_141B67180;
    *(_QWORD *)(sub_1414812D0() + 152) = sub_140D3FC40;
    sub_1414812D0();
    *(_QWORD *)(sub_1429510E0() + 8) = sub_140D3FFA0;
    sub_1414812D0();
    *(_QWORD *)(sub_142952160() + 16) = sub_140D40050;
    v25 = *(_DWORD *)(v0 + 2496);
    v26 = (unsigned __int8)byte_1437C68A0;
    *(_DWORD *)(v0 + 2496) = 9;
    sub_141B47EE0(v26);
    if (dword_143905E80 != 2)
        sub_141B0F330(&unk_143905A00, &dword_143905E80);
    v27 = sub_141B0EEB0(&unk_143905A00, 24i64, 0i64);
    if (v27)
        sub_141B4EB70(v27, off_1437C7158[0], (unsigned int)dword_1437C6E70, 0i64);
    v28 = qword_145C21060;
    *(_DWORD *)(v0 + 2496) = v25;
    if (v28)
        sub_141B4F6B0(v28, "DATA");
    sub_140D421F0(&v58);
    sub_141CAECD0();
    v29 = *(_DWORD *)(v0 + 2496);
    *(_DWORD *)(v0 + 2496) = 9;
    sub_140D69890();
    if (!byte_1437C6660)
        sub_140D69870();
    sub_140D0CAE0();
    sub_140D0CB60(off_1437C6678);
    sub_140D0CB60(off_1437C6690);
    *(_DWORD *)(v0 + 2496) = v29;
    sub_141B7DA10("MESHES\\DEBRIS\\", "data\\", 0i64);
    v30 = *(_DWORD *)(v0 + 2496);
    *(_DWORD *)(v0 + 2496) = 9;
    sub_140D3EE40();
    *(_DWORD *)(v0 + 2496) = v30;
    nullsub_259();
    sub_141B25D20();
    if (byte_1437D2660 && byte_14387E340)
        LOBYTE(v31) = 1;
    else
        v31 = 0i64;
    sub_141B26370(v31);
    v21 = qword_145909800 == 0;
    v32 = *(_DWORD *)(v0 + 2496);
    *(_DWORD *)(v0 + 2496) = 86;
    if (v21)
        qword_145909800 = sub_141B203F0(&unk_145AFF240, (unsigned __int8)byte_1437C7140);
    if (!qword_145A13260)
        qword_145A13260 = sub_141B27710((unsigned __int64)&unk_145ADD7D0);
    v21 = dword_143905E80 == 2;
    *(_DWORD *)(v0 + 2496) = 85;
    if (!v21)
        sub_141B0F330(&unk_143905A00, &dword_143905E80);
    v33 = sub_141B0EEB0(&unk_143905A00, 616i64, 0i64);
    if (v33)
        qword_145ADD2C8 = sub_140D35AF0(v33, v58, qword_145ADD2E0);
    else
        qword_145ADD2C8 = 0i64;
    *(_DWORD *)(v0 + 2496) = v32;
    sub_141B50600(sub_140633470);
    sub_141B50610(sub_140D423B0);
    sub_141B50570(0i64, 0i64, v20);
    sub_141CE5EE0();
    sub_1428C1260();
    sub_141CCD940();
    sub_141CF6070(sub_140D42400, sub_140D42460);
    LODWORD(v57) = 0;
    v34 = sub_140D52170();
    sub_140D50E20(v34, &v57);
    v35 = *(_DWORD *)(qword_145ADD2C8 + 64);
    *(_DWORD *)(sub_1414812D0() + 176) = v35;
    sub_1414812D0();
    if (dword_1437C69C0)
    {
        if (dword_143905E80 != 2)
            sub_141B0F330(&unk_143905A00, &dword_143905E80);
        v36 = sub_141B0EEB0(&unk_143905A00, 8i64, 0i64);
        if (v36)
            v37 = sub_14012D640(v36, (unsigned int)dword_1437C69C0);
        else
            v37 = 0i64;
        *(_QWORD *)(qword_145ADD2C8 + 456) = v37;
    }
    sub_141D0B270(&byte_146219900);
    dword_146759044 = dword_1437520B8;
    qword_146759100 = (__int64)sub_140D40720;
    qword_1467590A0 = 0i64;
    byte_146759130 = byte_1437C6BB8;
    byte_146759131 = byte_1437C6C00;
    qword_1467590A8 = (__int64)sub_140D407F0;
    SetUnhandledExceptionFilter(TopLevelExceptionFilter);
    sub_140D37C90(qword_145ADD2C8);
    sub_140D3CCF0();
    v21 = qword_145AA4DF0 == 0;
    v38 = *(_DWORD *)(v0 + 2496);
    *(_DWORD *)(v0 + 2496) = 86;
    if (v21)
        qword_145AA4DF0 = sub_141B62D40(&unk_145AFF220, 2i64);
    *(_DWORD *)(v0 + 2496) = v38;
    sub_140CBC130();
    sub_142893530();
    sub_142893500((unsigned __int8)byte_1437C6F48);
    sub_1428855F0();
    sub_142885520((unsigned __int8)byte_1437C6F60);
    LOBYTE(v39) = 1;
    sub_140D3C480(qword_145ADD2C8, v39);
    LOBYTE(v40) = 1;
    sub_1400FB170(qword_145ADD2D0, 0i64, 0i64, v40);
    sub_140B04B50();
    sub_141D0B290(&byte_146219900);
    v41 = *(_DWORD *)(v0 + 2496);
    *(_DWORD *)(v0 + 2496) = 70;
    sub_140D1D1F0();
    *(_DWORD *)(v0 + 2496) = v41;
    sub_140CEC840();
    v42 = 1;
    if (off_1437C68B8 && *off_1437C68B8
        || off_1437C68D0 && *off_1437C68D0 && off_1437C68E8 && *off_1437C68E8 && off_1437C6900 && *off_1437C6900)
    {
        if ((sub_140D3EED0(),
            sub_141CA38F0(qword_146038088, 5i64),
            LODWORD(v57) = 2,
            v43 = sub_140D52170(),
            sub_140D50E20(v43, &v57),
            off_1437C68B8)
            && *off_1437C68B8
            || off_1437C68D0 && *off_1437C68D0 && off_1437C68E8 && *off_1437C68E8 && off_1437C6900 && *off_1437C6900)
        {
            if (!*(_BYTE *)(qword_145ADD3D8 + 2368))
            {
                v57 = 0i64;
                v42 = sub_140D3F4A0(&v57);
                if (!v42)
                    sub_140D3F7E0(v57);
            }
        }
    }
    sub_142571D30();
    if (byte_1437C6510)
    {
        sub_141B66F90();
        if (byte_1437C6510)
        {
            if (!qword_145ADD740)
                sub_141B09CB0();
            if (!qword_145A98E60)
                sub_1409FCFA0();
        }
    }
    *(_BYTE *)(qword_145ADD2C8 + 40) = 1;
    v44 = byte_1437C64C8;
    v45 = sub_1429520B0();
    LOBYTE(v55) = 0;
    LOBYTE(v54) = 0;
    LODWORD(v53) = 0;
    LODWORD(v52) = 0;
    (*(void(__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, __int64, __int64))(*(_QWORD *)v45 + 16i64))(
        v45,
        v44,
        0i64,
        0i64,
        v52,
        v53,
        v54,
        v55);
    v46 = sub_1429520B0();
    v47 = (*(__int64(__fastcall **)(__int64))(*(_QWORD *)v46 + 40i64))(v46);
    v48 = qword_1465CCBE8;
    *(_BYTE *)(qword_1465CCBE8 + 81) = v47;
    v49 = v47;
    if (!byte_145ADD2AD && v47)
        sub_140D53230();
    if (v42)
    {
        if (v49)
        {
            LOBYTE(v48) = 1;
            sub_1412A1B90(v48);
        }
        else
        {
            sub_140BC5E90();
        }
        sub_1400FB350((char)qword_145ADD2D0);
    }
    sub_142485550(qword_1465CCBE8);
    sub_140267C50(v50);
    v51 = -1i64;
    do
        ++v51;
    while (*(_BYTE *)(off_1437C6918 + v51));
    if (v51)
        sub_14125B380(off_1437C6918);
    result = 1;
    */

    return true;
}
//HOOK_FUNCTION(0x140D35F80, InitializeGame);

// 0x140D39B50
int64_t __fastcall ComputeTimeDelta(GameContext_t *ctx)
{
    TimeData_t& td = gTimeData2.get();

    td.bChangeTimeMultSlowly = bChangeTimeMultSlowly.get();
    if (!ctx->field_1D0)
        SetTimeScale();

    LARGE_INTEGER currentCounter = GetCurrentCounter();

    // Not sure why but they seem to do it.
    uint32_t elapsedTime = (uint32_t)(1000 * (currentCounter.QuadPart - td.counterStart) / gFrequency.get());

    int64_t result = sub_141B137B0(&td, elapsedTime);
    flt_143889EF8 = fHavokTauRatio;

    float delta;
    if (ctx->field_1D0)
    {
        result = TtbhkWorld_SetDeltaTime(td.scaledDeltaTime);
        if(!ctx->field_1D0)
            delta = td.scaledDeltaTime;
        else
            delta = 0.0f;
    }
    else
    {
        delta = td.scaledDeltaTime;
    }

    gScaledDeltaTime = delta;

    if (byte_145ADD2AC.get())
        result = sub_141371EB0(qword_14590C388.get());

    return result;
}
HOOK_FUNCTION(0x140D39B50, ComputeTimeDelta);

int64_t __fastcall GameUpdate(GameContext_t *a1)
{
    char v3; // si
    int64_t result; // ax
    __int64 v8; // rbx
    void* v10; // rbx
    uint64_t *v11; // rax
    void* v12; // rbx
    uint64_t *v13; // rax
    void* v14; // rbx
    uint64_t *v15; // rax
    void* v16; // rbx
    uint64_t *v17; // rax
    void* v18; // rbx
    uint64_t *v19; // rax
    void* v20; // rbx
    uint64_t *v21; // rax
    __int64 v22; // rcx
    uint8_t* v26; // rbx
    uint64_t *v27; // rax
    char v28; // rdx
    float v30; // rax
    uint32_t *v36; // rcx
    char v40; // bl
    void* v42; // rax
    uint8_t* v51; // rbx
    uint64_t *v53; // rax
    __int64 v59; // rcx
    __int64 v60; // rdi
    int v61; // ebx
    char v62; // [rsp+20h] [rbp-28h]
    float delta = 0.0f;

    GameContext_t *context = a1;

    bool v2 = *(uint32_t*)(qword_145909918.get() + 480) != 0;
    a1->field_1D0 = v2;

    if (v2 || a1->field_2A)
    {
        v3 = 0;
        if (v2)
            ComputeTimeDelta(context);
    }
    else
    {
        v3 = 1;
    }

    delta = gTimeData2.get().scaledDeltaTime;
    if ((!context->field_1D0 || context->field_1D1) && !context->field_2A)
    {
        BeginFrame(delta);
    }

    //nullsub_980(qword_145ADD758, qword_145ADD228);
    sub_141B62EA0(qword_145AA4DF0.get());               // ResetEvent in there
    if (GetAsyncKeyState(9) >= 0 || (result = GetAsyncKeyState(18), !(result & 0x8000)))
    {
        if (!context->field_1D0 || (sub_140D3BE30(), !context->field_1D0))
        {
            if (context->field_2A && sub_14124E6D0(qword_145907BA8.get(), 3u))
                sub_140D39D20(context);
        }
        if (byte_145ADD2AD.get())
        {
            if (ProcessMessages())
            {
                sub_140CBCEC0();
                sub_1427D4670(qword_145909B28.get(), 1);
                sub_1427D3FF0(qword_145909B28.get());
            }
            else if (!(unsigned __int8)sub_140DB4E60(qword_145ADD3D8.get()))
            {
                if (byte_145ADD550.get())
                {
                    if (byte_145ADD2B7.get())
                    {
                        byte_145B14E0F = 1;
                        sub_1400FB170(qword_145ADD2D0.get(), nullptr, 1, 1);
                        sub_141CA38F0(qword_146038088.get(), 4);
                        v62 = 1;
                        sub_1400FB350(qword_145ADD2D0.get(), nullptr, 0, -1.0f, 1);
                        byte_145ADD550 = 0;
                        byte_145ADD2FC = 0;
                    }
                }
                else
                {
                    v8 = *(uint64_t*)(qword_145ADD3D8.get() + 184);
                    if (v8 && v8 != qword_145ADD548.get() && !(*(uint8_t*)(v8 + 64) & 1))
                    {
                        if (!sub_1403B3700(*(uint64_t *)(qword_145ADD3D8.get() + 184))
                            || !(unsigned __int8)sub_14282EE50() 
                            && !sub_1427D4B90(qword_145909B28.get(), *(uint32_t*)(v8 + 20)))
                        {
                            byte_145ADD550 = 1;
                            byte_145ADD2FC = 1;
                        }
                        qword_145ADD548 = v8;
                    }
                }
            }
            sub_14018C340(qword_145909908.get());
            sub_140CF13A0(qword_145AAC618.get());
            sub_140D3C800();
            sub_140EA6470(qword_145ADD3D8.get());
        }

        if (!byte_1437C6660.get())
            goto LABEL_48;

        if (context->field_1D0)
        {
            v10 = qword_145909918.get();
            v11 = (uint64_t *)sub_14204B8B0(); // MapMenu
            if ((unsigned __int8)sub_142042040(v10, v11))
                goto LABEL_48;

            v12 = qword_145909918.get();
            v13 = (uint64_t *)sub_14204B6D0(); // LockpickingMenu
            if ((unsigned __int8)sub_142042040(v12, v13))
                goto LABEL_48;

            v14 = qword_145909918.get();
            v15 = (uint64_t *)sub_14204BFD0(); // RaceSexMenu
            if ((unsigned __int8)sub_142042040(v14, v15))
                goto LABEL_48;

            v16 = qword_145909918.get();
            v17 = (uint64_t *)sub_14204C330(); // StatsMenu
            if ((unsigned __int8)sub_142042040(v16, v17))
                goto LABEL_48;

            v18 = qword_145909918.get();
            v19 = (uint64_t *)sub_14204B850(); // MainMenu
            if ((unsigned __int8)sub_142042040(v18, v19))
                goto LABEL_48;

            v20 = qword_145909918.get();
            v21 = (uint64_t *)sub_14204B5B0(); // LoadingMenu
            if ((unsigned __int8)sub_142042040(v20, v21))
                goto LABEL_48;
        }
        v22 = *(unsigned int *)(qword_146038088.get() + 5168);
        if (!(uint32_t)v22)
        {
            if (context->field_1D0)
            {
                sub_140D0CCD0();
LABEL_48:
                if (v3)
                    dword_146759304.get() ^= 1u;

                if (!context->field_1D0 && !context->field_2A)
                {
                    // NOTE: This is a function call.
                    (*(void(__cdecl **)(void*))(*(uint64_t *)qword_145ADD3A8.get() + 552i64))(qword_145ADD3A8.get());

                    sub_140D1D730(qword_145909B40.get());
                    sub_140D19F30(qword_145A13170.get(), gTimeData2.get().deltaTime);
                }

                if (v3)
                {
                    flt_145B00A5C = gDeltaAccumulator;
                    delta = gDeltaAccumulator.get() + gTimeData2.get().scaledDeltaTime;
                    gDeltaAccumulator = delta;
                    sub_140CBCE50();
                }

                if (byte_145ADD2AC.get())
                {
                    if (!sub_1427D3280(qword_145909B28.get()))
                        sub_140D3C000();
                    v26 = qword_145909918.get();
                    v27 = (uint64_t *)sub_14204B8B0(); // MapMenu
                    if (!(unsigned __int8)sub_142042040(v26, v27))
                    {
                        if (context->field_1D0 || context->field_2A)
                            v28 = 0;
                        else
                            v28 = 1;
                        sub_140D3A210(context, v28);
                    }
                }
                ++dword_1437C63A8;
                dword_145AFF724 = 0;
                if (!context->field_1D0)
                    ++dword_1438FDF5C;
                sub_1403DE8C0(context->field_1D0);
                if (!v3)
                {
                    if (byte_145ADD2AC.get())
                    {
                        void *p = sub_14038AC50();
                        sub_1407ED4F0(p);
                        GsDriverEntry(qword_1459097F8.get(), nullptr);
                        sub_141372030(qword_14590C388.get());
                        sub_141372290(qword_14590C388.get());
                        sub_141084620(qword_145A12E18.get(), 1);
                        sub_140E146C0(qword_145ADD3D8.get(), delta, 0.0f);
                        sub_140D396C0();
                    }
                    sub_141B2BD10(qword_145A986B8.get());
                    sub_14125BE70();
                    sub_140A51050();
                    sub_141B2D1E0(qword_145A98AB0.get(), qword_145A13268.get());
                    sub_141B2D1E0(qword_145A98AB0.get(), qword_145A92288.get());
                    sub_140A510E0(qword_145A9BF90.get());
                }
                if (byte_145ADD2AC.get())
                    sub_140D39A10();
                if (!context->field_1D0 && !context->field_2A)
                    sub_1401E4B30();

                // Not calling this crashes.
                sub_140F0DC60(qword_145907F18.get(), gTimeData2.get().scaledDeltaTime);
                if (context->field_1D0)
                {
                    sub_140D24360();
                    sub_141BA5830();
                }

                /*
                if (gHitchedShaderCompilation)
                {
                    gHitchedShaderCompilation = 0;
                    sub_140AE1D70((unsigned __int64)"Hitched from shader compile", 0);
                }
                */

                if (!context->field_1D0 && !context->field_2A && !sub_140D413D0())
                {
                    sub_1400F57C0(qword_145ADD2D0.get(), qword_145ADD3D8.get() + 208, 1, nullptr);
                }

                sub_141B63050(0);
                sub_141B63050(1);

                if (qword_14590D6E0.get())
                    sub_1401819F0(qword_14590D6E0.get());

                sub_141B63050(2);
                v36 = *(uint32_t **)(qword_145ADD3A8.get() + 320);
                v36[97] = dword_1438FE1E8.get();
                v36[98] = dword_1438FE1EC.get();
                v36[99] = dword_1438FE1F0.get();
                v36[100] = dword_1438FE1F4.get();
                if (byte_145ADD2AC.get())
                {
                    __m128 res = sub_14124D0C0(qword_145907BA8.get());
                    if (*(uint32_t *)(qword_14591BA80.get() + 64) != 1)
                    {
                        // rcx, xmm1, r8b, r9
                        sub_1428451A0(qword_145ADD3A8.get(), res.m128_f32[0], 0, nullptr);
                        sub_1427FC090(res.m128_f32[0]);
                    }
                }
                if (sub_140CBCD50(1))
                {
                    if (sub_1401EF270())
                        sub_141B630F0(0, 3);
                    sub_141B630F0(0, 0);
                }
                sub_140D39940();
                if (qword_145908100.get())
                    sub_142572910(qword_145AA0A40.get());

                float xmm0 = flt_1437C6528.get();
                v30 = flt_1437C6DC8.get();
                if(v30 <= xmm0)
                    v30 = xmm0;
                    
                sub_140D3A8A0(context, v30);
                sub_140D385E0(context);
                v40 = sub_140CBCD50(0);
                sub_140CBCE80();
                if (dword_143905E80.get() != 2)
                    sub_141B0F330(&unk_143905A00.get(), &dword_143905E80.get());
                v42 = sub_141B0E350(&unk_143905A00.get());
                sub_141B14600(v42);
                if (!v40)
                {
                    sub_141B2D1E0(qword_145A98AB0.get(), qword_145909B58.get());
                    sub_141B2D1E0(qword_145A98AB0.get(), qword_145AA0260.get());
                    sub_141B2D1E0(qword_145A98AB0.get(), qword_145909918.get());
                    sub_140C20300(qword_145A12E20.get());
                    sub_1409FD050();
                    sub_142042310(qword_145909918.get());
                    sub_142043410(qword_145909918.get());
                }
                if (qword_145A98E60.get())
                {
                    sub_1409FD260(qword_145A98E60.get());
                    *(uint32_t *)(qword_145A98E60.get() + 428) = 0;
                }
                if (gGameContext->field_2B)
                {
                    gGameContext->field_2B = 0;
                    gGameContext->field_2A = 1;
                }
                sub_14125B660();

                EndFrame(context);
                if ((!context->field_1D0 || context->field_1D1) && !context->field_2A)
                    sub_140268090(xmm0);

                if (!v3)
                {
                    if (!context->field_1D0 && !context->field_2A)
                    {
                        float scaledDelta = gTimeData2.get().scaledDeltaTime;
                        sub_1409C02F0(scaledDelta);
                        sub_140E61300(scaledDelta);
                        sub_1409C4510(scaledDelta);
                    }
                    sub_142486E10();
                    sub_140C8C450();

                    float p1 = 0.0f;
                    if (qword_145ADD3D8.get() && sub_140E00AA0(qword_145ADD3D8.get()))
                        p1 = (float)(unsigned int)flt_1437C65E8.get();

                    sub_140832290(p1);
                    if (byte_145ADD2AC.get())
                    {
                        sub_140D398A0(context, nullptr);
                        sub_1413723D0(qword_14590C388.get());
                    }
                    sub_1404E4C20();
                    sub_140D57E80(qword_145AFF540.get(), p1, 8);
                    v51 = qword_145909918.get();
                    v53 = (uint64_t *)sub_14204BFD0();
                    if ((unsigned __int8)sub_142042040(v51, v53))
                    {
                        void *v54 = (*(void*(__cdecl **)(void*))(*(uint64_t *)qword_145ADD3D8.get() + 1032i64))(qword_145ADD3D8.get());
                        sub_140685940(v54, 1);
                    }
                }
                if (dword_143905E80.get() != 2)
                    sub_141B0F330(&unk_143905A00.get(), &dword_143905E80.get());
                void *v56 = sub_141B0E350(&unk_143905A00.get());
                sub_141B14610(v56);
                sub_1404E5070();
                sub_1404E1510();
                if (!context->field_2A)
                {
                    v59 = (unsigned int)TlsIndex.get();
                    v60 = *(uint64_t *)(__readgsqword(0x58u) + 8i64 * (unsigned int)TlsIndex.get());
                    v61 = *(uint32_t *)(v60 + 2496);
                    *(uint32_t *)(v60 + 2496) = 7;
                    //nullsub_807(v59);
                    *(uint32_t *)(v60 + 2496) = v61;
                }
                return sub_1428C3690(qword_14676A740.get());
            }
            if (*((uint64_t *)qword_145ADD2D0.get() + 11))
            {
                uint8_t *v23 = qword_145909918.get();
                uint64_t *v24 = (uint64_t *)sub_14204AE30((void*)v22);
                if (!(unsigned __int8)sub_142042040(v23, v24))
                {
                    sub_140D0CCD0();
                    goto LABEL_48;
                }
            }
        }
        sub_140D0CCA0();
        goto LABEL_48;
    }
    return result;
}

void MainGameLoop()
{
    bool flipVar = false;
    while (true)
    {
        sub_14294BD50(0);
        sub_140D38A20(gGameContext.get());

        if (GetActiveWindow() == gGameContext->hwnd
            || qword_145ADD2D0.get() 
            && (*((bool *)qword_145ADD2D0.get() + 197) 
            || *((bool*)qword_145ADD2D0.get() + 198))
            || qword_145ADD3E8.get()
            || byte_1437C6618.get())
        {
            if (flipVar)
            {
                flipVar = false;
                sub_140C8EC50(false, 0);
                sub_1409E5F70(qword_145A92288.get());
            }
            GameUpdate(gGameContext.get());
        }
        else
        {
            if (!flipVar)
            {
                flipVar = true;
                sub_140C8EC50(true, 0);
                void* v2 = sub_14287C6D0();
                sub_142853DF0(v2);
            }
            Sleep(0x32u);
        }

        if(gGameContext->exitGame)
            break;

        if (gGameContext->unknownField)
        {
            if (byte_145ADD2AD.get())
                sub_140D3B6E0(gGameContext.get());
        }

        sub_14294BDB0(0);
    }
}
HOOK_FUNCTION(0x140D36C30, MainGameLoop);