/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/27 13:28:12 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    {
        std::cout << YELLOW "\nTEST: SCAVTRAP" RESET << std::endl;
        std::cout << PURPLE "Constructors" RESET<< std::endl;
        ScavTrap second("Sammy");
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << second << std::endl;   
        std::cout << PURPLE "attack() function" RESET << std::endl;    
        second.attack("OTHER");
        std::cout << PURPLE "takeDamage() function" RESET << std::endl;    
        second.takeDamage(20);
        std::cout << PURPLE "beRepaired() function" RESET << std::endl;
        second.beRepaired(5);
        std::cout << PURPLE "guardGate() function" RESET << std::endl;
        second.guardGate();
        std::cout << PURPLE "takeDamage() function" RESET << std::endl;    
        second.takeDamage(85);
        std::cout << second << std::endl;
        std::cout << PURPLE "ScavTrap is dead" RESET<< std::endl;
        second.beRepaired(10);
        second.takeDamage(10);
        second.attack("OTHER");
        std::cout << PURPLE "Destructors" RESET<< std::endl;
    }
    // {
    //     std::cout << YELLOW "\nTEST: CLAPTRAP" RESET << std::endl;
    //     std::cout << PURPLE "Constructors" RESET<< std::endl;
    //     ClapTrap first("Bobby");
    //     std::cout << GREEN "Starting values" RESET << std::endl;
    //     std::cout << first << std::endl;
    //     std::cout << PURPLE "attack() function" RESET << std::endl;
    //     first.attack("Sammy");
    //     std::cout << first << std::endl;
    //     std::cout << PURPLE "beRepaired() function" RESET << std::endl;
    //     first.beRepaired(2);
    //     std::cout << first << std::endl;
    //     std::cout << PURPLE "takeDamage() function" RESET << std::endl;
    //     first.takeDamage(5);
    //     first.takeDamage(7);
    //     std::cout << first << std::endl;
    //     std::cout << PURPLE "ClapTrap is dead" RESET<< std::endl;
    //     first.takeDamage(5);
    //     first.beRepaired(3);
    //     first.attack("Sammy");
    //     std::cout << PURPLE "Destructors" RESET<< std::endl;
    // }
    return (0);
}