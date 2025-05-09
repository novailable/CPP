#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	Character a("a");
	Character b("b");
	AMateria*	ice = new Ice();
	AMateria*	cure = new Cure();

	MateriaSource	source;
	source.learnMateria(ice);
	source.createMateria("ice");
	a.equip(ice);
	b.equip(cure);
	b.use(0, b);
	b = a;
	b.use(0, b);
}