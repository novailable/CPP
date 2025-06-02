#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat is created : type - " << _type << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Cat assignment operator called" << std::endl;
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete	_brain;
}

void	Cat::makeSound() const
{
	std::cout << "meoww~" << std::endl;
}

void	Cat::think(const std::string idea)
{
	_brain->setIdea(idea);
}

std::string	Cat::remember(int index) const
{
	return (_brain->getIdea(index));
}
