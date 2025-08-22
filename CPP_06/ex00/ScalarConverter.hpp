#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <exception>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static	void	convert(const std::string &input);
};

#endif
