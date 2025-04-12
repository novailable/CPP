#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_energy = 100;
	_dmg = 30;
	std::cout << "FragTrap " << _name << " is created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destoryed" << std::endl;
}

std::string	FragTrap::class_name() const {return ("FragTrap");}

void	FragTrap::highFiveGuys(void)
{
	if (is_ok())
		std::cout << class_name() << " " << _name << " : Hi Five Everybody ✋" << std::endl;
}
