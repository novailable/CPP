#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n"
				"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger\n"
				"I really do!\n\n";
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n"
				"I cannot believe adding extra bacon costs more money.\n"
				"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void 	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n"
				"I think I deserve to have some extra bacon for free.\n"
				"I’ve been coming for years, whereas you started working here just last month.\n\n";
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n"
				"This is unacceptable! I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	int	i = 0;

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (; i < 4; ++i)
	{
		if (levels[i] == level)
			break ;
	}

	switch (i)
	{
		case 0: debug();
		case 1: info();
		case 2: warning();
		case 3:	error(); break;
		default : std::cout << "[ Probably complaining about insignificant problems ]\n\n";
	}
}
