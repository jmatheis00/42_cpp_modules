/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:22 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:19:12 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"),
                             ScavTrap("Default_clap_name"), FragTrap("Default_clap_name")
{
    name_ = "Default";
    hitpoints_ = FragTrap::hitpoints_;
    energypoints_ = ScavTrap::get_energy();
    attackdamage_ = FragTrap::attackdamage_;
    std::cout << RED "Default DiamondTrap wakes up" RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
                                             ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
    name_ = name;
    hitpoints_ = FragTrap::hitpoints_;
    energypoints_ = ScavTrap::get_energy();
    attackdamage_ = FragTrap::attackdamage_;
    std::cout << RED "DiamondTrap named " << name_ << " wakes up" RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copyclass) : ClapTrap(copyclass),
                                                         ScavTrap(copyclass), FragTrap(copyclass)
{
    std::cout << "Copy Constructor DiamondTrap" << std::endl;
    DiamondTrap::operator=(copyclass);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copyop)
{
    name_ = copyop.get_name();
    hitpoints_ = copyop.get_hitpoints();
    energypoints_ = copyop.get_energypoints();
    attackdamage_ = copyop.get_attackdamage();
    std::cout << "Copy Assignment Operator DiamondTrap" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED "DiamondTrap named " << name_ << " dies" RESET << std::endl;
}

// GETTER FUNCTIONS

// OTHER MEMBER FUNCTIONS

// lose <attack damage> hit points
void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "ClapTrap name is " << ClapTrap::name_
              << " normal name is " << DiamondTrap::name_
              << std::endl;
}

std::string DiamondTrap::get_name() const
{
    return (name_);
}

// OUTPUT OPERATOR OVERLOADING
std::ostream &operator<<(std::ostream &os, const DiamondTrap &i)
{
    os << "NAME\t" << i.DiamondTrap::get_name() << std::endl;
    os << "HIT POINTS\t" << i.FragTrap::get_hitpoints() << std::endl;
    os << "ENERGY POINTS\t" << i.ScavTrap::get_energypoints() << std::endl;
    os << "ATTACK DAMAGE\t" << i.FragTrap::get_attackdamage() << std::endl;
    return (os);
}
