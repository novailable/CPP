#ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string class_name() const;
		std::string	_mode;

	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap	&operator=(const ScavTrap &other);
		~ScavTrap();
		
		ScavTrap(std::string name);
		
		void	attack(const std::string &target);
		void	guardGate();
		std::string	status() const;
};

#endif