#ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		std::string class_name() const;
		std::string	_mode;

	public:
		ScavTrap(std::string name);
		~ScavTrap();
	
		void	attack(const std::string &target);
		void	guardGate();
		std::string	status() const;
};

#endif