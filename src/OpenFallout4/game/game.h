#pragma once 

#pragma pack(push, 1)
struct TimeData_t
{
    uint64_t counterStart;
    float maxFrameRateMs;
    float field_C;
    float scaledDeltaTime;
    float unscaledDeltaTime;
    uint64_t deltaTime;
    uint64_t timestampStartMs;
    uint64_t field_28;
    uint64_t field_30;
    uint32_t counter;
    uint32_t bChangeTimeMultSlowly; 
    uint32_t field_40;
    uint32_t field_44;
    uint32_t field_48;
};
static_assert(sizeof(TimeData_t) == 0x4C);

struct struc_3
{
    uint64_t field_0;
    uint64_t field_8;
    uint64_t field_10;
    uint64_t  field_18;
    uint64_t field_20;
    uint64_t field_28;
};
static_assert(sizeof(struc_3) == 0x30);

struct struc_2
{
    uint64_t field_0;
    uint64_t field_8;
    uint64_t field_10;
    uint64_t  field_18;
    uint64_t field_20;
    uint64_t field_28;
};
static_assert(sizeof(struc_2) == 0x30);

struct GameContext_t // 0x268 from malloc.
{
    char field_0[36];
    bool exitGame;
    bool unknownField;
    uint8_t field_26;
    uint8_t field_27;
    uint8_t field_28;
    uint8_t field_29;
    uint8_t field_2A;
    uint8_t field_2B;
    uint8_t field_2C;
    uint8_t field_2D;
    uint8_t field_2E;
    uint8_t field_2F;
    void* hwnd;
    void* hInstance;
    uint32_t threadId;
    uint32_t field_44;
    void* scrapHeap1;
    char field_50[136];
    struc_3 field_D8;
    void* scrapHeap2;
    char field_110[136];
    struc_2 field_198;
    uint64_t field_1C8;
    uint8_t field_1D0;
    uint8_t field_1D1;
    uint8_t field_1D2;
    uint8_t field_1D3;
    uint32_t field_1D4;
    uint64_t field_1D8;
    uint32_t field_1E0;
    uint32_t field_1E4;
    uint64_t field_1E8;
    uint64_t field_1F0;
    uint32_t field_1F8;
    uint32_t field_1FC;
    uint64_t field_200;
    uint64_t field_208;
    uint64_t field_210;
    uint64_t field_218;
    uint64_t field_220;
    uint32_t field_228;
    uint32_t field_22C;
    uint64_t field_230;
    uint64_t field_238;
    uint32_t field_240;
    uint32_t field_244;
    uint64_t field_248;
    uint64_t field_250;
    uint32_t field_258;
    uint32_t field_25C;
    uint64_t field_260;
};

static_assert(offsetof(GameContext_t, exitGame) == 0x24);
static_assert(offsetof(GameContext_t, unknownField) == 0x25);
static_assert(offsetof(GameContext_t, hwnd) == 0x30);
static_assert(sizeof(GameContext_t) == 616);

#pragma pack(pop)