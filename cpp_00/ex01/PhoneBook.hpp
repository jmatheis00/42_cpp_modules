/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:37 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/05 12:57:58 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

#define RESET       "\033[0m"
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define MAGENTA     "\033[35m"              /* Magenta */
#define BOLDRED     "\033[1m\033[31m"       /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"       /* Bold Green */

class PhoneBook
{
    private:
        int num_;
        int oldest_;
        Contact contacts[8];
    public:
        PhoneBook();
        ~PhoneBook();
        void check_action();
        void add_contact(Contact contact);
        void search_contact();
        void search_get_spaces(std::string tmp);
        void show_contact_info();
};

#endif