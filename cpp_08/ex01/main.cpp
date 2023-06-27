/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/27 10:54:07 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    {
        std::cout << YELLOW "TEST FROM PDF" RESET << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17); 
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest span:\t" << sp.shortestSpan() << std::endl;
        std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
        sp.getSpan();
    }
    {
        std::cout << YELLOW "SPAN TEST NOT ENOUGH NUMBERS" RESET << std::endl;
        Span sp = Span(5);
        try
        {
            // sp.addNumber(6);
            std::cout << "SIZE:\t" << sp.getSize() << std::endl;
            std::cout << "shortest span:\t" << sp.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {
        std::cout << YELLOW "SPAN TEST N = 0" RESET << std::endl;
        Span sp = Span(0);
        try
        {
            std::cout << "SIZE:\t" << sp.getSize() << std::endl;
            std::cout << "shortest span:\t" << sp.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {
        std::cout << YELLOW "SPAN TEST SPAN ALREADY FILLED" RESET << std::endl;
        Span sp = Span(3);
        try
        {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            std::cout << "shortest span:\t" << sp.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {        
        std::cout << YELLOW "MANY NUMBERS SPAN ALREADY FILLED" RESET << std::endl;
        Span sp = Span(100);
        try
        {
            sp.addNumber(100);
            std::vector<int> test;
            for(int i = 0; i < 100; i++)
                test.push_back(rand() % 100);
            sp.addmanyNumbers(test);
            std::cout << "SIZE: " << sp.getSize() << std::endl;
            std::cout << "shortest span:\t" << sp.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
            sp.getSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {        
        std::cout << YELLOW "10.002 NUMBERS SPAN WORKING" RESET << std::endl;
        Span sp = Span(10002);
        try
        {
            sp.addNumber(2);
            std::vector<int> test;
            for(int i = 0; i < 10000; i++)
                test.push_back(rand() % 10000);
            sp.addmanyNumbers(test);
            sp.addNumber(346535);
            std::cout << "SIZE:\t" << sp.getSize() << std::endl;
            std::cout << "shortest span:\t" << sp.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
            // sp.getSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
   {        
        std::cout << YELLOW "addManyNumbers() working" RESET << std::endl;
        Span sp = Span(10);
        try
        {
            sp.addNumber(-10);
            std::vector<int> test;
            for(int i = 0; i < 10; i++)
                test.push_back(i);
            std::vector<int>::iterator it = test.begin();
            it += 5;
            sp.addmanyNumbers(it, test.end());
            sp.addNumber(300);
            sp.getSpan();
            std::cout << "SIZE:\t" << sp.getSize() << std::endl;
            std::cout << "shortest span:\t" << sp.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    return 0;
}
