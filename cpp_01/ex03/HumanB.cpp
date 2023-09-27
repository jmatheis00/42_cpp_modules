/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:29:35 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:10:50 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weap_(NULL)
{
    std::cout << GREEN << name_ << " woke up" << RESET << std::endl;
}

HumanB::~HumanB()
{
    std::cout << GREEN << name_ << " fell asleep" << RESET << std::endl;
}

void HumanB::attack()
{
    if (weap_ != NULL)
        std::cout << RED << name_ << " attacks with " << weap_->getType() << RESET << std::endl;
    else
        std::cout << RED << name_ << " attacks without a weapon" << RESET << std::endl;
}

// Weapn* weap_ = Weapon &w --> address manipulation
void HumanB::setWeapon(Weapon &w)
{
    weap_ = &w;
    std::cout << name_ << " took weapon named " << weap_->getType() << std::endl;
}