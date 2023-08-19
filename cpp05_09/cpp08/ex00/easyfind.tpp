#include "easyfind.hpp"

template<typename T>
typename T::iterator easyfind(T &a, int integer)
{
    typename T::iterator it = std::find(a.begin(), a.end(), integer);
    if (it != a.end())
        return (it);
    return a.end();
}
