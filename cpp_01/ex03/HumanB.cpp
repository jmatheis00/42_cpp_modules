/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:29:35 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/06 16:27:54 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    name_ = name;
    hasweapon_ = 0;
    std::cout << name_ << " woke up" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << name_ << " fell asleep" << std::endl;
}

void HumanB::attack()
{
    if (hasweapon_ == 1)
        std::cout << name_ << " attacks with " << weap_->getType() << std::endl;
    else
        std::cout << name_ << " attacks without a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon w)
{
    weap_ = &w;
    hasweapon_ = 1;
}