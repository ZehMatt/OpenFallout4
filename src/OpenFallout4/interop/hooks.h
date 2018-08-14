#pragma once

#include <stdint.h>

namespace interop {

bool hook(void *src, void *target);
bool hookTranslated(uintptr_t src, void *target);
bool hookPending();

class StaticHookHelperInstance
{
public:
    StaticHookHelperInstance(uintptr_t src, void *target)
    {
        hookTranslated(src, target);
    }
};

#define HOOK_FUNCTION(src, target); \
    __declspec(dllexport) interop::StaticHookHelperInstance _hook_##src##_(src, target);

}