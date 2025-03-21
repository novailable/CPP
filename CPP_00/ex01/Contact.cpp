/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:06:22 by aoo               #+#    #+#             */
/*   Updated: 2025/03/21 03:06:23 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    get_safe_input(std::string prompt, std::string &value)
{
	while (true)
	{
		std::cout << prompt;
		if (!getline(std::cin, value))
		{
			std::cin.clear();
			std::cout << "\neof detected quitting." << std::endl;
			exit(0);
		}
		if (value.empty())
			std::cout << "\nThe value cannot be empty. Try again.\n";
		else
			break;
	}
}

void	print_setw(int width, std::string str)
{
	std::cout << std::setw(width) << (str.length() > width ? str.substr(0, width - 1) + "." : str) << " | ";
}

Contact:: Contact() {}

void    Contact::set_contact()
{
	get_safe_input("\nEnter First Name     : ", _f_name);
	get_safe_input("Enter Last Name      : ", _l_name);
	get_safe_input("Enter Nick Name      : ", _n_name);
	get_safe_input("Enter Phone Number   : ", _ph_num);
	get_safe_input("Enter Darkest Secret : ", _secret);

	std::cout << "\nContact successfully added!" << std::endl;
};

void	Contact::show_content(int width, int index)
{
	std::cout << "| ";
	print_setw(10, std::to_string(index));
	print_setw(10, _f_name);
	print_setw(10, _l_name);
	print_setw(10, _n_name);
	std::cout << std::endl;
}

void	Contact::show_detail()
{
	std::cout << "\nDetail of the contact\n" << std::endl;
	print_setw(14, "FirstName"); std::cout << _f_name << std::endl;
	print_setw(14, "Last Name"); std::cout << _l_name << std::endl;
	print_setw(14, "Nickname"); std::cout << _n_name << std::endl;
	print_setw(14, "Phone Number"); std::cout <<  _ph_num << std::endl;
	print_setw(14, "Darkest Secret"); std::cout << _secret << std::endl;
}