#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void start_phonebook(void)
{
	PhoneBook   pb;

    std::cout << "YOUR AWESOME PHONEBOOK" << std::endl;
    std::cout << "Possibilities:" << std::endl;
    std::cout << "\tADD" << std::endl;
    std::cout << "\tSEARCH" << std::endl;
    std::cout << "\tEXIT" << std::endl;
    std:: cout << "your choice: ";
    // std:: cin >> str; //reading one string
    getline(std::cin, pb.action); //reading whole line
    // std::cout << pb.action << std::endl; //testing
}

void check_action(void)
{
	PhoneBook	pb;
	std::cout << pb.action << std::endl; //testing
	if (pb.action.compare("ADD") == 0)
	{
		std::cout << "action is add" << std::endl;
	}
	else
	{
		std::cout << "no valid action" << std::endl;
	}
}