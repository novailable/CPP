#ifndef FRAGTRAP_HPP
#define	FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		std::string class_name() const;

	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);
		~FragTrap();

		FragTrap(std::string name);
		
		void	highFiveGuys(void);
};

#endif