/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:06:31 by aoo               #+#    #+#             */
/*   Updated: 2025/04/04 03:43:55 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class   PhoneBook
{
    private:
        Contact contacts[8];
        int     _count;
    
    public:
        PhoneBook();
        void    add();
        void    search();
};

#endif