#include "AMateria.hpp"

AMateria::AMateria() : _type("materia") {};

AMateria::AMateria(const AMateria &other) : _type(other._type) {};

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

AMateria::~AMateria() {};

AMateria::AMateria(std::string const &type) : _type(type) {};

std::string const	&AMateria::getType() const {return(_type);}

void	AMateria::use(ICharacter& target) {(void)target;}
