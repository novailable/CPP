#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal	&operator=(const Animal &other);
		~Animal();

		virtual void	makeSound();
		std::string	getType() const;
};

#endif
