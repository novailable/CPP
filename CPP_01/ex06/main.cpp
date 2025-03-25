#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cerr << "Too many complaints! Live your life!\n" << std::endl;
		return (1);
	}

	if (argc == 1)
	{
		std::cout << "Good, good. No complaints! Have a nice day. :)\n" << std::endl;
		return (1);
	}

	Harl	harl;
	harl.complain(argv[1]);

	return (0);
}
