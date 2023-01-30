/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:11 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/30 12:54:05 by jmatheis         ###   ########.fr       */
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
	if (num_ == 0)
	{
		std::cout << "no contacts saved, add contact/s" << std::endl;
		return ;
	}
	for (int count = 0; count < num_; count++)
	{
		// CHECK DATA
		std::cout << count + 1 << "         ";
		search_get_spaces(contacts[count].get_firstname());
		search_get_spaces(contacts[count].get_lastname());
		search_get_spaces(contacts[count].get_nickname());
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
		if (index[0] > '0'  && index[0] < num_ + '1' && !index[1])
		{
			std::cout << contacts[index[0] - '1'].get_firstname() << std::endl;
			std::cout << contacts[index[0] - '1'].get_lastname() << std::endl;
			std::cout << contacts[index[0] - '1'].get_nickname() << std::endl;
			std::cout << contacts[index[0] - '1'].get_phonenumber() << std::endl;
			std::cout << contacts[index[0] - '1'].get_darkestsecret() << std::endl;
			return ;
		}
		else
			std::cout << "invalid index, please try again" << std::endl;
	}
}

void PhoneBook::start_phonebook()
{
    std::cout << MAGENTA<< " _____  _    _  ____  _   _ ______ ____   ____   ____  _  __" << RESET<< std::endl;
    std::cout << MAGENTA<< "|  __ \\| |  | |/ __ \\| \\ | |  ____|  _ \\ / __ \\ / __ \\| |/ /" << RESET<< std::endl;
    std::cout << MAGENTA<< "| |__) | |__| | |  | |  \\| | |__  | |_) | |  | | |  | | ' /" << RESET<< std::endl; 
    std::cout << MAGENTA<< "|  ___/|  __  | |  | | . ` |  __| |  _ <| |  | | |  | |  <" << RESET<< std::endl;  
    std::cout << MAGENTA<< "| |    | |  | | |__| | |\\  | |____| |_) | |__| | |__| | . \\" << RESET<< std::endl; 
    std::cout << MAGENTA<< "|_|    |_|  |_|\\____/|_| \\_|______|____/ \\____/ \\____/|_|\\_\\" << RESET<< std::endl;                                            
}