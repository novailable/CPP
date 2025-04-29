#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	Animal* animals[6];

	for (int i = 0; i < 6; ++i)
	{
		if (i < 3)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < 6; ++i)
		animals[i]
}