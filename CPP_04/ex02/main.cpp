#include "Dog.hpp"
#include "Cat.hpp"

bool	compare_dogs(std::string msg1, Dog *d1, std::string msg2, Dog *d2)
{
	std::cout << msg1 << d1 << ", think - " << d1->remember(0) << "\n"
			<< msg2 << d2 << ", think - " << d2->remember(0) << std::endl;
	
	return (d1 != d2);
}

bool	compare_cats(std::string msg1, Cat *c1, std::string msg2, Cat *c2)
{
	std::cout << msg1 << c1 << ", think - " << c1->remember(0) << "\n"
			<< msg2 << c2 << ", think - " << c2->remember(0) << std::endl;
	
	return (c1 != c2);
}

int	main()
{
	int num = 4;
	Animal* animals[num];

	for (int i = 0; i < num; ++i)
	{
		if (i < 3)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < num; ++i)
		delete animals[i];
	std:: cout << std::string(53, '*') << "\n";

	Dog	*dog = new Dog();
	Cat	*cat = new Cat();
	std:: cout << std::string(53, '*')
			<< "\nBrain work\n";
	dog->think("Bone!");
	cat->think("Fish!");
	std::cout << "dog : " << dog->remember(0) << ", cat : " << cat->remember(0) << std::endl
		<< std::string(53, '*') << "\n"
		<< "Dog OCF tests\n\n";
	Dog	pod(*dog);
	compare_dogs("dog : ", dog, "pod : ", &pod);
	std::cout << "\n";
	Dog bob;
	bob = *dog;
	compare_dogs("dog : ", dog, "bob : ", &bob);
	delete dog;

	std::cout << "\n" << std::string(53, '*')
			<< "\nCat OCF tests\n\n";
	Cat mew(*cat);
	compare_cats("cat : ", cat, "mew : ", &mew);
	std::cout << "\n";
	Cat cuppy;
	cuppy = *cat;
	compare_cats("cat : ", cat, "cuppy : ", &cuppy);
	std::cout << std::string(53, '*') << "\n";

}