#include "Harl.hpp"

std::string	to_upper(std::string str)
{
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i]);
	return (str);
}

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
	harl.complain(to_upper(argv[1]));

	return (0);
}
