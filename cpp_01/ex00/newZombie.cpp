/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:43:23 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/06 15:21:19 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// It creates a zombie, name it,
// and return it so you can use it outside of the function scope.
Zombie* newZombie(std::string name)
{
	Zombie *z = new Zombie(name);
	if (!z)
	{
		std::cout << "Allocation of newZombie failed" << std::endl;
		return (NULL);
	}
	return (z);
}