#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
}

Character::Character(const Character &other)
{
	_name = other._name;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : 0;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; ++i)
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : 0;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		delete	_inventory[i];
}

std::string const	&Character::getName() const {return (_name);}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		std::cout << _name << " : ";
		_inventory[idx]->use(target);
	}
}

std::string	Character::status() const
{
	std::string result = _name + " : ";

	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
			result += _inventory[i]->getType() + ", ";
	}
	result += "\n";
	return (result);
}
