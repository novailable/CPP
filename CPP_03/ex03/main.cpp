#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	di4m_tp_default;
	std::cout << di4m_tp_default << "\n\n";

	DiamondTrap	di4m_tp("DI4M0ND-TP");
	std::cout << di4m_tp << "\n";

	std::cout << "\nCopy Constructor\n";
	DiamondTrap	di4m_tp1(di4m_tp);
	std::cout << "di4m_tp org\t> " << &di4m_tp << " | " << di4m_tp << "\n"
				<< "di4m_tp1\t> " << &di4m_tp1 << " | " << di4m_tp1 << "\n\n";

	di4m_tp.whoAmI();
	std::cout << "\n";

	di4m_tp.attack("Dummy");
	di4m_tp.takeDamage(50);
	di4m_tp.beRepaired(30);
	di4m_tp.guardGate();
	di4m_tp.highFiveGuys();
	std::cout << di4m_tp << "\n";

	std::cout << "\nAssign Overload\n";
	DiamondTrap	di4m_tp2("DI4M0ND-TP2");
	di4m_tp2 = di4m_tp;
	std::cout << "di4m_tp org\t> " << &di4m_tp << " | " << di4m_tp << "\n"
				<< "di4m_tp2\t> " << &di4m_tp2 << " | " << di4m_tp2 << "\n\n";

	di4m_tp.setEnergy(0);
	std::cout << di4m_tp << "\n";
	di4m_tp.beRepaired(20);

	di4m_tp.setHp(0);
	std::cout << di4m_tp << "\n";
	di4m_tp.highFiveGuys();

	std::cout << "\n";
	ClapTrap* ptr = new DiamondTrap("dimmy");
	std::cout << *ptr << std::endl;
	delete	ptr;
	std::cout << "\n";

}
