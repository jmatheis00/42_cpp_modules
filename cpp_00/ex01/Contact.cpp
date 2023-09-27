/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:22 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:07:21 by jmatheis         ###   ########.fr       */
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

// INIT DATA OF CONTACT
void Contact::set_firstname()
{
	std::string data;
	std::cout << "Enter first name: ";
	while (getline(std::cin, data))
	{
		if (!std::cin.eof() && data.compare(""))
		{
			firstname_ = data;
			return;
		}
		else if (!std::cin.eof())
		{
			std::cout << BOLDRED "Field can't be empty" RESET << std::endl;
			std::cout << "Enter first name: ";
		}
	}
	if (std::cin.eof())
		exit(1);
}

void Contact::set_lastname()
{
	std::string data;
	std::cout << "Enter last name: ";
	while (getline(std::cin, data))
	{
		if (!std::cin.eof() && data.compare(""))
		{
			lastname_ = data;
			return;
		}
		else if (!std::cin.eof())
		{
			std::cout << BOLDRED "Field can't be empty" RESET << std::endl;
			std::cout << "Enter last name: ";
		}
	}
	if (std::cin.eof())
		exit(1);
}

void Contact::set_nickname()
{
	std::string data;
	std::cout << "Enter nickname: ";
	while (getline(std::cin, data))
	{
		if (!std::cin.eof() && data.compare(""))
		{
			nickname_ = data;
			return;
		}
		else if (!std::cin.eof())
		{
			std::cout << BOLDRED "Field can't be empty" RESET << std::endl;
			std::cout << "Enter nickname: ";
		}
	}
	if (std::cin.eof())
		exit(1);
}

void Contact::set_phonenumber()
{
	std::string data;
	std::cout << "Enter phone number: ";
	while (getline(std::cin, data))
	{
		if (!std::cin.eof() && data.compare(""))
		{
			phonenumber_ = data;
			return;
		}
		else if (!std::cin.eof())
		{
			std::cout << BOLDRED "Field can't be empty" RESET << std::endl;
			std::cout << "Enter phone number: ";
		}
	}
	if (std::cin.eof())
		exit(1);
}

void Contact::set_darkestsecret()
{
	std::string data;
	std::cout << "Enter darkest secret: ";
	while (getline(std::cin, data))
	{
		if (!std::cin.eof() && data.compare(""))
		{
			darkestsecret_ = data;
			return;
		}
		else if (!std::cin.eof())
		{
			std::cout << BOLDRED "Field can't be empty" RESET << std::endl;
			std::cout << "Enter darkest secret: ";
		}
	}
	if (std::cin.eof())
		exit(1);
}

// RETURN DATA OF CONTACT
std::string Contact::get_firstname()
{
	return (firstname_);
}

std::string Contact::get_lastname()
{
	return (lastname_);
}

std::string Contact::get_nickname()
{
	return (nickname_);
}

std::string Contact::get_phonenumber()
{
	return (phonenumber_);
}

std::string Contact::get_darkestsecret()
{
	return (darkestsecret_);
}