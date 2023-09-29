/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/29 23:33:07 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void calculatepower(T t)
{
    t *= t;
}

template <typename T>
void printing(T t)
{
    std::cout << t << std::endl;
}

template <typename T>
void addpoint(T t)
{
    t += ".";
}

int main()
{
    {
        std::cout << YELLOW "INT TEST" RESET << std::endl;
        int test1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << PURPLE << "starting values" RESET << std::endl;
        iter(test1, 10, printing<int>);
        std::cout << PURPLE << "calculate power" RESET << std::endl;
        iter(test1, 10, calculatepower<int &>);
        iter(test1, 10, printing<int>);
    }
    {
        std::cout << YELLOW "CHAR TEST" RESET << std::endl;
        char test1[] = {'a', 'b', 'c'};
        std::cout << PURPLE << "values printed" RESET << std::endl;
        iter(test1, 3, printing<char>);
    }
    {
        std::cout << YELLOW "STRING TEST" RESET << std::endl;
        std::string test1[] = {"value 0", "value 1", "value 2", "value 3"};
        std::cout << PURPLE << "starting values" RESET << std::endl;
        iter(test1, 4, printing<std::string>);
        std::cout << PURPLE << "add point at the end" RESET << std::endl;
        iter(test1, 4, addpoint<std::string &>);
        iter(test1, 4, printing<std::string>);
    }
    return (0);
}

// using calculatorpower<int> -> creates copy of element which gets changed
// using int& -> reference -> access to original element, remains changed