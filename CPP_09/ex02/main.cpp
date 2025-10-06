#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{	
	if (argc < 3)
		return (std::cerr << "\033[31m\033[1m" << "Error: Invalid arguments!" << "\033[0m" << std::endl, 1);
	try
	{
		PmergeMe::sort(++argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

