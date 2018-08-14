#pragma once

#include "interop.h"
#include <functional>

namespace interop {

template<typename decl, uintptr_t _Addr>
class func
{
public:
    template<class ...Args>
    auto operator()(Args ... args)
    {
        decl* f = (decl*)translateAddr(_Addr);
        return f(std::forward<Args>(args)...);
    }
};

}