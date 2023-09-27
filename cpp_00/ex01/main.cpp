/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:56 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:07:43 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void main_menu()
{
    std::cout << GREEN "Choose one of the following actions:\n"
              << std::endl
              << "\t\U0001F464\tADD\n"
              << "\t\U0001F50E\tSEARCH\n"
              << "\t\U0000274C\tEXIT\n" RESET
              << std::endl
              << "your action: ";
}

int main(void)
{
    PhoneBook pb;
    Contact contact;
    std::string act;

    main_menu();
    while (getline(std::cin, act))
    {
        if (act == "ADD")
        {
            pb.add_contact(contact);
            main_menu();
        }
        else if (act == "SEARCH")
            pb.search_contact();
        else if (act == "EXIT")
        {
            std::cout << BOLDGREEN "\nGOODBYE" RESET << std::endl;
            return (0);
        }
        else if (!std::cin.eof())
        {
            std::cout << BOLDRED "INVALID INPUT, PLEASE TRY AGAIN" RESET << std::endl;
            main_menu();
        }
    }
    return (0);
}
