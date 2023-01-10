#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

std::string PhoneBook::start_phonebook()
{
	std::string str;
    std::cout << "YOUR AWESOME PHONEBOOK" << std::endl;
    std::cout << "Possibilities:" << std::endl;
    std::cout << "\tADD" << std::endl;
    std::cout << "\tSEARCH" << std::endl;
    std::cout << "\tEXIT" << std::endl;
    std:: cout << "your choice: ";
    getline(std::cin, str); //reading whole line
	return (str);
}

void PhoneBook::check_action(std::string act)
{
	std::cout << act << std::endl; //testing
	if (!act.compare("ADD"))
	{
		std::cout << "action is add" << std::endl;
		// input information of new contact
		// one field at a time
		// fields can't be empty
		// 1. first name
		// 2. last name
		// 3. nickname
		// 4. phone number
		// 5. darkest secret
	}
	else if (!act.compare("SEARCH"))
	{
		std::cout << "action is search" << std::endl;
		// PhoneBook::contact[num] = addcontact(PhoneBook::contact[num]);
		// num++;
		// display the saved contacts as a list of 4 Columns:
			// index, firstname, lastname, nickname
		// Each column must be 10 chars wide
		// A pipe character separates them
		// if text is longer than the column it must be truncated
		//  & last displayable character must be replaced by a dot (.)
		// then prompt the user again for the index of the entry to display
		// if index is out of range or wrong, define a relevant behavior
		//  otherwise display contact information, one field per line
	}
	else if (!act.compare("EXIT"))
	{
		std::cout << "action is exit" << std::endl;
	}
	else
	{
		std::cout << "no valid input (any other input is discarded)" << std::endl;
	}
}