/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:43:23 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/12 13:48:28 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name)
{
	std::string n;
	Zombie *z = NULL;
	n = name;
	// z->_name = name;
	return (z);
}
// It creates a zombie, name it,
// and return it so you can use it outside of the function scope.