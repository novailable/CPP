#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <algorithm>
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <iterator>

class	RPN
{
	private:
		 std::stack<int>	_numbers;
	public:
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();

		int	operation(const std::string &seq);
};

#endif