#ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		std::string class_name() const;
		std::string	_mode;
	
	protected:
		int	_energy;

	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap	&operator=(const ScavTrap &other);
		~ScavTrap();

		ScavTrap(std::string name);
	
		void	attack(const std::string &target);
		void	beRepaired(unsigned int amount);
		void	guardGate();
		void	setEnergy(int value);
		std::string	status() const;
};

#endif
