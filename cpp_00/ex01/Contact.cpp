#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

std::string Contact::add_data(std::string type)
{
	std::string str;
	std:: cout << "Enter" << type << ": ";
    getline(std::cin, str);
	return(str);
}

void Contact::add_contact()
{
	Contact c;
	c.firstname = add_data("first name");
	c.lastname = add_data("last name");
	c.nickname = add_data("nickname");
	c.phonenumber = add_data("phone number");
	c.darkestsecret = add_data("darkest secret");
}