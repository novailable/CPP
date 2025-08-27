#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <limits>
#include <vector>
#include <exception>
#include <iterator>
#include <iostream>

class	Span
{
	private:
		unsigned int	_max_size;
		std::vector<int>	_nums;

	public:
		Span();
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();

		Span(unsigned int N);

		template <typename Container>
		Span(unsigned int N, const Container &container) : _max_size(N)
		{
			Span::addNumber(container);
		}

		void	addNumber(int n);

		template <typename InputIterator>
		void	addNumber(InputIterator begin, InputIterator end)
		{
			typedef typename std::iterator_traits<InputIterator>::iterator_category Category;
			(void)sizeof(Category);

			typedef typename std::iterator_traits<InputIterator>::value_type value_type;
			typedef char check_type[(sizeof(value_type) == sizeof(int)) ? 1 : -1];
			(void)sizeof(check_type);

			_nums.insert(_nums.end(), begin, end);
			if (_nums.size() > _max_size)
			{
				_nums.resize(_max_size);
				throw	std::overflow_error("Span: full!");
			}
		}

		template <typename Container>
		void	addNumber(const Container &container)
		{
			Span::addNumber(container.begin(), container.end());
		}

		long long	shortestSpan() const;
		long long	longestSpan() const;

		unsigned int	get_cur_span_size() const;
		
		void	print() const;
};

template <typename T>
void	print_container(T container)
{
	std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

#endif
