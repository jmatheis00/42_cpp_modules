/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:21:06 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:11:14 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType()
{
    return (type_);
}

// value change of type_
void Weapon::setType(std::string newweapon)
{
    type_ = newweapon;
    std::cout << "Weapon type changed to " << type_ << std::endl;
}