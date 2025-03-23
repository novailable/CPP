#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " just died!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie	*newZombie(std::string name)
{
	return new Zombie(name);
}

void	randomChump(std::string name)
{
	Zombie zom(name);
	zom.announce();
}

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return nullptr;

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; ++i)
		new (&horde[i]) Zombie(name + "_" + std::to_string(i));
	return horde;
}