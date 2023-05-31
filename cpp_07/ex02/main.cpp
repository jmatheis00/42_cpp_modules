/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/31 18:10:48 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    {
        std::cout << YELLOW "INT Array test" RESET << std::endl;
        std::cout << PURPLE "Constructor with size" RESET << std::endl;
        Array<int> test1(5);
        std::cout << "size of test1: " << test1.size() << std::endl;
        std::cout << PURPLE "Default Constructor" RESET << std::endl;
        Array<int> test2;
        std::cout << "size of test2: " << test2.size() << std::endl;
        std::cout << PURPLE "Filling values + out of range test" RESET << std::endl;
        try
        {
            test1[0] = 1;
            test1[1] = 2;
            test1[2] = 3;
            test1[3] = 4;
            test1[4] = 5;
            test1[5] = 6;  
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        std::cout << YELLOW "\nDEEP COPY TEST" RESET << std::endl;
        std::cout << PURPLE "copy constructor" RESET << std::endl;
        Array<int> test3(test1);
        std::cout << PURPLE "copy assignment operator" RESET << std::endl;
        test2 = test1;
        std::cout << PURPLE "values test1" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
            std::cout << test1[i] << std::endl;
        std::cout << PURPLE "values test2" RESET << std::endl;
        for (int i = 0; i < test2.size(); i++)
            std::cout << test2[i] << std::endl;
        std::cout << PURPLE "values test3" RESET << std::endl;
        for (int i = 0; i < test3.size(); i++)
            std::cout << test3[i] << std::endl;
        std::cout << PURPLE "change of values in test1" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
        {
            test1[i] = -1;
            std::cout << test1[i] << std::endl;
        }
        std::cout << PURPLE "values test2" RESET << std::endl;
        for (int i = 0; i < test2.size(); i++)
            std::cout << test2[i] << std::endl;
        std::cout << PURPLE "values test3" RESET << std::endl;
        for (int i = 0; i < test3.size(); i++)
            std::cout << test3[i] << std::endl;
        std::cout << PURPLE "Destructors" RESET << std::endl;
    }
    {
        std::cout << YELLOW "STRING Array test" RESET << std::endl;
        std::cout << PURPLE "Constructor with size" RESET << std::endl;
        Array<std::string> test1(5);
        std::cout << "size of test1: " << test1.size() << std::endl;
        std::cout << PURPLE "Default Constructor" RESET << std::endl;
        Array<std::string> test2;
        std::cout << "size of test2: " << test2.size() << std::endl;
        std::cout << PURPLE "Filling values + out of range test" RESET << std::endl;
        try
        {
            test1[0] = "value position 0";
            test1[1] = "value position 1";
            test1[2] = "value position 2";
            test1[3] = "value position 3";
            test1[4] = "value position 4";
            test1[5] = "value position 5"; 
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        std::cout << YELLOW "\nDEEP COPY TEST" RESET << std::endl;
        std::cout << PURPLE "copy constructor" RESET << std::endl;
        Array<std::string> test3(test1);
        std::cout << PURPLE "copy assignment operator" RESET << std::endl;
        test2 = test1;
        std::cout << PURPLE "values test1" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
            std::cout << test1[i] << std::endl;
        std::cout << PURPLE "values test2" RESET << std::endl;
        for (int i = 0; i < test2.size(); i++)
            std::cout << test2[i] << std::endl;
        std::cout << PURPLE "values test3" RESET << std::endl;
        for (int i = 0; i < test3.size(); i++)
            std::cout << test3[i] << std::endl;
        std::cout << PURPLE "change of values in test1" RESET << std::endl;
        for (int i = 0; i < test1.size(); i++)
        {
            test1[i] = "changed string";
            std::cout << test1[i] << std::endl;
        }
        std::cout << PURPLE "values test2" RESET << std::endl;
        for (int i = 0; i < test2.size(); i++)
            std::cout << test2[i] << std::endl;
        std::cout << PURPLE "values test3" RESET << std::endl;
        for (int i = 0; i < test3.size(); i++)
            std::cout << test3[i] << std::endl;
        std::cout << PURPLE "Destructors" RESET << std::endl;
    }
    return (0);
}