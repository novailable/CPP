#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string input)
{
	try 
	{
		std::cout << static_cast<double>(input[1]) << std::endl;
	}
	catch(std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << input << std::endl;
}
0