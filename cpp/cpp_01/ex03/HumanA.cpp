/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:02 by jmatheis          #+#    #+#             */
/*   Updated: 2023/02/10 01:32:24 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon w)
{
    name_ = name;
    w_ = &w;
    std::cout << "This is " << w_->getType() << std::endl;
}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
    std::cout << name_ << " attacks with their" << w_->getType() << std::endl;
}