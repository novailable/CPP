#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN	&RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

RPN::~RPN() {}

void	RPN::operation(const std::string &seq)
{
	std::stack<int>	_nums;
	std::istringstream	iss(seq);
	std::string	token;
	while (iss >> token)
	{
		if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
		{
			if (_nums.size() < 2)
				throw	std::out_of_range("invalid expression: '" + seq + "'");
			int y = _nums.top(); _nums.pop();
			int x = _nums.top(); _nums.pop();
			_nums.push(calc(x, y, token[0]));
		}
		else
		{
			if (token.size() != 1 || !std::isdigit(token[0]))
				throw std::invalid_argument("invalid token: '" + token + "'");
			_nums.push(token[0] - '0');
		}

	}
	if (_nums.size() != 1)
		throw	std::out_of_range(": invalid expression: '" + seq + "'");
	std::cout << _nums.top() << std::endl;
}

int	RPN::calc(int x, int y, char o)
{
	std::stringstream	err_msg;
	err_msg << x << " " << y << " " << o;
	
	switch (o)
	{
		case '+': return (x + y);
		case '-': return (x - y);
		case '*': return (x * y);
		case '/':
			if (y != 0)
				return (x / y);
			else
				throw	std::logic_error("divison by zero: " + err_msg.str());
		default:
			throw	std::invalid_argument("unknown operator: " + err_msg.str());
	}
}
