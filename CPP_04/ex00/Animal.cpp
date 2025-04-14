#include "Animal.hpp"

Animal::Animal() : _type("animal")
{
	std::cout << "Animal is created : type - " << _type << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	_type = other._type;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		std::cout << "Animal assignment operator called" << std::endl;
		_type = other._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound()
{
	std::cout << _type << " sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}

