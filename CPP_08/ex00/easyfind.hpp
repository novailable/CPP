#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	item = std::find(container.begin(), container.end(), value);
	if (item == container.end())
		throw	std::out_of_range("easyfind: value not found!");
	return (item);
}

template <typename T>
typename T::const_iterator	easyfind(const T &container, int value)
{
	typename T::const_iterator	item = std::find(container.begin(), container.end(), value);
	if (item == container.end())
		throw	std::out_of_range("easyfind: value not found!");
	return (item);
}

#endif