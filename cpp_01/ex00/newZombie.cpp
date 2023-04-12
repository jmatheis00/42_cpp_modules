/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:43:23 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/12 14:19:26 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// It creates a zombie, name it,
// and return it so you can use it outside of the function scope.
Zombie* newZombie(std::string name)
{
	Zombie *z = new Zombie(name);
	return (z);
}