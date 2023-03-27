/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:11 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/27 20:00:45 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
    num_ = 0;
	oldest_ = 0;
    std::cout << MAGENTA
	<< " _____  _    _  ____  _   _ ______ ____   ____   ____  _  __" << std::endl
    << "|  __ \\| |  | |/ __ \\| \\ | |  ____|  _ \\ / __ \\ / __ \\| |/ /" << std::endl
    << "| |__) | |__| | |  | |  \\| | |__  | |_) | |  | | |  | | ' /" << std::endl
    << "|  ___/|  __  | |  | | . ` |  __| |  _ <| |  | | |  | |  <" << std::endl
    << "| |    | |  | | |__| | |\\  | |____| |_) | |__| | |__| | . \\" << std::endl
    << "|_|    |_|  |_|\\____/|_| \\_|______|____/ \\____/ \\____/|_|\\_\\" RESET<< std::endl;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::add_contact(Contact contact)
{
    contact.set_firstname();
	contact.set_lastname();
    contact.set_nickname();
    contact.set_phonenumber();
    contact.set_darkestsecret();
	if (num_ != 8)
	{
    	contacts[num_] = contact;
    	num_++;
	}
	else
	{
		if (oldest_ == 8)
			oldest_ = 0;
		contacts[oldest_] = contact;
		oldest_++;
	}
}

void PhoneBook::search_contact()
{
	if (num_ != 0)
	{
		for (int count = 0; count < num_; count++)
		{
			std::cout << count + 1 << "         ";
			search_get_spaces(contacts[count].get_firstname());
			search_get_spaces(contacts[count].get_lastname());
			search_get_spaces(contacts[count].get_nickname());
			std::cout << "|" << std::endl;
		}
		show_contact_info();
	}
	else
		std::cout << BOLDRED "no contacts saved, add contact/s" RESET << std::endl;
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
	std::cout << "choose index to see all contact information: ";
	while (getline(std::cin, index))
	{	
		if (index[0] > '0'  && index[0] < num_ + '1' && !index[1])
		{
			std::cout << "first name:\t" << contacts[index[0] - '1'].get_firstname() << std::endl;
			std::cout << "last name:\t" << contacts[index[0] - '1'].get_lastname() << std::endl;
			std::cout << "nickname:\t" << contacts[index[0] - '1'].get_nickname() << std::endl;
			std::cout << "phone number:\t" << contacts[index[0] - '1'].get_phonenumber() << std::endl;
			std::cout << "darkest secret:\t" << contacts[index[0] - '1'].get_darkestsecret() << std::endl;
			return ;
		}
		else if (!std::cin.eof())
		{
			std::cout << BOLDRED "invalid index, please try again" RESET << std::endl;
			std::cout << "choose index to see all contact information: ";
		}
	}
	if(std::cin.eof())
		exit(1);
}
