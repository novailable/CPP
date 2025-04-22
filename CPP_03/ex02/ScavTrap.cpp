#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "SC4V-TP";
	_hp = 100;
	_energy = 50;
	_dmg = 20;
	_mode = "Normal";
	std::cout << "ScavTrap is created with default name " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	_mode = other._mode;
	std::cout << "ScavTrap " << other._name << " is cloned" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		std::string	org_name = this->_name;
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << org_name << " is altered into " << other._name << std::endl;
		_mode = other._mode;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " is destroyed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_energy = 50;
	_dmg = 20;
	_mode = "Normal";
	std::cout << "ScavTrap " << _name << " is created" << std::endl;
}

std::string	ScavTrap::class_name() const {return ("ScavTrap");}


void	ScavTrap::attack(const std::string &target)
{
	if (!is_ok())
		return ;
	--_energy;
	std::cout << "Ka-BOOM! " << class_name() << " " << _name << " bringing the pain to " << target << "! Dealing " 
	<< _dmg << " point of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (!is_ok())
		return ;
	--_energy;
	_mode = "Gate Keeper";
	std::cout << class_name() << " " << _name << " gate keeper mode activiated. ÜR ÜR Æ Æ Æ Æ!" << std::endl;
}

std::string	ScavTrap::status() const
{
	std::ostringstream	detail;

	detail << ClapTrap::status() << ", mode " << _mode;
	return (detail.str());
}
