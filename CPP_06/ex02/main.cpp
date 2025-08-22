#include "Base.hpp"

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define CYAN		"\033[36m"
#define BOLD		"\033[1m"

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main()
{
	Base *random = generate();
	std::cout << CYAN << "Identify by pointer:\n" << RESET;
	identify(random);
	std::cout << CYAN << "Identify by reference:\n" << RESET;
	identify(*random);

	delete random;
}