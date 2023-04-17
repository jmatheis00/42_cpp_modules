/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/16 13:05:59 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    {
        std::cout << YELLOW "\nTEST: NO HITPOINTS LEFT" RESET << std::endl;
        ClapTrap first("Bobby");
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << first << std::endl;
        first.attack("Sammy");
        std::cout << first << std::endl;
        first.takeDamage(5);
        std::cout << first << std::endl;
        first.takeDamage(5);
        std::cout << first << std::endl;
        first.takeDamage(5);
        first.beRepaired(3);
        first.attack("Sammy");
    }
    {
        std::cout << YELLOW "\nTEST: NO ENERGY POINTS LEFT" RESET << std::endl;
        ClapTrap second("Sammy");
        std::cout << second << std::endl;
        for(int i = 0; i < 10; i++)
            second.attack("Lissy");
        std::cout << "\n" << second << std::endl;
        second.beRepaired(20);
        second.attack("Lissy");
        second.takeDamage(2);
    }
    return (0);
}