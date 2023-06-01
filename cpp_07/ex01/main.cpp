/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/06/01 18:43:44 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void calculatepower(T t)
{
    std::cout << t * t << std::endl;
}

template<typename T>
void printing(T t)
{
    std::cout << t << std::endl;
}

template<typename T>
void addpoint(T t)
{
    std::cout << t + "." << std::endl;
}

int main()
{
    {
        std::cout << YELLOW "INT TEST" RESET << std::endl;
        int test1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << PURPLE << "starting values" RESET<< std::endl;
        iter(test1, 10, printing);
        std::cout << PURPLE << "calculate power" RESET << std::endl;
        iter(test1, 10, calculatepower);
    }
    {
        std::cout << YELLOW "CHAR TEST" RESET << std::endl;
        char test1[] = {'a', 'b', 'c'};
        std::cout << PURPLE << "values printed" RESET<< std::endl;
        iter(test1, 3, printing);
    }
    {
        std::cout << YELLOW "STRING TEST" RESET << std::endl;
        std::string test1[] = {"value 0", "value 1", "value 2", "value 3"};
        std::cout << PURPLE << "starting values" RESET<< std::endl;
        iter(test1, 4, printing);
        std::cout << PURPLE << "add point at the end" RESET << std::endl;
        iter(test1, 4, addpoint);
    }
}
