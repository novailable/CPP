#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog is created : type - " << _type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = other._type;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Dog assignment operator called" << std::endl;
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}

