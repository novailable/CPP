#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <cstdarg>
#include <iomanip>

std::string	line = "+" + std::string(60, '-') + "+\n";

void	npcs_status(Character &npc1, Character &npc2)
{
	std::cout << &npc1 << ", " << npc1.status() << &npc2 << ", " << npc2.status();
}

void	srcs_status(MateriaSource &ms1, MateriaSource &ms2)
{
	std::cout << &ms1 << ", " << ms1.display() << &ms2 << ", " <<  ms2.display();
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

	delete bob;
	delete me;
	delete src;

	std::cout << line << "MaterialSource's OCF test\n";
	MateriaSource	ms1;
	MateriaSource	ms2;
	
	ms1.learnMateria(new Ice());
	ms1.learnMateria(new Cure());
	ms2.learnMateria(new Cure());

	MateriaSource	ms3(ms2);
	srcs_status(ms2, ms3);
	std::cout << "\n";
	srcs_status(ms1, ms2);
	ms2 = ms1;
	srcs_status(ms1, ms2);

	std::cout << line << "Character's OCF test\n";
	Character c1;
	c1.equip(ms1.createMateria("ice"));
	c1.equip(ms1.createMateria("ice"));
	c1.equip(ms1.createMateria("ice"));
	c1.equip(ms1.createMateria("cure"));

	// AMateria *temp = ms1.createMateria("cure");
	// c1.equip(temp);
	// delete temp;
	
	Character c2("c2");
	npcs_status(c1, c2);
	c2 = c1;
	npcs_status(c1, c2);
	std::cout << "\n";
	c1.equip(ms1.createMateria("fire"));
	npcs_status(c1, c2);

	std::cout << line << "AMateria OCF test" << std::endl;
	AMateria *ice = new Ice();
	AMateria *materia(ice);
	std::cout << materia->getType() << std::endl;
	AMateria *cure = new Cure();
	*ice = *cure;
	std::cout << ice->getType() << ", " << cure->getType() << std::endl;
	delete	ice;
	delete cure;
	return 0;
}