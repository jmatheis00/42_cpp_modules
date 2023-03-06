/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:02 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/06 16:28:45 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon w)
{
    name_ = name;
    w_ = &w;
    std::cout << name_ << " woke up with weapon named " << w_->getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << name_ << " fell asleep" << std::endl;
}

void HumanA::attack()
{
    std::cout << name_ << " attacks with " << w_->getType() << std::endl;
}