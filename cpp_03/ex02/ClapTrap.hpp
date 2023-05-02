/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:56:41 by jmatheis          #+#    #+#             */
/*   Updated: 2023/05/02 17:03:14 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RESET       "\033[0m"               /* Reset */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define PURPLE      "\033[35m"              /* Purple */

class ClapTrap
{
    protected:
        std::string name_;
        int hitpoints_;
        int energypoints_;
        int attackdamage_;
    public:
        ClapTrap(); //Default Constructor
		ClapTrap(std::string name); 
		ClapTrap(const ClapTrap &copyclass); //Copy Constructor
		ClapTrap& operator= (const ClapTrap& copyop); //copy assignment operator
		virtual ~ClapTrap(); //Destructor
    
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string get_name() const;
        int get_hitpoints() const;
        int get_energypoints() const;
        int get_attackdamage() const;
};

// OUTSTREAM OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& os, const ClapTrap& i);

#endif