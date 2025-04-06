/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:06:40 by aoo               #+#    #+#             */
/*   Updated: 2025/04/04 03:41:44 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class	Contact 
{
	private:
		std::string	_f_name;
		std::string	_l_name;
		std::string	_n_name;
		std::string	_ph_num;
		std::string	_secret;
	
	public:
		Contact();
		void	set_contact();
		void	show_content(int width, int index);
		void	show_detail();
};

void    get_safe_input(std::string prompt, std::string &value);
void	print_setw(size_t width, std::string str);

#endif