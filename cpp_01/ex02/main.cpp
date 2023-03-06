/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:20:59 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/06 15:48:11 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RESET       "\033[0m"
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // print addresses
    std::cout << GREEN << "\nMEMORY ADDRESSES\n" << RESET;
    std::cout << "string:\t\t" << &str << std::endl;
    std::cout << "stringPTR:\t" << stringPTR << std::endl;
    std::cout << "stringREF:\t" << &stringREF << std::endl;
    // print values
    std::cout << GREEN << "\nVALUES\n" << RESET;
    std::cout << "string:\t\t" << str << std::endl;
    std::cout << "stringPTR:\t" << *stringPTR << std::endl;
    std::cout << "stringREF:\t" << stringREF << std::endl;
    // changed value of str
    // std::cout << GREEN << "\nCHANGED VALUE OF STR\n" << RESET;
    // str = "BYE";
    // std::cout << "string:\t\t" << str << std::endl;
    // std::cout << "stringPTR:\t" << *stringPTR << std::endl;
    // std::cout << "stringREF:\t" << stringREF << std::endl;   
    return (0);
}