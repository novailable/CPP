#include "Span.hpp"

Span::Span() : _max_size(0) {}

Span::Span(const Span &other) : _max_size(other._max_size), _nums(other._nums) {}

Span	&Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	_max_size = other._max_size;
	_nums = other._nums;
	return (*this);
}

Span::~Span() {};

Span::Span(unsigned int N) : _max_size(N) {};

void	Span::addNumber(int n)
{
	if (_nums.size() >= _max_size)
		throw	std::overflow_error("Span: maximum size reached!");
	_nums.push_back(n);
}

long long	Span::shortestSpan() const
{
	if (_nums.size() < 2)
		throw	std::underflow_error("Span: not enough numbers!");
	std::vector<int>	sorted(_nums);
	std::sort(sorted.begin(), sorted.end());
	long long min_span = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		long long diff = sorted[i + 1] - sorted[i];
		if (std::abs(diff) < std::abs(min_span))
			min_span = diff;
	}
    return (std::abs(min_span));
}

long long	Span::longestSpan() const
{
	if (_nums.size() < 2)
        throw	std::underflow_error("Span: not enough numbers!");

    long long min_val = *std::min_element(_nums.begin(), _nums.end());
    long long max_val = *std::max_element(_nums.begin(), _nums.end());
    return (std::abs(max_val - min_val));
}

void	Span::print() const
{
	print_container(_nums);
}
