/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:43:23 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/10 20:06:58 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// It creates a zombie, name it,
// and the zombie announces itself.
// Calls Constructor
void randomChump(std::string name)
{
	Zombie z = Zombie(name);
	z.announce();
}
