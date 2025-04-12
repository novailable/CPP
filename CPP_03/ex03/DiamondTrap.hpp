#ifndef	DIAMONDTRAP_HPP
#define	DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
		std::string	class_name() const;
	
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap	&operator=(const DiamondTrap &other);
		~DiamondTrap();

		void	whoAmI();
		std::string	status() const;
};

#endif
