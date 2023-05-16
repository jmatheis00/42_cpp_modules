/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/16 11:42:02 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        std::cout << YELLOW "\nShrubbery: Grade not signed, executing not working" RESET << std::endl;
        ShrubberyCreationForm home("Home");
        Bureaucrat bob("Bob", 147);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nShrubbery: Grade too low for executing" RESET << std::endl;
        ShrubberyCreationForm home("Home");
        Bureaucrat bob("Bob", 144);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nShrubbery: Execution works" RESET << std::endl;
        ShrubberyCreationForm home("Home");
        Bureaucrat bob("Bob", 120);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nRobotomy: Grade not signed, executing not working" RESET << std::endl;
        RobotomyRequestForm home("Home");
        Bureaucrat bob("Bob", 100);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nRobotomy: Grade too low for executing" RESET << std::endl;
        RobotomyRequestForm home("Home");
        Bureaucrat bob("Bob", 50);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nRobotomy: Execution works" RESET << std::endl;
        RobotomyRequestForm home("Home");
        Bureaucrat bob("Bob", 40);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
            bob.executeForm(home);
            bob.executeForm(home);
            bob.executeForm(home);
            bob.executeForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nPresidential: Grade not signed, executing not working" RESET << std::endl;
        PresidentialPardonForm home("Home");
        Bureaucrat bob("Bob", 50);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nPresidential: Grade too low for executing" RESET << std::endl;
        PresidentialPardonForm home("Home");
        Bureaucrat bob("Bob", 25);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nPresidential: Execution works" RESET << std::endl;
        PresidentialPardonForm home("Home");
        Bureaucrat bob("Bob", 5);
        try
        {
            bob.signForm(home);
            bob.executeForm(home);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    return 0;
}