#ifndef __CALCULATOR__H__
#define __CALCULATOR__H__

#include <map>
#include <type_traits>

namespace call
{
    template <typename T>
    T sum(T a , T b)
    {
        return (a + b);
    }

    template <typename T>
    T mul(T a, T b)
    {
        return (a * b);
    }

    template <typename T>
    T sub(T a, T b)
    {
        return (a - b);
    }

    template <typename T>
    T dive(T a, T b)
    {
        return (a / b);
    }
};

#endif // __CALCULATOR__H__