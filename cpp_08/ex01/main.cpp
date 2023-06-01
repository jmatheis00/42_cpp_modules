/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/30 18:40:50 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    {
        std::cout << YELLOW "SPAN TEST NOT ENOUGH NUMBERS" RESET << std::endl;
        Span sp = Span(5);
        try
        {
            // sp.addNumber(6);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
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
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
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
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {        
        std::cout << YELLOW "MANY NUMBERS SPAN ALREADY FILLED" RESET << std::endl;
        Span sp = Span(9);
        try
        {
            sp.addNumber(100);
            std::vector<int> test;
            for(int i = 0; i < 10; i++)
                test.push_back(rand() % 100);

            sp.addmanyNumber(test);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            sp.getSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {
        std::cout << YELLOW "SPAN TEST WORKING" RESET << std::endl;
        Span sp = Span(6);
        try
        {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            sp.getSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {        
        std::cout << YELLOW "10.000 NUMBERS SPAN WORKING" RESET << std::endl;
        Span sp = Span(10000);
        try
        {
            std::vector<int> test;
            for(int i = 0; i < 10000; i++)
                test.push_back(rand() % 100000);

            sp.addmanyNumber(test);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            sp.getSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    return 0;
}