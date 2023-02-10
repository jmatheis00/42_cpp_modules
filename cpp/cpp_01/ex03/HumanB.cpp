/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:29:35 by jmatheis          #+#    #+#             */
/*   Updated: 2023/02/08 11:35:26 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    name_ = name;
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
    std::cout << name_ << " attacks with their" << std::endl;
}