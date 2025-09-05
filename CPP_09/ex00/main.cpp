#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "\033[31m" << "Error: Invalid arguments!" << "\033[1m" << std::endl, 1);
	try
	{
		BitcoinExchange btc;
		btc.exchange(argv[1]);
		// std::cout << btc << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "\033[31m\033[1m" << e.what() << "\033[0m" << std::endl;
	}
}
