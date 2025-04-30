#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat is created : type - " << _type << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = other._type;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		std::cout << "WrongCat assignment operator called" << std::endl;
		_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "meoww~" << std::endl;
}
