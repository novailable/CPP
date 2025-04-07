#include "Harl.hpp"

std::string	to_upper(std::string str)
{
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	Harl	harl;

	(void)argc;
	while (*++argv)
		harl.complain(to_upper(*argv));
}
