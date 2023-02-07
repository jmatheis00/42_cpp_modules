/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:22 by jmatheis          #+#    #+#             */
/*   Updated: 2023/02/07 13:27:55 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{

}

Contact::~Contact()
{
	
}

// init data of contact
void Contact::set_firstname()
{
	std::string data;
    std::cout << "Enter first name: ";
   	while (getline(std::cin, data))
	{
		if (data.compare(""))
		{
			firstname_ = data;
			return ;
		}
		else
		{
			std::cout << BOLDRED << "Field can't be empty" << RESET << std::endl;
			std::cout << "Enter first name: ";
		}
	}
	if (!firstname_.compare(""))
		exit (1);
}

void Contact::set_lastname()
{
	std::string data;
    std::cout << "Enter last name: ";
	while (getline(std::cin, data))
	{
		if (data.compare(""))
		{
			lastname_ = data;
			return ;
		}
		else
		{
			std::cout << BOLDRED << "Field can't be empty" << RESET << std::endl;
			std::cout << "Enter last name: ";
		}
	}
	if (!lastname_.compare(""))
		exit (1);
}

void Contact::set_nickname()
{
	std::string data;
    std::cout << "Enter nickname: ";
	while (getline(std::cin, data))
	{
		if (data.compare(""))
		{
			nickname_ = data;
			return ;
		}
		else
		{
			std::cout << BOLDRED << "Field can't be empty" << RESET << std::endl;
			std::cout << "Enter nickname: ";
		}
	}
	if (!nickname_.compare(""))
		exit (1);
}

void Contact::set_phonenumber()
{
	std::string data;
    std::cout << "Enter phone number: ";
	while (getline(std::cin, data))
	{
		if (data.compare(""))
		{
			phonenumber_ = data;
			return ;
		}
		else
		{
			std::cout << BOLDRED << "Field can't be empty" << RESET << std::endl;
			std::cout << "Enter phone number: ";
		}
	}
	if (!phonenumber_.compare(""))
		exit (1);
}

void Contact::set_darkestsecret()
{
	std::string data;
    std::cout << "Enter darkest secret: ";
	while (getline(std::cin, data))
	{
		if (data.compare(""))
		{
			darkestsecret_ = data;
			return ;
		}
		else
		{
			std::cout << BOLDRED << "Field can't be empty" << RESET << std::endl;
			std::cout << "Enter darkest secret: ";
		}
	}
	if (!darkestsecret_.compare(""))
		exit (1);
}

// return data of contact
std::string Contact::get_firstname()
{
	return(firstname_);
}

std::string Contact::get_lastname()
{
	return(lastname_);
}

std::string Contact::get_nickname()
{
	return(nickname_);
}

std::string Contact::get_phonenumber()
{
	return(phonenumber_);
}

std::string Contact::get_darkestsecret()
{
	return(darkestsecret_);
}