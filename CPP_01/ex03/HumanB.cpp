#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	if (_weapon)
	{
		std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
	}
}
