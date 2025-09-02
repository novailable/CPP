#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "\033[31m" << "Error: Invalid arguments!" << "\033[1m" << std::endl;
	try
	{
		RPN	rbn;
		rbn.operation(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}