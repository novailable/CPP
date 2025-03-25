#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	while (*++argv)
		harl.complain(*argv);
}
