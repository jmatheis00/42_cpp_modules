/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:56:26 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/06 15:38:16 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor
Zombie::Zombie()
{
	std::cout << "Created new Zombie member of a horde" << _name << std::endl;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << "Destroyed Zombie named: " << _name << std::endl;
}

void	Zombie::set_name(std::string s)
{
	_name = s;
}

// Zombie announcement
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
