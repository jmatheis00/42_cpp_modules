/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:50:27 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:19:50 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    name_ = "Default";
    hitpoints_ = 100;
    energypoints_ = 50;
    energy_ = energypoints_;
    attackdamage_ = 20;
    std::cout << RED "Default ScavTrap wakes up" RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    name_ = name;
    hitpoints_ = 100;
    energypoints_ = 50;
    energy_ = energypoints_;
    attackdamage_ = 20;
    std::cout << RED "ScavTrap with name " << name << " wakes up" RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copyclass) : ClapTrap(copyclass)
{
    std::cout << "Copy Constructor ScavTrap" << std::endl;
    ScavTrap::operator=(copyclass);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copyop)
{
    name_ = copyop.get_name();
    hitpoints_ = copyop.get_hitpoints();
    energypoints_ = copyop.get_energypoints();
    attackdamage_ = copyop.get_attackdamage();
    std::cout << "Copy Assignment Operator ScavTrap" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << RED "ScavTrap named " << name_ << " dies" RESET << std::endl;
}

// lose <attack damage> hit points
void ScavTrap::attack(const std::string &target)
{
    if (energypoints_ > 0 && hitpoints_ > 0)
    {
        std::cout << "ScavTrap " << get_name() << " attacks "
                  << target << ", causing " << get_attackdamage() << " points of damage!" << std::endl;
        energypoints_--;
    }
    else if (energypoints_ == 0)
        std::cout << RED "ScavTrap " << get_name() << " has no energy left, cannot attack someone else!" RESET << std::endl;
    else if (hitpoints_ <= 0)
        std::cout << RED "ScavTrap " << get_name() << " already died, cannot attack someone else!" RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap named " << get_name() << " is now in Gate keeper mode." << std::endl;
}

int ScavTrap::get_energy()
{
    return (energy_);
}

// OUTPUT OPERATOR OVERLOADING
std::ostream &operator<<(std::ostream &os, const ScavTrap &i)
{
    os << "NAME\t\t" << i.get_name() << std::endl;
    os << "HIT POINTS\t" << i.get_hitpoints() << std::endl;
    os << "ENERGY POINTS\t" << i.get_energypoints() << std::endl;
    os << "ATTACK DAMAGE\t" << i.get_attackdamage() << std::endl;
    return (os);
}
