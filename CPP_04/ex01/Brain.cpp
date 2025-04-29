#include "Brain.hpp"

Brain::Brain() : _index(0)
{
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copied" << std::endl;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
	_index = other._index;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain is assigned" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
		_index = other._index;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}

void	Brain::setIdea(std::string idea)
{
	if (_index == 99)
		_index = 0;
	_ideas[_index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return (_ideas[index]);
	}
	return "";
}
