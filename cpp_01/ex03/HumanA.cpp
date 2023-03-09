/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:02 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/09 15:53:31 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

// set w_ address to new w address --> initialize reference
HumanA::HumanA(std::string name, Weapon& w) : name_(name), w_(w)
{
    std::cout << GREEN << name_ << " woke up with weapon named " << w_.getType() << RESET << std::endl;
}

HumanA::~HumanA()
{
    std::cout << GREEN << name_ << " fell asleep" << RESET << std::endl;
}

void HumanA::attack()
{
    std::cout << RED << name_ << " attacks with " << w_.getType() << RESET << std::endl;
}