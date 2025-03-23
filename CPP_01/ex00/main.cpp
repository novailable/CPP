#include "Zombie.hpp"

int	main()
{
	Zombie	*zom = newZombie("Foo");
	zom->announce();

	randomChump("Faa");
	
	delete zom;
	return (0);
}
