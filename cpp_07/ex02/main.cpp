/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/21 18:02:57 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> test(5);
    std::cout << test.size() << std::endl;
    try
    {
        test[0] = 2;
        test[1] = 2;
        test[2] = 2;
        test[3] = 2;
        test[4] = 2;
        // test[5] = 2;  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    Array<int> test2(test);
    std::cout << test2[0] << std::endl;
    Array<int> test3(2);
    test3 = test;
    std::cout << test2[0] << std::endl;
    test[0] = 3;
    std::cout << PURPLE "DEEP COPY TEST" RESET << std::endl;
    std::cout << test[0] << std::endl;
    std::cout << test2[0] << std::endl;
    std::cout << test3[0] << std::endl;

    return (0);
}