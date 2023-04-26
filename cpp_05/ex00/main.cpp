/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/27 01:12:41 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << YELLOW "\nTEST: CONSTRUCTOR GRADE TOO LOW" RESET << std::endl;
    try
    {
        Bureaucrat Bob1("Bob1", 151);
    }
    catch(Bureaucrat::GradeTooLowException &b)
    {
        std::cout << b.what() << std::endl;
    }
    std::cout << YELLOW "\nTEST: CONSTRUCTOR GRADE TOO HIGH" RESET << std::endl;
    try
    {
        Bureaucrat Bob2("Bob2", 0);
    }
    catch(Bureaucrat::GradeTooHighException &b)
    {
        std::cout << b.what() << std::endl;
    }
    std::cout << YELLOW "\nTEST: INCREMENTING GRADE -> TOO HIGH" RESET << std::endl;
    Bureaucrat Bob3("Bob3", 2);
    std::cout << Bob3 << std::endl;
    try
    {
        Bob3.incrementGrade();
        Bob3.incrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &b)
    {
        std::cout << b.what() << std::endl;
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
    }
    catch(Bureaucrat::GradeTooLowException &b)
    {
        std::cout << b.what() << std::endl;
        std::cout << *Bob4 << std::endl;
    }
    delete Bob4;
    return 0;
}