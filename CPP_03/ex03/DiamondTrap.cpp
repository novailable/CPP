#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_ClapTrap"), ScavTrap(name + "_ScavTrap"), FragTrap(name + "_FragTrap"), _name(name)
{
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_dmg = FragTrap::_dmg;

	std::cout << "DiamondTrap " << _name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	_name = other._name;
	std::cout << "DiamondTrap " << _name << " is cloned" << std::endl;	
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		std::string	org_name = _name;
		ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
		_name = other._name;
		std::cout << "DiamondTrap " << org_name << " is altered into " << _name << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is destoryed" << std::endl;
}

std::string	DiamondTrap::class_name() const {return ("DiamondTrap");}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << "\nmy ClapTrap name is " << ClapTrap::_name << std::endl;
}

std::string	DiamondTrap::status() const
{
	std::ostringstream	detail;

	detail << class_name() << " " << _name << " : hp " << _hp
			<< ", energy " << _energy << ", dmg " << _dmg;
	return (detail.str());
}
