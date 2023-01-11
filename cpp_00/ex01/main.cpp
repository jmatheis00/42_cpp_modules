/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:56 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/11 16:23:35 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void start_phonebook();

int main(void)
{
    PhoneBook pb;
    Contact contact;
    std::string act;

    start_phonebook();
    while (act.compare("EXIT"))
    {
        std::cout << MAGENTA << "\nChoose one of the following actions:\n" << RESET << std::endl;
        std::cout << GREEN  << "\t\U0001F464\tADD\n"
                            << "\t\U0001F50E\tSEARCH\n"
                            << "\t\U0000274C\tEXIT\n"
                            << std::endl
                            << "your action: " << RESET;
        getline(std::cin, act); 
        if (!act.compare("ADD"))
            pb.add_contact(contact);
        else if (!act.compare("SEARCH"))
            pb.search_contact();
        else if (!act.compare("EXIT"))
            std::cout << BOLDGREEN << "\nGOODBYE" << RESET << std::endl;
        else
            std::cout << BOLDRED << "INVALID INPUT, PLEASE TRY AGAIN" << RESET << std::endl;
    }
    return (0);
}

void start_phonebook()
{
    std::cout << MAGENTA<< " _____  _    _  ____  _   _ ______ ____   ____   ____  _  __" << RESET<< std::endl;
    std::cout << MAGENTA<< "|  __ \\| |  | |/ __ \\| \\ | |  ____|  _ \\ / __ \\ / __ \\| |/ /" << RESET<< std::endl;
    std::cout << MAGENTA<< "| |__) | |__| | |  | |  \\| | |__  | |_) | |  | | |  | | ' /" << RESET<< std::endl; 
    std::cout << MAGENTA<< "|  ___/|  __  | |  | | . ` |  __| |  _ <| |  | | |  | |  <" << RESET<< std::endl;  
    std::cout << MAGENTA<< "| |    | |  | | |__| | |\\  | |____| |_) | |__| | |__| | . \\" << RESET<< std::endl; 
    std::cout << MAGENTA<< "|_|    |_|  |_|\\____/|_| \\_|______|____/ \\____/ \\____/|_|\\_\\" << RESET<< std::endl;                                            
}
