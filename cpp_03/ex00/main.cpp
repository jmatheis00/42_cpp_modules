/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/24 21:16:04 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap ex1("ex1");

    std::cout << GREEN "Starting values" RESET << std::endl;
    std::cout << ex1 << std::endl;
    std::cout << GREEN "TEST: NO HITPOINTS" RESET << std::endl;
    ex1.attack("test");
    std::cout << ex1 << std::endl;
    ex1.takeDamage(5);
    std::cout << ex1 << std::endl;
    ex1.takeDamage(5);
    std::cout << ex1 << std::endl;
    ex1.takeDamage(5);
    std::cout << GREEN "TEST: NO ENERGY" RESET << std::endl;
    ClapTrap ex2("ex2");
    std::cout << ex2 << std::endl;
    for(int i = 0; i < 10; i++)
        ex2.attack("TEST2");
    std::cout << ex2 << std::endl;
    ex2.beRepaired(20);
    std::cout << ex2 << std::endl;
    // std::cout << example << std::endl;
    // example.beRepaired(2);
    // std::cout << example << std::endl;
    // example.takeDamage(8);
    // std::cout << example << std::endl;
    // example.attack("TREE");
    // std::cout << example << std::endl;

}