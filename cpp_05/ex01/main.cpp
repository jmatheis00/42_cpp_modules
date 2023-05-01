/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/01 14:43:39 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << PURPLE "Destructors" RESET << std::endl;
    Form forms("contract", 50, 60);
    Bureaucrat b("Bob", 70);
    Bureaucrat c("Sam", 20);

    std::cout << YELLOW "\nTEST: FORM GRADES TOO HIGH OR TOO LOW" RESET << std::endl;
    try
    {
        Form fail("contract2", 12, 0);
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW "\nTEST: GRADE TOO LOW FOR SIGNING" RESET << std::endl;
    std::cout << GREEN "FORM INFORMATION" RESET << std::endl;
    std::cout << forms << std::endl;
    std::cout << GREEN "BUREAUCRAT INFORMATION" RESET << std::endl;
    std::cout << b << std::endl;
    try 
    {
        b.signForm(forms);
    }
    catch(std::exception &b)
    {
        // not necessary cause exception gets catched in signForm
        std::cout << RED << b.what() << RESET << std::endl;
    }

    std::cout << YELLOW "\nTEST: GRADE GETS SIGNED" RESET << std::endl;
    std::cout << GREEN "FORM INFORMATION" RESET << std::endl;
    std::cout << forms << std::endl;
    std::cout << GREEN "BUREAUCRAT INFORMATION" RESET << std::endl;
    std::cout << c << std::endl;
    try 
    {
        c.signForm(forms);
    }
    catch(std::exception &b)
    {
        std::cout << RED << b.what() << RESET << std::endl;
    }

    std::cout << YELLOW "\nTEST: GRADE WAS ALREADY SIGNED" RESET << std::endl;
    std::cout << GREEN "FORM INFORMATION" RESET << std::endl;
    std::cout << forms << std::endl;
    std::cout << GREEN "BUREAUCRAT INFORMATION" RESET << std::endl;
    std::cout << c << std::endl;
    try 
    {
        c.signForm(forms);
    }
    catch(std::exception &b)
    {
        // not necessary cause exception gets catched in signForm
        std::cout << RED << b.what() << RESET << std::endl;
    }
    std::cout << PURPLE "Destructors" RESET << std::endl;
    return 0;
}