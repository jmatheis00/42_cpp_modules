/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:11 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/11 16:18:36 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

void PhoneBook::add_contact(Contact contact)
{
    contact.init_firstname();
    contact.init_lastname();
    contact.init_nickname();
    contact.init_phonenumber();
    contact.init_darkestsecret();
	if (_num != 8)
	{
    	contacts[_num] = contact;
    	_num++;
	}
	else
	{
		if (_oldest == 8)
			_oldest = 0;
		contacts[_oldest] = contact;
		_oldest++;
	}
}

void PhoneBook::search_contact()
{
	if (_num == 0)
	{
		std::cout << "no contacts saved, add contact/s" << std::endl;
		return ;
	}
	for (int count = 0; count < _num; count++)
	{
		std::cout << count + 1 << "         ";
		search_get_spaces(contacts[count].firstname());
		search_get_spaces(contacts[count].lastname());
		search_get_spaces(contacts[count].nickname());
		search_get_spaces(contacts[count].phonenumber());
		search_get_spaces(contacts[count].darkestsecret());
		std::cout << "|" << std::endl;
	}
	show_contact_info();
}

void PhoneBook::search_get_spaces(std::string tmp)
{
	if (tmp.length() > 10)
		std::cout << "|" << tmp.substr(0,9) << ".";
	else
	{
		std::cout << "|" << tmp;
		for (size_t i = 0; i < 10 - tmp.length(); i++)
			std::cout << " ";
	}	
}

void PhoneBook::show_contact_info()
{
	std::string index;
	while (1)
	{	
		std::cout << "choose index to see all contact information:" << std::endl;
		getline(std::cin, index);
		if (index[0] > '0'  && index[0] < _num + '1' && !index[1])
		{
			std::cout << contacts[index[0] - '1'].firstname() << std::endl;
			std::cout << contacts[index[0] - '1'].lastname() << std::endl;
			std::cout << contacts[index[0] - '1'].nickname() << std::endl;
			std::cout << contacts[index[0] - '1'].phonenumber() << std::endl;
			std::cout << contacts[index[0] - '1'].darkestsecret() << std::endl;
			return ;
		}
		else
			std::cout << "invalid index, please try again" << std::endl;
	}
}
