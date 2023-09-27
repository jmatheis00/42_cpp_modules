/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:28:01 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:15:29 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("Default"),
                       hitpoints_(10), energypoints_(10), attackdamage_(0)
{
    std::cout << RED "Default ClapTrap wakes up" RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name),
                                       hitpoints_(10), energypoints_(10), attackdamage_(0)
{
    std::cout << RED "ClapTrap named " << name_ << " wakes up" RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copyclass)
{
    std::cout << "Copy Constructor ClapTrap" << std::endl;
    ClapTrap::operator=(copyclass);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copyop)
{
    name_ = copyop.get_name();
    hitpoints_ = copyop.get_hitpoints();
    energypoints_ = copyop.get_energypoints();
    attackdamage_ = copyop.get_attackdamage();
    std::cout << "Copy Assignment Operator ClapTrap" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << RED "ClapTrap named " << name_ << " dies" RESET << std::endl;
}

// GETTER FUNCTIONS
std::string ClapTrap::get_name() const
{
    return (name_);
}

int ClapTrap::get_hitpoints() const
{
    return (hitpoints_);
}

int ClapTrap::get_energypoints() const
{
    return (energypoints_);
}

int ClapTrap::get_attackdamage() const
{
    return (attackdamage_);
}

// OTHER MEMBER FUNCTIONS

// lose <attack damage> hit points
void ClapTrap::attack(const std::string &target)
{
    if (energypoints_ > 0 && hitpoints_ > 0)
    {
        std::cout << "ClapTrap " << get_name() << " attacks "
                  << target << ", causing " << get_attackdamage() << " points of damage!" << std::endl;
        energypoints_--;
    }
    else if (energypoints_ <= 0)
        std::cout << RED "ClapTrap " << get_name() << " has no energy left, cannot attack someone else!" RESET << std::endl;
    else if (hitpoints_ <= 0)
        std::cout << RED "ClapTrap " << get_name() << " already died, cannot attack someone else!" RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitpoints_ > 0 && energypoints_ > 0)
    {
        std::cout << "ClapTrap " << get_name() << " got attacked, gets "
                  << amount << " points of damage!" << std::endl;
        hitpoints_ -= amount;
    }
    else
        std::cout << RED "ClapTrap " << get_name() << " already died, cannot take damage anymore!" RESET << std::endl;
}

// gets <amount> hit points back
void ClapTrap::beRepaired(unsigned int amount)
{
    if (energypoints_ > 0 && hitpoints_ > 0)
    {
        std::cout << "ClapTrap " << get_name() << " repairs itself with "
                  << amount << " points!" << std::endl;
        hitpoints_ += amount;
        energypoints_--;
    }
    else if (energypoints_ == 0)
        std::cout << RED "ClapTrap " << get_name() << " has no energy left, cannot repair itself!" RESET << std::endl;
    else if (hitpoints_ <= 0)
        std::cout << RED "ClapTrap " << get_name() << " already died, cannot repair itself!" RESET << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream &operator<<(std::ostream &os, const ClapTrap &i)
{
    os << "NAME\t\t" << i.get_name() << std::endl;
    os << "HIT POINTS\t" << i.get_hitpoints() << std::endl;
    os << "ENERGY POINTS\t" << i.get_energypoints() << std::endl;
    os << "ATTACK DAMAGE\t" << i.get_attackdamage() << std::endl;
    return (os);
}
