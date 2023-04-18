/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:31:24 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/18 15:08:37 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */

// INHERITED FROM CLAPTRAP
// constructors & destructor
// constructor desctrucor and attack prints different messages
// uses attributes of ClapTrap
// new function: void guardGate();
class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(); //Default Constructor
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copyclass); //Copy Constructor
		ScavTrap& operator= (const ScavTrap& copyop); //copy assignment operator
		~ScavTrap(); //Destructor

        void attack(const std::string& target); //overwritten
        void guardGate();
};

std::ostream& operator<<(std::ostream& os, const ScavTrap& i);

#endif