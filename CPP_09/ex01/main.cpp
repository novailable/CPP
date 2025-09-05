#include "RPN.hpp"

int	main(int argc, char **argv)
{	
	if (argc != 2)
		return (std::cerr << "\033[31m\033[1m" << "Error: Invalid arguments!" << "\033[0m" << std::endl, 1);
	try
	{
		RPN::operation(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}