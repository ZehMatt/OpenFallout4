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

    template<uintptr_t _O>
    var& operator+=(var<T, _O>& v)
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

    template<uintptr_t _O>
    var& operator=(var<T, _O>& v)
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

    template<uintptr_t _O>
    bool operator==(var<T, _O>& v) const
    {
        return get() == v.get();
    }

    template<uintptr_t _O>
    bool operator!=(var<T, _O>& v) const
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

    var operator++()
    {
        T& v = get();
        ++v;
        return *this;
    }

    var operator--()
    {
        T& v = get();
        --v;
        return *this;
    }

    var operator++(int)
    {
        var tmp = *this;
        T& v = get();
        v++;
        return tmp;
    }

    var operator--(int)
    {
        var tmp = *this;
        T& v = get();
        v--;
        return tmp;
    }
};

}