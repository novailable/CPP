#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_ClapTrap"), ScavTrap(name + "_ScavTrap"), FragTrap(name + "_FragTrap"), _name(name)
{
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_dmg = FragTrap::_dmg;

	std::cout << class_name() << " " << _name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	_name = other._name;
	_hp = other._hp;
	_energy = other._energy;
	_dmg = other._dmg;
	std::cout << "DiamondTrap " << _name << " is cloned" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		std::cout << "DiamondTrap " << _name << " is altered into " << other._name << std::endl;
		ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
		_hp = other._hp;
		_energy = other._energy;
		_dmg = other._dmg;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is destoryed" << std::endl;
}
