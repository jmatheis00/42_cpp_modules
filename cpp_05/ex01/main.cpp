/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/16 11:40:20 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        std::cout << YELLOW "\nTEST: FORM CONSTRUCTOR WITH GRADE TOO LOW" RESET << std::endl;
        try
        {
            std::cout << "Grade: 151" << std::endl;
            Form Form1("Form1", 151, 70);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        }   
    }
    {
        std::cout << YELLOW "\nTEST: FORM CONSTRUCTOR WITH GRADE TOO HIGH" RESET << std::endl;
        try
        {
            std::cout << "Grade: 0" << std::endl;
            Form Form2("Form2", 70, 0);
        }
        catch(std::exception &b)
        {
            std::cout << RED << b.what() << RESET<< std::endl;
        } 
    }
    {
        std::cout << YELLOW "\nTEST: GRADE TOO LOW TO GET SIGNED" RESET << std::endl;
        Bureaucrat Bob1("Bob1", 50);
        Form Form3("Form3", 25, 88);
        try
        {
            std::cout << Bob1 << std::endl;
            std::cout << Form3 << std::endl;
            Bob1.incrementGrade();
            Bob1.incrementGrade();
            Bob1.signForm(Form3);
        }
        catch(std::exception &b)
        {
            std::cout << Bob1 << std::endl;
            std::cout << RED << b.what() << RESET<< std::endl;
        }
    }
    {
        std::cout << YELLOW "\nTEST: GRADE GOT SIGNED" RESET << std::endl;
        Bureaucrat Bob1("Bob1", 77);
        Form Form3("Form3", 75, 88);
        try
        {
            std::cout << Bob1 << std::endl;
            std::cout << Form3 << std::endl;
            Bob1.incrementGrade();
            Bob1.incrementGrade();
            std::cout << Bob1 << std::endl;
            Bob1.signForm(Form3);
        }
        catch(std::exception &b)
        {
            std::cout << Bob1 << std::endl;
            std::cout << RED << b.what() << RESET<< std::endl;
        }
    }
    return 0;
}