/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:22 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/18 22:33:42 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap()
{
    ClapTrap::name_ = "Default_clap_name";
    name_ = "Default";
    hitpoints_ = FragTrap::hitpoints_;
    ScavTrap::energypoints_ = 50;
    energypoints_ = ScavTrap::energypoints_;
    attackdamage_ = FragTrap::attackdamage_;
    std::cout << RED "Default DiamondTrap wakes up"  RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    ClapTrap::name_ = name + "_clap_name";
    name_ = name;
    hitpoints_ = FragTrap::hitpoints_;
    ScavTrap::energypoints_ = 50;
    energypoints_ = ScavTrap::energypoints_;
    attackdamage_ = FragTrap::attackdamage_;
    std::cout << RED "DiamondTrap named " << name_ << " wakes up"  RESET << std::endl;
    std::cout << attackdamage_ << std::endl;
    std::cout << FragTrap::get_attackdamage() << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copyclass)
{
    DiamondTrap::operator= (copyclass);
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& copyop)
{
    name_ = copyop.get_name();
    hitpoints_ = copyop.get_hitpoints();
    energypoints_ = copyop.get_energypoints();
    attackdamage_ = copyop.get_attackdamage();

    return(*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED "DiamondTrap named " << name_ << " dies" RESET << std::endl;
}


// GETTER FUNCTIONS

// OTHER MEMBER FUNCTIONS
// DiamondTrap can't do anything if it has no hit points or energy points left

// lose <attack damage> hit points
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << YELLOW "ClapTrap name is " << ClapTrap::get_name()
        << " normal name is " << DiamondTrap::name_
        << RESET << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const DiamondTrap& i)
{
	os << "CLAPTRAP NAME\t" << i.ClapTrap::get_name() << std::endl;
    os << "HIT POINTS\t" << i.FragTrap::get_hitpoints() << std::endl;
    os << "ENERGY POINTS\t" << i.ScavTrap::get_energypoints() << std::endl;
    os << "ATTACK DAMAGE\t" << i.FragTrap::get_attackdamage() << std::endl;
	return (os);
}
