#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_template[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
		_template[i] = other._template[i] ? other._template[i]->clone() : 0;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_template[i])
			{
				delete	_template[i];
				_template[i] = other._template[i] ? other._template[i]->clone() : 0;
			}
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_template[i])
		{std::cout << _template[i]->getType() << " trying to delete\n";
			delete	_template[i];}
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_template[i])
		{
			_template[i] = m;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_template[i] && _template[i]->getType() == type)
			return (_template[i]->clone());
	}
	return (0);
}
