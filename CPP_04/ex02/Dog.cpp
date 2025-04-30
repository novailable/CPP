#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog is created : type - " << _type << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Dog assignment operator called" << std::endl;
		_type = other._type;
		*_brain = *other._brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete	_brain;
}

void	Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}

void	Dog::think(const std::string idea)
{
	_brain->setIdea(idea);
}

std::string	Dog::remember(int index) const
{
	return (_brain->getIdea(index));
}
