#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_energy = 100;
	_dmg = 30;
	std::cout << "FragTrap " << _name << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " is cloned" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		std::string	org_name = this->_name;
		ClapTrap::operator=(other);
		std::cout << "FragTrap " << org_name << " is altered into " << this->_name << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destroyed" << std::endl;
}

std::string	FragTrap::class_name() const {return ("FragTrap");}

void	FragTrap::highFiveGuys(void)
{
	if (is_ok())
		std::cout << class_name() << " " << _name << " : High Five Everybody ✋" << std::endl;
}
