#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <cstdarg>
#include <iomanip>

std::string	line = std::string(53, '-') + '\n';

std::string center(std::string input, int width = 113) 
{ 
    return std::string((width - input.length()) / 2, ' ') + input + std::string((width - input.length()) / 2, ' ');
}

// void	print_setw(size_t width, std::string str)
// {
// 	std::cout << std::setw(width) << (str.length() > width ? str.substr(0, width - 1) + "." : str) << " | ";
// }

void	npcs_status(ICharacter *npcs[])
{
	std::cout << line
		<< "| name | " << center("inventory", 50) << " |\n";
	for (int i = 0; npcs[i] != NULL; ++i)
	{
		std::cout << "| " << center("") ;
		print_setw(4, npcs[i]->getName());
		std::cout << " |" << std::endl;
	}
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "Character's OCF test\n";
	ICharacter *npcs[] = {me, bob, NULL};
	npcs_status(npcs);

	delete bob;
	delete me;
	delete src;
	return 0;
}