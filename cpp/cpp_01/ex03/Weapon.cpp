/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:21:06 by jmatheis          #+#    #+#             */
/*   Updated: 2023/02/08 11:20:20 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    setType(type);
}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType()
{
    return (type_);
}

void Weapon::setType(std::string s)
{
    type_ = s;
}