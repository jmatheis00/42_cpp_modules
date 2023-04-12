/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:56:26 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/12 13:59:38 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor
Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Created new Zombie named: " << _name << std::endl;
}

// Deconstructor
Zombie::~Zombie()
{
	std::cout << "Destroyed Zombie named: " << _name << std::endl;
}

// Zombie announcement
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
