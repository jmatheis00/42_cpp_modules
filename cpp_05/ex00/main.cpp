/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/16 11:56:38 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    {
        std::cout << YELLOW "\nTEST: CONSTRUCTOR WITH GRADE TOO LOW" RESET << std::endl;
        try
        {
            std::cout << "Grade: 151" << std::endl;
            Bureaucrat("Bob1", 151);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }
    }
    {
        std::cout << YELLOW "\nTEST: CONSTRUCTOR WITH GRADE TOO HIGH" RESET << std::endl;
        try
        {
            std::cout << "Grade: 0" << std::endl;
            Bureaucrat Bob2("Bob2", 0);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        } 
    }
    {
        std::cout << YELLOW "\nTEST: INCREMENT GRADE -> TOO HIGH" RESET << std::endl;
        Bureaucrat Bob3("Bob3", 2);
        try
        {
            std::cout << Bob3 << std::endl;
            Bob3.incrementGrade();
            Bob3.incrementGrade();
        }
        catch(std::exception &b)
        {
            std::cout << Bob3 << std::endl;
            std::cout << RED << b.what() << RESET<< std::endl;
        }
    }
    {
        std::cout << YELLOW "\nTEST: DECREMENTING GRADE -> TOO LOW" RESET << std::endl;
        Bureaucrat *Bob4 = new Bureaucrat("Bob4", 150);
        try
        {
            std::cout << *Bob4 << std::endl;
            Bob4->decrementGrade();
            Bob4->decrementGrade();
            Bob4->decrementGrade();
            Bob4->decrementGrade();
            std::cout << "This should not get printed" << std::endl;
        }
        catch(std::exception &b)
        {
            std::cout << *Bob4 << std::endl;
            std::cout << RED << b.what() << RESET<< std::endl;
        }
        delete Bob4;
    }
    {
        std::cout << YELLOW "\nTEST: NO EXCEPTIONS" RESET << std::endl;
        Bureaucrat *Bob5 = new Bureaucrat("Bob5", 100);
        try
        {
            std::cout << *Bob5 << std::endl;
            Bob5->decrementGrade();
            Bob5->decrementGrade();
            Bob5->decrementGrade();
            Bob5->incrementGrade();
        }
        catch(std::exception &b)
        {
            std::cout << "This should not get printed" << std::endl;
            std::cout << *Bob5 << std::endl;
            std::cout << RED << b.what() << RESET<< std::endl;
        }
        std::cout << *Bob5 << std::endl;
        delete Bob5;
    }
    return 0;
}