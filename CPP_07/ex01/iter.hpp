#ifndef	ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Func>
void	iter(T* items, size_t size, Func func)
{
    for (size_t i = 0; i < size; ++i)
		func(items[i]);
}

#endif