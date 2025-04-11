#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	egg("egg");
	ClapTrap	rock("rock");

	std::cout << egg << std::endl;
	std::cout << rock << "\n\n";

	egg.attack("rock");
	rock.takeDamage(0);
	std::cout << "\n" << rock.status() << "\n";
	rock.beRepaired(1);
	std::cout << "\n";

	ClapTrap	rock_clone(rock);
	std::cout << rock_clone << "\n\n";

	egg.beRepaired(2);
	std::cout << "\n";

	ClapTrap	egg_successor("egg_successor");
	std::cout << egg_successor << "\n\n";
	egg_successor = egg;
	std::cout << "egg_org > " << egg << "\n" 
				<< "egg_successor > " << egg_successor << "\n\n";

	egg.setHp(0);
	rock.setEnergy(0);
	rock.setDmg(100);
	std::cout << egg << "\n" << rock << "\n\n";

	egg.beRepaired(10);
	rock.attack("egg");

	std::cout << "\nrock\t: " << &rock << ", rock_clone\t: " << &rock_clone
				<< "\negg\t: " << &egg << ", egg_successor\t: " << &egg_successor 
				<< "\n\n";
}
