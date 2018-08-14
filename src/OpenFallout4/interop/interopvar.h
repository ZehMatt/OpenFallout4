#pragma once

#include "interop.h"

namespace interop {

template<typename T, uintptr_t _Addr>
class var
{
#ifdef _DEBUG 
private:
    T* _data;
#endif
public:
    T& get() const
    {
        T& res = interop::reference_at<T>(_Addr);
#if _DEBUG
        const_cast<var*>(this)->_data = &res;
#endif
        return res;
    }

    var& operator+=(T v)
    {
        T& p = get();
        p += v;
        return *this;
    }

    var& operator+=(var& v)
    {
        T& p = get();
        p += v.get();
        return *this;
    }

    var& operator=(T v)
    {
        T& p = get();
        p = v;
        return *this;
    }

    var& operator=(var& v)
    {
        T& p = get();
        p = v.get();
        return *this;
    }

    bool operator<(T v) const
    {
        return get() < v;
    }

    bool operator>(T v) const
    {
        return get() > v;
    }

    bool operator==(T v) const
    {
        return get() == v;
    }

    bool operator!=(T v) const
    {
        return get() != v;
    }

    bool operator==(var& v) const
    {
        return get() == v.get();
    }

    bool operator!=(var& v) const
    {
        return get() != v.get();
    }

    bool operator!() const
    {
        return !get();
    }

    auto operator->() const
    {
        return get();
    }
};

}