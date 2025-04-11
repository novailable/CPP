#ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string class_name() const;
	public:
		ScavTrap(std::string name);
		~ScavTrap();
	
	void	attack(const std::string &target);
	void	guardGate();
};

#endif