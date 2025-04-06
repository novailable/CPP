#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	(void)argc;
	while (*++argv)
		harl.complain(*argv);
}
