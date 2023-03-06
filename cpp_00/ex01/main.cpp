/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:56 by jmatheis          #+#    #+#             */
/*   Updated: 2023/02/07 13:36:33 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void start_phonebook();

void    main_menu()
{
    std::cout << MAGENTA << "\nChoose one of the following actions:\n" << RESET << std::endl;
    std::cout << GREEN  << "\t\U0001F464\tADD\n"
                        << "\t\U0001F50E\tSEARCH\n"
                        << "\t\U0000274C\tEXIT\n"
                        << std::endl
                        << "your action: " << RESET;
}

int main(void)
{
    PhoneBook pb;
    Contact contact;
    std::string act;

    pb.start_phonebook();
    main_menu();
    while (getline(std::cin, act))
    {
        if (!act.compare("ADD"))
        {
            pb.add_contact(contact);
            main_menu();
        }
        else if (!act.compare("SEARCH"))
        {
            pb.search_contact();
            // main_menu();
        }
        else if (!act.compare("EXIT"))
        {
            std::cout << BOLDGREEN << "\nGOODBYE" << RESET << std::endl;
            return (0);
        }
        else
        {
            std::cout << BOLDRED << "INVALID INPUT, PLEASE TRY AGAIN" << RESET << std::endl;
            main_menu();
        }
    }
    return (0);
}
