#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

bool	compare_objs(const std::string obj_name1, const std::string obj_name2, const Animal &a1, const Animal &a2)
{
	std::cout << obj_name1 + "\t>" << &a1 << " | type - " << a1.getType() << ", sound - ";
	a1.makeSound();
	std::cout << obj_name2 + "\t>" << &a2 << " | type - " << a2.getType() << ", sound - ";
	a2.makeSound();
	
	return (&a1 != &a2);
}

bool	wrong_compare_objs(const std::string obj_name1, const std::string obj_name2, const WrongAnimal &a1, const WrongAnimal &a2)
{
	std::cout << obj_name1 + "\t>" << &a1 << " | type - " << a1.getType() << ", sound - ";
	a1.makeSound();
	std::cout << obj_name2 + "\t>" << &a2 << " | type - " << a2.getType() << ", sound - ";
	a2.makeSound();
	
	return (&a1 != &a2);
}

int	main()
{
	Animal	creature;
	Animal	creature1(creature);
	compare_objs("creature", "creature1", creature, creature1);
	creature1.setType("Organism");
	Animal	creature2;
	creature2 = creature1;
	compare_objs("creature1", "creature2", creature1, creature2);
	std::cout << "\n";

	Dog	dog;
	Dog	dog1(dog);
	compare_objs("dog", "dog1", dog, dog1);
	dog1.setType("Chihuahua");
	Dog	dog2;
	dog2 = dog1;
	compare_objs("dog1", "dog2", dog1, dog2);
	std::cout << "\n";

	Cat	cat;
	Cat	cat1(cat);
	compare_objs("cat", "cat1", cat, cat1);
	cat1.setType("Burmese cat");
	Cat	cat2;
	cat2 = cat1;
	compare_objs("cat1", "cat2", cat1, cat2);
	std::cout << "\n";

	WrongAnimal	rong;
	WrongAnimal	rong1(rong);
	wrong_compare_objs("rong", "rong1", rong, rong1);
	creature1.setType("Eon");
	WrongAnimal	rong2;
	rong2 = rong1;
	wrong_compare_objs("rong1", "rong2", rong1, rong2);
	std::cout << "\n";

	WrongCat cut;
	WrongCat cut1(cut);
	wrong_compare_objs("cut", "cut1", cut, cut1);
	cut1.setType("RongCut");
	WrongCat cut2;
	cut2 = cut1;
	wrong_compare_objs("cut1", "cut2", cut1, cut2);
	std::cout << "\n";

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\n";

	const WrongAnimal* delta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	delta->makeSound();
	std::cout << "\n\n";
}