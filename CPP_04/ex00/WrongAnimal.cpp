#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAniaml")
{
	std::cout << "WrongAnimal is created : type - " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	_type = other._type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		std::cout << "WrongAnimal assignment operator called" << std::endl;
		_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "~!@#$%^&*(-)_+" << std::endl;
}

std::string	WrongAnimal::getType() const {return (_type);}

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}
