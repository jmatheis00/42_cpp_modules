#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        // int num;
    public:
        std::string action;
        std::string start_phonebook();
        void check_action(std::string act);
        Contact *contact;

};

#endif