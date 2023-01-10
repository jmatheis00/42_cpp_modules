#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int _num;  
        std::string _action;
    public:
        Contact contacts[8];
        void check_action();
        void add_contact(Contact contact);
};

#endif