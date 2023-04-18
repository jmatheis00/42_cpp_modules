/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:50:27 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/17 19:15:54 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    name_ = "Default";
    hitpoints_ = 100;
    energypoints_ = 100;
    attackdamage_ = 30;
    std::cout << RED "Default FragTrap wakes up"  RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    name_ = name;
    hitpoints_ = 100;
    energypoints_ = 100;
    attackdamage_ = 30;
    std::cout << RED "FragTrap with name " << name << " wakes up"  RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copyclass): ClapTrap(copyclass)
{
    FragTrap::operator= (copyclass);
}

FragTrap& FragTrap::operator= (const FragTrap& copyop)
{
    name_ = copyop.get_name();
    hitpoints_ = copyop.get_hitpoints();
    energypoints_ = copyop.get_energypoints();
    attackdamage_ = copyop.get_attackdamage();
    return(*this);
}

FragTrap::~FragTrap()
{
    std::cout << RED "FragTrap named " << name_ << " dies" RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << GREEN "HIGH FIVES GUYS!" RESET << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const FragTrap& i)
{
	os << "NAME\t\t" << i.get_name() << std::endl;
    os << "HIT POINTS\t" << i.get_hitpoints() << std::endl;
    os << "ENERGY POINTS\t" << i.get_energypoints() << std::endl;
    os << "ATTACK DAMAGE\t" << i.get_attackdamage() << std::endl;
	return (os);
}
