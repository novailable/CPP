#ifndef FRAGTRAP_HPP
#define	FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		std::string class_name() const;

	public:
		FragTrap(std::string name);
		~FragTrap();

		void	highFiveGuys(void);
};

#endif