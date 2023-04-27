/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/27 10:10:30 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

// virtual inheritance (Frag- & ScavTrap)
// avoiding Diamond having two copies of same functions/attributes
int main(void)
{
    {
        std::cout << YELLOW "\nTEST: DIAMONDTRAP" RESET << std::endl;
        std::cout << PURPLE "Constructors" RESET<< std::endl;
        DiamondTrap other("Danny");
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << other << std::endl;    
        std::cout << PURPLE "attack() function" RESET<< std::endl;
        other.attack("OTHER");
        std::cout << PURPLE "takeDamage() function" RESET<< std::endl;    
        other.takeDamage(20);
        std::cout << PURPLE "beRepaired() function" RESET<< std::endl;       
        other.beRepaired(5);
        std::cout << PURPLE "whoAmI() function" RESET<< std::endl;    
        other.whoAmI();
        std::cout << PURPLE "guardGate() function" RESET<< std::endl;    
        other.guardGate();
        std::cout << PURPLE "highFivesGuys() function" RESET<< std::endl;    
        other.highFivesGuys();
        std::cout << PURPLE "takeDamage() function" RESET<< std::endl;
        other.takeDamage(85);
        std::cout << other << std::endl;
        std::cout << PURPLE "DiamondTrap() is dead" RESET<< std::endl;
        other.beRepaired(10);
        other.takeDamage(10);
        other.attack("OTHER");
        std::cout << PURPLE "Destructors" RESET<< std::endl;
    }
    // {
    //     std::cout << YELLOW "\nTEST: FRAGTRAP" RESET << std::endl;
    //     std::cout << PURPLE "Constructors" RESET<< std::endl;
    //     FragTrap third("Tommy");
    //     std::cout << GREEN "Starting values" RESET << std::endl;
    //     std::cout << third << std::endl;
    //     std::cout << PURPLE "attack() function" RESET<< std::endl;    
    //     third.attack("OTHER");
    //     std::cout << PURPLE "takeDamage() function" RESET<< std::endl;    
    //     third.takeDamage(20);
    //     std::cout << PURPLE "beRepaired() function" RESET<< std::endl;    
    //     third.beRepaired(5);
    //     std::cout << PURPLE "highFivesGuys() function" RESET<< std::endl;    
    //     third.highFivesGuys();
    //     std::cout << PURPLE "takeDamage() function" RESET<< std::endl;
    //     third.takeDamage(85);
    //     std::cout << third << std::endl;
    //     std::cout << PURPLE "ScavTrap() is dead" RESET<< std::endl;
    //     third.beRepaired(10);
    //     third.takeDamage(10);
    //     third.attack("OTHER");
    //     std::cout << PURPLE "Destructors" RESET<< std::endl;
    // }
    //   {
    //     std::cout << YELLOW "\nTEST: SCAVTRAP" RESET << std::endl;
    //     std::cout << PURPLE "Constructors" RESET<< std::endl;
    //     ScavTrap second("Sammy");
    //     std::cout << GREEN "Starting values" RESET << std::endl;
    //     std::cout << second << std::endl;   
    //     std::cout << PURPLE "attack() function" RESET << std::endl;    
    //     second.attack("OTHER");
    //     std::cout << PURPLE "takeDamage() function" RESET << std::endl;    
    //     second.takeDamage(20);
    //     std::cout << PURPLE "beRepaired() function" RESET << std::endl;
    //     second.beRepaired(5);
    //     std::cout << PURPLE "guardGate() function" RESET << std::endl;
    //     second.guardGate();
    //     std::cout << PURPLE "takeDamage() function" RESET << std::endl;    
    //     second.takeDamage(85);
    //     std::cout << second << std::endl;
    //     std::cout << PURPLE "ScavTrap is dead" RESET<< std::endl;
    //     second.beRepaired(10);
    //     second.takeDamage(10);
    //     second.attack("OTHER");
    //     std::cout << PURPLE "Destructors" RESET<< std::endl;
    // }
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