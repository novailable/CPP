#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class	RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();

		static void	operation(const std::string &seq);
		static int	calc(int a, int b, char o);
};

#endif
