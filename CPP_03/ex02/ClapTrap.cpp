#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "ClapTrap " << _name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap "  << other._name << " is cloned" << std::endl;
	_name = other._name;
	_hp = other._hp;
	_energy = other._energy;
	_dmg = other._dmg;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		std::cout << "ClapTrap "  << this->_name << " is altered into " << other._name << std::endl;
		_name = other._name;
		_hp = other._hp;
		_energy = other._energy;
		_dmg = other._dmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap "  << _name << " is destroyed" << std::endl;
}

std::string	ClapTrap::class_name () const {return ("ClapTrap");}

void	ClapTrap::attack(const std::string& target)
{
	if (!is_ok())
		return ;
	_energy--;
	std::cout << class_name() << " "  << _name << " attacks " << target 
			<< ", causing " << _dmg << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hp -= amount;
	std::cout << class_name() << " "  << _name << " take " << amount << " damage\n" 
				<< _name << " has " << _hp << " hit point left\n";

	if (_hp <= 0)
		std::cout << class_name() << " "  << _name << " is dead now" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!is_ok())
		return ;
	_energy--;
	_hp += amount;
	std::cout << class_name() << " "  << _name << " is repaired\nCurrent hit point " << _hp << std::endl;
}

void	ClapTrap::setHp(int value)
{
	_hp = value;
}

void	ClapTrap::setEnergy(int value)
{
	_energy = value;
}

void	ClapTrap::setDmg(int value)
{
	_dmg = value;
}

bool	ClapTrap::is_ok() const
{
	if (_hp <= 0)
	{
		std::cout << class_name() << " " << _name << " is dead" << std::endl;
		return (0);
	}
	if (_energy <= 0)
	{
		std::cout << class_name() << " " <<  _name << " has no energy" << std::endl;
		return (0);
	}
	return (1);
}

std::string	ClapTrap::status() const
{
	std::ostringstream	detail;

	detail << class_name() << " " << _name 
		<< " : hp " << _hp 
		<< ", energy " << _energy 
		<< ", dmg " << _dmg;
	return (detail.str());
}

std::ostream	&operator<<(std::ostream &out, const ClapTrap &clap_trap)
{
	out << clap_trap.status();
	return (out);	
}