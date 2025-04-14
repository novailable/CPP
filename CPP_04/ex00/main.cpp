#include "Animal.hpp"

int	main()
{
	Animal	anima;
	Animal	amina(anima);
	Animal	iamna;
	iamna = anima;
	amina.makeSound();
	std::cout << "type: " << amina.getType() << std::endl;
	
}