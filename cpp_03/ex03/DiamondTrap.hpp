/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:26 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/18 16:19:08 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */

// INHERITED FROM CLAPTRAP
// constructors & destructor
// constructor desctrucor and attack prints different messages
// uses attributes of ClapTrap
// new function: void guardGate();
class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap(); //Default Constructor
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copyclass); //Copy Constructor
		DiamondTrap& operator= (const DiamondTrap& copyop); //copy assignment operator
		~DiamondTrap(); //Destructor

        void attack(const std::string& target); //overwritten
		void whoAmI();
	private:
		std::string name_;
};

std::ostream& operator<<(std::ostream& os, const DiamondTrap& i);

#endif