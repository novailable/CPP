#ifndef CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <sstream>

class ClapTrap
{
private:
	std::string	_name;
	int	_hp;
	int	_energy;
	int	_dmg;

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap	&operator=(const ClapTrap &other);
	~ClapTrap();

	void	attack(const std::string& target);	
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	setHp(int value);
	void	setEnergy(int value);
	void	setDmg(int value);
	
	bool	is_ok() const;
	std::string	status() const;
};

std::ostream	&operator<<(std::ostream &out, const ClapTrap &clap_trap);
#endif
