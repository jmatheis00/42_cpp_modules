/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:40:32 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/02 15:08:40 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    {
        std::cout << YELLOW "\nTEST: NO HITPOINTS LEFT" RESET << std::endl;
        std::cout << PURPLE "Constructors" RESET<< std::endl;
        ClapTrap bobby("Bobby");
        ClapTrap other(bobby);
        ClapTrap diff;
        diff = bobby;
        std::cout << GREEN "Starting values" RESET << std::endl;
        std::cout << bobby << std::endl;
        std::cout << PURPLE "attack() function" RESET << std::endl;
        bobby.attack("Sammy");
        std::cout << bobby << std::endl;
        std::cout << PURPLE "beRepaired() function" RESET << std::endl;
        bobby.beRepaired(2);
        std::cout << bobby << std::endl;
        std::cout << PURPLE "takeDamage() function" RESET << std::endl;
        bobby.takeDamage(5);
        bobby.takeDamage(7);
        std::cout << PURPLE "Copy Test" RESET << std::endl;
        std::cout << GREEN "bobby (original Bobby)" RESET << std::endl;
        std::cout << bobby;
        std::cout << GREEN "other (Copy Constructor)" RESET << std::endl;
        std::cout << other;
        std::cout << GREEN "diff (Copy Assignment Operator)" RESET << std::endl;
        std::cout << diff;
        std::cout << PURPLE "ClapTrap is dead" RESET<< std::endl;
        bobby.takeDamage(5);
        bobby.beRepaired(3);
        bobby.attack("Sammy");
        std::cout << PURPLE "Destructors" RESET<< std::endl;
    }
    {
        std::cout << YELLOW "\nTEST: NO ENERGY POINTS LEFT" RESET << std::endl;
        std::cout << PURPLE "Constructors" RESET<< std::endl;
        ClapTrap sammy("Sammy");
        std::cout << sammy << std::endl;
        std::cout << PURPLE "attack() function" RESET << std::endl;
        for(int i = 0; i < 10; i++)
            sammy.attack("Lissy");
        std::cout << sammy << std::endl;
        std::cout << PURPLE "ClapTrap is dead" RESET<< std::endl;
        sammy.beRepaired(20);
        sammy.attack("Lissy");
        sammy.takeDamage(2);
        std::cout << PURPLE "Destructors" RESET<< std::endl;
    }
    return (0);
}