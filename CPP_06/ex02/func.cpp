#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void)
{
	Base	*bases[] = {new A, new B, new C};

	std::srand(std::time(0));
	return (bases[std::rand() % 3]);
}

void	identify(Base* p)
{
	std::cout << "p: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "neither of them" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "p: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}catch (std::bad_cast&) {}
}
