/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:06:13 by aoo               #+#    #+#             */
/*   Updated: 2025/04/04 03:38:04 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	to_upper(std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i]);
}

int	main()
{
	std::string	help = "\nADD	- save a new contact!\nSEARCH	- find a specific content!\nEXIT	- exit program!\n";
	std::string	cmd;

	PhoneBook	ph_book;

	std::cout << "\nWelcome to Crabby!\n" << help ;
	while (true)
	{
		std::cout << std::string(53, '-') << std::endl;
		std::cout << "\nEnter Command - ADD | SEARCH | EXIT : ";
		if (!getline(std::cin, cmd))
			return (std::cin.clear(), std::cout << "\neof detected quitting." << std::endl, 0);
		cmd.erase(0, cmd.find_first_not_of(" \t\n\r\f\v"));
		cmd.erase(cmd.find_last_not_of(" \t\n\r\f\v") + 1);
		to_upper(cmd);
		if (cmd == "ADD")
			ph_book.add();
		else if (cmd == "SEARCH")
			ph_book.search();
		else if (cmd == "EXIT")
			return (std::cout << "\nThank you for using crabby, Bye...\n"<< std::endl, 0);
		else
			std::cout << "Invalid command!\n" << help ;
	}
}