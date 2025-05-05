#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
}

Character::Character(const Character &other)
{
	_name = other._name;
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 
		
	}
}

Character::Character(const Character &other)