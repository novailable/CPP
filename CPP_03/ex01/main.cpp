#include "ScavTrap.hpp"

int	main()
{
	ScavTrap sc4v_tp_default;
	std::cout << sc4v_tp_default << "\n\n";

	ScavTrap	sc4v_tp("SC4V-TP");
	std::cout << sc4v_tp << "\n\n";

	std::cout << "Copy Constructor\n";
	ScavTrap	sc4v_tp1(sc4v_tp);
	std::cout << "sc4v_tp org\t> " << &sc4v_tp << " | " << sc4v_tp << "\n"
				<< "sc4v_tp1\t> " << &sc4v_tp1 << " | " << sc4v_tp1 << "\n\n"; 

	sc4v_tp.attack("Dummy");
	sc4v_tp.guardGate();
	sc4v_tp.takeDamage(20);
	std::cout << "\n" << sc4v_tp << "\n\n";

	std::cout << "Assign Overload\n";
	ScavTrap	sc4v_tp2("sc4v_tp2");
	std::cout << sc4v_tp2 << std::endl;
	sc4v_tp2 = sc4v_tp;
	std::cout << "sc4v_tp org\t> " << &sc4v_tp << " | " << sc4v_tp << "\n"
				<< "sc4v_tp2\t> " << &sc4v_tp2 << " | " << sc4v_tp2 << "\n\n";

	std::cout << "Hp & Energy Testing\n";
	sc4v_tp1.setHp(0);
	sc4v_tp1.setEnergy(0);
	std::cout << "sc4v_tp1 > " << sc4v_tp1 << std::endl;
	sc4v_tp1.attack("SC4V_TP2");
	sc4v_tp2.setEnergy(0);
	std::cout << "sc4v_tp2 > " << sc4v_tp2 << std::endl;
	sc4v_tp2.guardGate();
	std::cout << "\n" ; 

	ClapTrap* ptr = new ScavTrap("guardy");
	std::cout << ptr->status() << std::endl;
	delete	ptr;
	std::cout << "\n";
}
