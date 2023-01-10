#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main(void)
{
    PhoneBook pb;
    Contact c;

    pb.action = pb.start_phonebook();
    pb.check_action(pb.action);
    c.add_contact(); //should be class function
    std:: cout << c.firstname << std::endl;
    return (0);
}
