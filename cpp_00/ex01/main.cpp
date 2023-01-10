#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void start_phonebook();
void get_contact_data();

int main(void)
{
    PhoneBook pb;
    Contact c;

    start_phonebook();
    pb.check_action();
    get_contact_data();
    std::cout << "TEST2 " << c.firstname() << std::endl; //problem here
    pb.add_contact(c); // add contact to phonebook
    return (0);
}

void start_phonebook()
{
	std::string str;
    std::cout << "YOUR AWESOME PHONEBOOK" << std::endl;
    std::cout << "Possibilities:" << std::endl;
    std::cout << "\tADD\n" << "\tSEARCH\n" << "\tEXIT" << std::endl;
    std::cout << "your choice: ";
}

void get_contact_data()
{
    Contact c;
    c.init_firstname();
    c.init_lastname();
    c.init_nickname();
    c.init_phonenumber();
    c.init_darkestsecret();
    std::cout << "TEST " << c.firstname() << std::endl;
}
// phonebook.add_contact(contact);
// void add_contact(Contact contact);
// void Phonebook::add_contact(Contact _contact)
// {

// 	if (_count == 8)
// 	{
// 		for (size_t i = 0; i < 7; i++)
// 			_contacts[i] = _contacts[i + 1];
// 		_contacts[7] = _contact;
// 	}
// 	else
// 	{
// 		_contacts[_count] = _contact;
// 		_count++;
// 	}
// }