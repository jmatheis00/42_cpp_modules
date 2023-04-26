/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/27 01:20:51 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << YELLOW "\nTEST: CONSTRUCTOR GRADE TOO LOW" RESET << std::endl;
    try
    {
        std::cout << "Grade: 151" << std::endl;
        Bureaucrat Bob1("Bob1", 151);
    }
    catch(std::exception &b)
    {
        std::cout << RED << b.what() << RESET<< std::endl;
    }
    std::cout << YELLOW "\nTEST: CONSTRUCTOR GRADE TOO HIGH" RESET << std::endl;
    try
    {
        std::cout << "Grade: 0" << std::endl;
        Bureaucrat Bob2("Bob2", 0);
    }
    catch(std::exception &b)
    {
        std::cout << RED << b.what() << RESET<< std::endl;
    }
    std::cout << YELLOW "\nTEST: INCREMENTING GRADE -> TOO HIGH" RESET << std::endl;
    Bureaucrat Bob3("Bob3", 2);
    std::cout << Bob3 << std::endl;
    try
    {
        Bob3.incrementGrade();
        Bob3.incrementGrade();
    }
    catch(std::exception &b)
    {
        std::cout << RED << b.what() << RESET<< std::endl;
        std::cout << Bob3 << std::endl;
    }
    std::cout << YELLOW "\nTEST: DECREMENTING GRADE -> TOO LOW" RESET << std::endl;
    Bureaucrat *Bob4 = new Bureaucrat("Bob4", 150);
    std::cout << *Bob4 << std::endl;
    try
    {
        Bob4->decrementGrade();
        Bob4->decrementGrade();
        Bob4->decrementGrade();
        Bob4->decrementGrade();
        std::cout << "This should not get printed" << std::endl;
    }
    catch(std::exception &b)
    {
        std::cout << RED << b.what() << RESET<< std::endl;
        std::cout << *Bob4 << std::endl;
    }
    std::cout << std::endl;
    delete Bob4;
    return 0;
}