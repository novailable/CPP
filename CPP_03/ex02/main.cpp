#include "FragTrap.hpp"

int	main()
{
	FragTrap	fr4g_default;
	std::cout << fr4g_default << "\n\n";

	FragTrap	fr4g_tp("FR4G-TP");
	std::cout << fr4g_tp << "\n\n";

	std::cout << "Copy Constructor\n";
	FragTrap	fr4g_tp1(fr4g_tp);
	std::cout << "fr4g_tp org\t> " << &fr4g_tp << " | " << fr4g_tp << "\n"
				<< "fr4g_tp1\t> " << &fr4g_tp1 << " | " << fr4g_tp1 << "\n\n"; 

	fr4g_tp.attack("Dummy");
	fr4g_tp.highFiveGuys();
	fr4g_tp.takeDamage(20);
	std::cout << fr4g_tp << "\n\n";

	std::cout << "Assign Overload\n";
	FragTrap	fr4g_tp2("fr4g_tp2");
	std::cout << fr4g_tp2 << std::endl;
	fr4g_tp2 = fr4g_tp;
	std::cout << "fr4g_tp org\t> " << &fr4g_tp << " | " << fr4g_tp << "\n"
				<< "fr4g_tp2\t> " << &fr4g_tp2 << " | " << fr4g_tp2 << "\n\n";

	std::cout << "Hp & Energy Testing\n";
	fr4g_tp1.setHp(0);
	fr4g_tp1.setEnergy(0);
	std::cout << "fr4g_tp1 > " << fr4g_tp1 << std::endl;
	fr4g_tp1.highFiveGuys();
	fr4g_tp2.setEnergy(0);
	std::cout << "fr4g_tp2 > " << fr4g_tp2 << std::endl;
	fr4g_tp2.highFiveGuys();
	std::cout << "\n" ; 

	ClapTrap* ptr = new FragTrap("fragy");
	std::cout << ptr->status() << std::endl;
	delete	ptr;
	std::cout << "\n";
}
