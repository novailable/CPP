#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	di4m_tp("DI4M0ND-TP");
	std::cout << di4m_tp << "\n";

	std::cout << "\nCopy Constructor\n";
	DiamondTrap	di4m_tp1(di4m_tp);
	std::cout << "di4m_tp org\t> " << &di4m_tp << " | " << di4m_tp << "\n"
				<< "di4m_tp1\t> " << &di4m_tp1 << " | " << di4m_tp1 << "\n\n";
	
	std::cout << "\nAssign Overload\n";
	DiamondTrap	di4m_tp2("DI4M0ND-TP2");
	di4m_tp2 = di4m_tp;
	std::cout << "di4m_tp org\t> " << &di4m_tp << " | " << di4m_tp << "\n"
				<< "di4m_tp2\t> " << &di4m_tp2 << " | " << di4m_tp2 << "\n\n";
	
	
	
}
