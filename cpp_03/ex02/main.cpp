/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/17 19:12:13 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    {
        std::cout << YELLOW "\nTEST: FRAGTRAP" RESET << std::endl;
        FragTrap third("Tommy");
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << third << std::endl;        
        third.attack("OTHER");
        third.takeDamage(20);
        third.beRepaired(5);
        third.highFivesGuys();
        third.takeDamage(100);
        
        std::cout << third << std::endl;
        third.beRepaired(10);
        third.takeDamage(10);
        third.attack("OTHER");
    }
    {
        std::cout << YELLOW "\nTEST: SCAVTRAP" RESET << std::endl;
        ScavTrap second("Sammy");
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << second << std::endl;        
        second.attack("OTHER");
        second.takeDamage(20);
        second.beRepaired(5);
        second.guardGate();
        second.takeDamage(100);
        
        std::cout << second << std::endl;
        second.beRepaired(10);
        second.takeDamage(10);
        second.attack("OTHER");
    }
    {
        std::cout << YELLOW "\nTEST: CLAPTRAP" RESET << std::endl;
        ClapTrap first("Bobby");
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << first << std::endl;
        first.attack("Sammy");
        std::cout << first << std::endl;
        first.takeDamage(5);
        first.beRepaired(1);
        std::cout << first << std::endl;
        first.takeDamage(6);
        std::cout << first << std::endl;
        first.takeDamage(5);
        first.beRepaired(3);
        first.attack("Sammy");
    }
    return (0);
}