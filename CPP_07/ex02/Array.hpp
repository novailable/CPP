#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>
#include <sstream>

template <typename T>
class	Array
{
	private:
		T	*_items;
		std::size_t	_size;
	public:
		Array() : _items(NULL), _size(0) {}
		Array(unsigned int n) : _items(new T[n]()), _size(n) {}
		Array(const Array &other) : _items(NULL), _size(0) {*this = other;}
		Array	&operator=(const Array &other)
		{
			if (this == &other)
				return (*this);
			delete[] _items;
			_size = other._size;
			_items = new T[_size]();
			for (std::size_t i = 0; i < _size; ++i)
				_items[i] = other._items[i];
			return (*this);
		}
		~Array() {delete[] _items;}
		T	&operator[](std::size_t index)
		{
			if (index >= _size)
				throw	std::out_of_range("index out of range!");
			return (_items[index]);
		}

		const T	&operator[](std::size_t index) const
		{
			if (index >= _size)
				throw	std::out_of_range("index out of range!");
			return (_items[index]);
		}
		std::size_t	size() {return (_size);}
		std::string	string() const
		{
			std::ostringstream oss;
			for (std::size_t i = 0; i < _size; ++i)
				oss << _items[i] << " ";
			oss << ", size: " << _size;
			return oss.str();
		}
};

#endif
