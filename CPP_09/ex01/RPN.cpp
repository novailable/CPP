#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		_numbers = other._numbers;
	return (*this);
}

RPN::~RPN() {}

int	RPN::operation(const std::string &seq)
{
	std::istringstream	iss(seq);
	std::string	token;
	while (iss >> token)
	{
		if (std::string("+-*/").find(token[0]) != std::string::npos)
		{
			if (_numbers.size() == 2)
				throw	std::out_of_range("invalid expression");
		}
	}

}