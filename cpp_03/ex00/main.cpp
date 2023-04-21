/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/21 10:44:46 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    {
        std::cout << YELLOW "\nTEST: NO HITPOINTS LEFT" RESET << std::endl;
        std::cout << PURPLE "Constructors" RESET<< std::endl;
        ClapTrap first("Bobby");
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << first << std::endl;
        std::cout << PURPLE "attack() function" RESET << std::endl;
        first.attack("Sammy");
        std::cout << first << std::endl;
        std::cout << PURPLE "beRepaired() function" RESET << std::endl;
        first.beRepaired(2);
        std::cout << first << std::endl;
        std::cout << PURPLE "takeDamage() function" RESET << std::endl;
        first.takeDamage(5);
        first.takeDamage(7);
        std::cout << first << std::endl;
        std::cout << PURPLE "ClapTrap is dead" RESET<< std::endl;
        first.takeDamage(5);
        first.beRepaired(3);
        first.attack("Sammy");
        std::cout << PURPLE "Destructors" RESET<< std::endl;
    }
    {
        std::cout << YELLOW "\nTEST: NO ENERGY POINTS LEFT" RESET << std::endl;
        std::cout << PURPLE "Constructors" RESET<< std::endl;
        ClapTrap second("Sammy");
        std::cout << second << std::endl;
        std::cout << PURPLE "attack() function" RESET << std::endl;
        for(int i = 0; i < 10; i++)
            second.attack("Lissy");
        std::cout << second << std::endl;
        std::cout << PURPLE "ClapTrap is dead" RESET<< std::endl;
        second.beRepaired(20);
        second.attack("Lissy");
        second.takeDamage(2);
        std::cout << PURPLE "Destructors" RESET<< std::endl;
    }
    return (0);
}