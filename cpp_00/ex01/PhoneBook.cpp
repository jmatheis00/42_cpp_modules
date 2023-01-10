#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void PhoneBook::check_action()
{
    getline(std::cin, _action); //reading whole line
	std::cout << _action << std::endl; //testing
	if (!_action.compare("ADD"))
	{
		std::cout << "action is add" << std::endl;
		// fields can't be empty
	}
	else if (!_action.compare("SEARCH"))
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
	else if (!_action.compare("EXIT"))
	{
		std::cout << "action is exit" << std::endl;
	}
	else
	{
		std::cout << "no valid input (any other input is discarded)" << std::endl;
	}
}

void PhoneBook::add_contact(Contact contact)
{
    contacts[_num] = contact;
    _num++;
}