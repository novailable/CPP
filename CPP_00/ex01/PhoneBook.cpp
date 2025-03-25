/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:06:27 by aoo               #+#    #+#             */
/*   Updated: 2025/03/25 17:18:50 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _index(0) {}

void	PhoneBook::add()
{
	if (_count > 7)
	{
		for (int i = 0; i < 7; ++i) contacts[i] = contacts[i + 1];
		_count = 7;
	}
	contacts[_count].set_contact();
	_count++;
}

void	PhoneBook::search()
{
	std::string	index_str;
	int			index;

	if (_count == 0)
	{
		std::cout << "\nPhone book is empty!\nAdd new contact to see detail!" << std::endl;
		return ;
	}

	std:: cout << "\n" << std::string(53, '-') << std::endl;
	std::cout <<  "| ";
	print_setw(10, "Index");
	print_setw(10, "First Name");
	print_setw(10, "Last Name");
	print_setw(10, "Nick Name");
	std::cout << std::endl;
	std:: cout << std::string(53, '-') << std::endl;

	for (int i = 0; i < _count; i++) contacts[i].show_content(10, i + 1);

	std::cout << std::string(53, '-') << std::endl;

	get_safe_input("\nEnter index for detail : ", index_str);
	try
	{
		index = std::stoi(index_str);
		if (index > 0 && index <= _count)
			contacts[index - 1].show_detail();
		else
			std::cout << "Invalid index!\n";
	}
	catch (...)
	{
		std::cin.clear();
		std::cout << "Invalid input!" << std::endl;
	}
}
