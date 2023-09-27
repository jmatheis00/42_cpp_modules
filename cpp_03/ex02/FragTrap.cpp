/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:50:27 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:18:01 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
{
    name_ = "Default";
    hitpoints_ = 100;
    energypoints_ = 100;
    attackdamage_ = 30;
    std::cout << RED "Default FragTrap wakes up" RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    name_ = name;
    hitpoints_ = 100;
    energypoints_ = 100;
    attackdamage_ = 30;
    std::cout << RED "FragTrap with name " << name << " wakes up" RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copyclass) : ClapTrap(copyclass)
{
    std::cout << "Copy Constructor FragTrap" << std::endl;
    FragTrap::operator=(copyclass);
}

FragTrap &FragTrap::operator=(const FragTrap &copyop)
{
    name_ = copyop.get_name();
    hitpoints_ = copyop.get_hitpoints();
    energypoints_ = copyop.get_energypoints();
    attackdamage_ = copyop.get_attackdamage();
    std::cout << "Copy Assignment Operator FragTrap" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << RED "FragTrap named " << name_ << " dies" RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "HIGH FIVES GUYS!" << std::endl;
}

// OUTPUT OPERATOR OVERLOADING
std::ostream &operator<<(std::ostream &os, const FragTrap &i)
{
    os << "NAME\t\t" << i.get_name() << std::endl;
    os << "HIT POINTS\t" << i.get_hitpoints() << std::endl;
    os << "ENERGY POINTS\t" << i.get_energypoints() << std::endl;
    os << "ATTACK DAMAGE\t" << i.get_attackdamage() << std::endl;
    return (os);
}
