/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/01 15:58:21 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

class NoOccurenceFound: public std::exception {
	public:
		virtual const char* what() const throw(){
			return("Occurence not found in Container!");
		}
};

int main(void)
{
    {
        std::cout << YELLOW "VECTOR TEST" RESET << std::endl;
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::vector<int>::iterator itb = v.begin();
        std::vector<int>::iterator ite = v.end();
        while(itb != ite)
        {
            std::cout << *itb << std::endl;
            itb++;
        }
        try
        {
            std::cout << PURPLE "Find int = 1" RESET << std::endl;
            std::cout << easyfind(v, 1) << std::endl;
            std::cout << PURPLE "Find int = 3" RESET << std::endl;
            std::cout << easyfind(v, 3) << std::endl;
            std::cout << PURPLE "Find int = 2" RESET << std::endl;
            std::cout << easyfind(v, 2) << std::endl;
            std::cout << PURPLE "Find int = 5" RESET << std::endl;
            std::cout << easyfind(v, 5) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    {
        std::cout << YELLOW "\nLIST TEST" RESET << std::endl;
        std::list<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::list<int>::iterator itb = v.begin();
        std::list<int>::iterator ite = v.end();
        while(itb != ite)
        {
            std::cout << *itb << std::endl;
            itb++;
        }
        try
        {
            std::cout << PURPLE "Find int = 1" RESET << std::endl;
            std::cout << easyfind(v, 1) << std::endl;
            std::cout << PURPLE "Find int = 3" RESET << std::endl;
            std::cout << easyfind(v, 3) << std::endl;
            std::cout << PURPLE "Find int = 2" RESET << std::endl;
            std::cout << easyfind(v, 2) << std::endl;
            std::cout << PURPLE "Find int = 5" RESET << std::endl;
            std::cout << easyfind(v, 5) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }    
    {
        std::cout << YELLOW "\nDEQUE TEST" RESET << std::endl;
        std::deque<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::deque<int>::iterator itb = v.begin();
        std::deque<int>::iterator ite = v.end();
        while(itb != ite)
        {
            std::cout << *itb << std::endl;
            itb++;
        }
        try
        {
            std::cout << PURPLE "Find int = 1" RESET << std::endl;
            std::cout << easyfind(v, 1) << std::endl;
            std::cout << PURPLE "Find int = 3" RESET << std::endl;
            std::cout << easyfind(v, 3) << std::endl;
            std::cout << PURPLE "Find int = 2" RESET << std::endl;
            std::cout << easyfind(v, 2) << std::endl;
            std::cout << PURPLE "Find int = 5" RESET << std::endl;
            std::cout << easyfind(v, 5) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    }
    return 0;
}
