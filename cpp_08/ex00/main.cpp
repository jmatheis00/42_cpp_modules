/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/27 10:25:41 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NoOccurenceFound::what() const throw()
{
	return("Occurence not found in Container!");
}

int main(void)
{
    {
        std::cout << YELLOW "VECTOR TEST" RESET << std::endl;
        std::vector<int> v;
        for(int i = 0; i < 100; i++)
            v.push_back(i);

        std::cout << PURPLE "vector elements" RESET << std::endl;
        std::vector<int>::const_iterator itb = v.begin();
        while(itb != v.end())
        {
            std::cout << *itb << " ";
            itb++;
        }
        std::cout << std::endl;
        try
        {
            std::cout << PURPLE "Find int = 98" RESET << std::endl;
            std::cout << easyfind(v, 98) << std::endl;
            std::cout << PURPLE "Find int = 3" RESET << std::endl;
            std::cout << easyfind(v, 3) << std::endl;
            std::cout << PURPLE "Find int = 2" RESET << std::endl;
            std::cout << easyfind(v, 2) << std::endl;
            std::cout << PURPLE "Find int = 100" RESET << std::endl;
            std::cout << easyfind(v, 100) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {
        std::cout << YELLOW "\nLIST TEST" RESET << std::endl;
        std::list<int> v;
        v.push_back(33536243);
        v.push_back(64903);
        v.push_back(-23);
        std::cout << PURPLE "list elements" RESET << std::endl;
        std::list<int>::iterator itb = v.begin();
        while(itb != v.end())
        {
            std::cout << *itb << std::endl;
            itb++;
        }
        try
        {
            std::cout << PURPLE "Find int = -23" RESET << std::endl;
            std::cout << easyfind(v, -23) << std::endl;
            std::cout << PURPLE "Find int = 33536243" RESET << std::endl;
            std::cout << easyfind(v, 33536243) << std::endl;
            std::cout << PURPLE "Find int = 2" RESET << std::endl;
            std::cout << easyfind(v, 2) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }    
    {
        std::cout << YELLOW "\nDEQUE TEST" RESET << std::endl;
        std::deque<int> v;
        v.push_back(100);
        v.push_back(3);
        v.push_back(22);
        v.push_back(490);
        v.push_back(3);
        std::cout << PURPLE "deque elements" RESET << std::endl;
        std::deque<int>::iterator itb = v.begin();
        while(itb != v.end())
        {
            std::cout << *itb << std::endl;
            itb++;
        }
        try
        {
            std::cout << PURPLE "Find int = 3" RESET << std::endl;
            std::cout << easyfind(v, 3) << std::endl;
            std::cout << PURPLE "Find int = 22" RESET << std::endl;
            std::cout << easyfind(v, 22) << std::endl;
            std::cout << PURPLE "Find int = 490" RESET << std::endl;
            std::cout << easyfind(v, 490) << std::endl;
            std::cout << PURPLE "Find int = 101" RESET << std::endl;
            std::cout << easyfind(v, 101) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    return 0;
}
