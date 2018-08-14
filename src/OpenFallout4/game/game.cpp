#include <windows.h>
#include <conio.h>

#include "../interop/interop.h"

// Data
static interop::var<uint32_t, 0x14370C8A0> iNumHWThreads;
static interop::var<char[0x210], 0x14370C8A0> gUserName;
static interop::var<uint64_t, 0x145A3A760> qword_145A3A760;
static interop::var<char[0x50], 0x145ADE2D0> unk_145ADE2D0;
static interop::var<void*, 0x145A3E830> qword_145A3E830;
static interop::var<char[0x08], 0x145ADE390> byte_145ADE390;
static interop::var<char[0x10], 0x145ADE398> byte_145ADE398;
static interop::var<char[0x08], 0x145ADE3A8> byte_145ADE3A8;
static interop::var<void*, 0x145907BA0> qword_145907BA0;

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

// Data
#pragma pack(push, 1)
struct GameContext_t // 0x268 from malloc.
{
    char unknown[36];
    bool exitBreak;
    bool var_0;
    char padding[10];
    HWND hwnd;
};
//template<size_t N> struct showme; showme<offsetof(GameContext_t, hwnd)> blub;
static_assert(offsetof(GameContext_t, exitBreak) == 0x24);
static_assert(offsetof(GameContext_t, var_0) == 0x25);
static_assert(offsetof(GameContext_t, hwnd) == 0x30);
#pragma pack(pop)

static interop::var<GameContext_t*, 0x145ADD2C8> gGameContextPtr;
static interop::var<void*, 0x145ADD2D0> qword_145ADD2D0;
static interop::var<void*, 0x145ADD3E8> qword_145ADD3E8;
static interop::var<void*, 0x145A92288> qword_145A92288;

static interop::var<char, 0x145ADD2AD> byte_145ADD2AD;
static interop::var<char, 0x1437C6618> byte_1437C6618;

// Functions
static interop::func<void(uint32_t), 0x14294BD50> sub_14294BD50;
static interop::func<void(void*), 0x140D38A20> sub_140D38A20;
static interop::func<int64_t(bool, uint32_t), 0x140C8EC50> sub_140C8EC50;
static interop::func<void(void*), 0x1409E5F70> sub_1409E5F70;
static interop::func<void(GameContext_t*), 0x140D38D40> sub_140D38D40;
static interop::func<void*(), 0x14287C6D0> sub_14287C6D0;
static interop::func<void(void*), 0x142853DF0> sub_142853DF0;
static interop::func<int64_t(GameContext_t*), 0x140D3B6E0> sub_140D3B6E0;
static interop::func<int64_t(int32_t), 0x14294BDB0> sub_14294BDB0;

void MainGameLoop()
{
    bool flipVar = false;
    while (true)
    {
        sub_14294BD50(0);
        sub_140D38A20(gGameContextPtr.get());

        if (GetActiveWindow() == gGameContextPtr->hwnd
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
            sub_140D38D40(gGameContextPtr.get());
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

        if(gGameContextPtr->exitBreak)
            break;

        if (gGameContextPtr->var_0)
        {
            if (byte_145ADD2AD.get())
                sub_140D3B6E0(gGameContextPtr.get());
        }

        sub_14294BDB0(0);
    }
}
HOOK_FUNCTION(0x140D36C30, MainGameLoop);