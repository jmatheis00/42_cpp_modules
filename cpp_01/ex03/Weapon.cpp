/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:21:06 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/06 16:32:59 by jmatheis         ###   ########.fr       */
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

// need some address manipulation here
void Weapon::setType(std::string s)
{
    type_ = s;
}