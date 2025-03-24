#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

void	Weapon::setType(std::string n_type) 
{
	type = n_type;
}

const std::string &Weapon::getType() const
{
	return (type);
}
