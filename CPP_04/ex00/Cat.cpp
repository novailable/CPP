#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat is created : type - " << _type << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = other._type;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Cat assignment operator called" << std::endl;
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meoww~" << std::endl;
}
