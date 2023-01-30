/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:22 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/30 12:57:00 by jmatheis         ###   ########.fr       */
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
    std::cout << "Enter first name:" << std::endl;
    getline(std::cin, data);
	while (data == "")
	{
		std::cout << "Field can't be empty" << std::endl;
		std::cout << "Enter first name:" << std::endl;
    	getline(std::cin, data);
	}
	firstname_ = data;
}

void Contact::set_lastname()
{
	std::string data;
    std::cout << "Enter last name:" << std::endl;
    getline(std::cin, data);
	while (data == "")
	{
		std::cout << "Field can't be empty" << std::endl;
		std::cout << "Enter last name:" << std::endl;
    	getline(std::cin, data);
	}
	lastname_ = data;
}

void Contact::set_nickname()
{
	std::string data;
    std::cout << "Enter nickname:" << std::endl;
    getline(std::cin, data);
	while (data == "")
	{
		std::cout << "Field can't be empty" << std::endl;
		std::cout << "Enter nickname:" << std::endl;
    	getline(std::cin, data);
	}
	nickname_ = data;
}

void Contact::set_phonenumber()
{
	std::string data;
    std::cout << "Enter phone number:" << std::endl;
    getline(std::cin, data);
	while (data == "")
	{
		std::cout << "Field can't be empty" << std::endl;
		std::cout << "Enter phone number:" << std::endl;
    	getline(std::cin, data);
	}
	phonenumber_ = data;
}

void Contact::set_darkestsecret()
{
	std::string data;
    std::cout << "Enter darkest secret:" << std::endl;
    getline(std::cin, data);
	while (data == "")
	{
		std::cout << "Field can't be empty" << std::endl;
		std::cout << "Enter darkest secret:" << std::endl;
    	getline(std::cin, data);
	}
	darkestsecret_ = data;
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