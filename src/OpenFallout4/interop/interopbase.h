#pragma once

#include <stdint.h>
#include <stdio.h>
#include <windows.h>

namespace interop {

bool isInitialized();

void initialize();

// Returns the static address translated to the current runtime address.
uintptr_t translateAddr(uintptr_t addr);

template<typename T>
T& reference_at(uintptr_t addr)
{
    return *reinterpret_cast<T*>(addr);
}

template<typename T>
const T& const_reference_at(uintptr_t addr)
{
    return *reinterpret_cast<const T*>(addr);
}

}