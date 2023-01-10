#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void Contact::init_firstname()
{
	std::string data;
    std::cout << "Enter first name:" << std::endl;
    getline(std::cin, data);
	_firstname = data;
}
void Contact::init_lastname()
{
	std::string data;
    std::cout << "Enter last name:" << std::endl;
    getline(std::cin, data);
	_lastname = data;
}
void Contact::init_nickname()
{
	std::string data;
    std::cout << "Enter nickname:" << std::endl;
    getline(std::cin, data);
	_nickname = data;
}
void Contact::init_phonenumber()
{
	std::string data;
    std::cout << "Enter phone number:" << std::endl;
    getline(std::cin, data);
	_phonenumber = data;
}
void Contact::init_darkestsecret()
{
	std::string data;
    std::cout << "Enter darkest secret:" << std::endl;
    getline(std::cin, data);
	_darkestsecret = data;
}

std::string Contact::firstname()
{
	return(_firstname);
}
std::string Contact::lastname()
{
	return(_lastname);
}
std::string Contact::nickname()
{
	return(_nickname);
}
std::string Contact::phonenumber()
{
	return(_phonenumber);
}
std::string Contact::darkestsecret()
{
	return(_darkestsecret);
}