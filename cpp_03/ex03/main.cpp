/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:19:40 by jmatheis         ###   ########.fr       */
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
        std::cout << PURPLE "Constructors" RESET << std::endl;
        DiamondTrap danny("Danny");
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << danny << std::endl;
        std::cout << PURPLE "attack() function" RESET << std::endl;
        danny.attack("other");
        std::cout << PURPLE "takeDamage() function" RESET << std::endl;
        danny.takeDamage(20);
        std::cout << PURPLE "beRepaired() function" RESET << std::endl;
        danny.beRepaired(5);
        std::cout << PURPLE "whoAmI() function" RESET << std::endl;
        danny.whoAmI();
        std::cout << PURPLE "guardGate() function" RESET << std::endl;
        danny.guardGate();
        std::cout << PURPLE "highFivesGuys() function" RESET << std::endl;
        danny.highFivesGuys();
        std::cout << PURPLE "takeDamage() function" RESET << std::endl;
        danny.takeDamage(85);
        std::cout << danny << std::endl;
        std::cout << PURPLE "DiamondTrap() is dead" RESET << std::endl;
        danny.beRepaired(10);
        danny.takeDamage(10);
        danny.attack("other");
        std::cout << PURPLE "Destructors" RESET << std::endl;
    }
    // TESTS FROM PREVIOUS EXERCISES
    // {
    //     std::cout << YELLOW "\nTEST: FRAGTRAP" RESET << std::endl;
    //     std::cout << PURPLE "Constructors" RESET<< std::endl;
    //     FragTrap tommy("Tommy");
    //     FragTrap other(tommy);
    //     FragTrap diff;
    //     diff = tommy;
    //     std::cout << GREEN "Starting values" RESET << std::endl;
    //     std::cout << tommy << std::endl;
    //     std::cout << PURPLE "attack() function" RESET<< std::endl;
    //     tommy.attack("OTHER");
    //     std::cout << PURPLE "takeDamage() function" RESET<< std::endl;
    //     tommy.takeDamage(20);
    //     std::cout << PURPLE "beRepaired() function" RESET<< std::endl;
    //     tommy.beRepaired(5);
    //     std::cout << PURPLE "highFivesGuys() function" RESET<< std::endl;
    //     tommy.highFivesGuys();
    //     std::cout << PURPLE "takeDamage() function" RESET<< std::endl;
    //     tommy.takeDamage(85);
    //     std::cout << PURPLE "Copy Test" RESET << std::endl;
    //     std::cout << GREEN "sammy (original Sammy)" RESET << std::endl;
    //     std::cout << tommy;
    //     std::cout << GREEN "other (Copy Constructor)" RESET << std::endl;
    //     std::cout << other;
    //     std::cout << GREEN "diff (Copy Assignment Operator)" RESET << std::endl;
    //     std::cout << diff;
    //     std::cout << PURPLE "ScavTrap() is dead" RESET<< std::endl;
    //     tommy.beRepaired(10);
    //     tommy.takeDamage(10);
    //     tommy.attack("OTHER");
    //     std::cout << PURPLE "Destructors" RESET<< std::endl;
    // }
    // {
    //     std::cout << YELLOW "\nTEST: SCAVTRAP" RESET << std::endl;
    //     std::cout << PURPLE "Constructors" RESET<< std::endl;
    //     ScavTrap sammy("Sammy");
    //     ScavTrap other(sammy);
    //     ScavTrap diff;
    //     diff = sammy;
    //     std::cout << GREEN "Starting values" RESET << std::endl;
    //     std::cout << sammy << std::endl;
    //     std::cout << PURPLE "attack() function" RESET << std::endl;
    //     sammy.attack("OTHER");
    //     std::cout << PURPLE "takeDamage() function" RESET << std::endl;
    //     sammy.takeDamage(20);
    //     std::cout << PURPLE "beRepaired() function" RESET << std::endl;
    //     sammy.beRepaired(5);
    //     std::cout << PURPLE "guardGate() function" RESET << std::endl;
    //     sammy.guardGate();
    //     std::cout << PURPLE "takeDamage() function" RESET << std::endl;
    //     sammy.takeDamage(85);
    //     std::cout << PURPLE "Copy Test" RESET << std::endl;
    //     std::cout << GREEN "sammy (original Bobby)" RESET << std::endl;
    //     std::cout << sammy;
    //     std::cout << GREEN "other (Copy Constructor)" RESET << std::endl;
    //     std::cout << other;
    //     std::cout << GREEN "diff (Copy Assignment Operator)" RESET << std::endl;
    //     std::cout << diff;
    //     std::cout << PURPLE "ScavTrap is dead" RESET<< std::endl;
    //     sammy.beRepaired(10);
    //     sammy.takeDamage(10);
    //     sammy.attack("OTHER");
    //     std::cout << PURPLE "Destructors" RESET<< std::endl;
    // }
    // {
    //     std::cout << YELLOW "\nTEST: CLAPTRAP" RESET << std::endl;
    //     std::cout << PURPLE "Constructors" RESET<< std::endl;
    //     ClapTrap bobby("Bobby");
    //     ClapTrap other(bobby);
    //     ClapTrap diff;
    //     diff = bobby;
    //     std::cout << GREEN "Starting values" RESET << std::endl;
    //     std::cout << bobby << std::endl;
    //     std::cout << PURPLE "attack() function" RESET << std::endl;
    //     bobby.attack("Sammy");
    //     std::cout << bobby << std::endl;
    //     std::cout << PURPLE "beRepaired() function" RESET << std::endl;
    //     bobby.beRepaired(2);
    //     std::cout << bobby << std::endl;
    //     std::cout << PURPLE "takeDamage() function" RESET << std::endl;
    //     bobby.takeDamage(5);
    //     bobby.takeDamage(7);
    //     std::cout << PURPLE "Copy Test" RESET << std::endl;
    //     std::cout << GREEN "bobby (original Bobby)" RESET << std::endl;
    //     std::cout << bobby;
    //     std::cout << GREEN "other (Copy Constructor)" RESET << std::endl;
    //     std::cout << other;
    //     std::cout << GREEN "diff (Copy Assignment Operator)" RESET << std::endl;
    //     std::cout << diff;
    //     std::cout << PURPLE "ClapTrap is dead" RESET<< std::endl;
    //     bobby.takeDamage(5);
    //     bobby.beRepaired(3);
    //     bobby.attack("Sammy");
    //     std::cout << PURPLE "Destructors" RESET<< std::endl;
    // }
    return (0);
}