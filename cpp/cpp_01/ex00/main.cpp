/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:46:09 by jmatheis          #+#    #+#             */
/*   Updated: 2023/01/12 13:54:32 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie z;
	std::string name = "Foo";

	std::cout << GREEN << "\nannounce Test\n" << RESET;
	z.announce();
	
	std::cout << GREEN << "\n\nnewZombie Test\n" << RESET;
	
	std::cout << GREEN << "\n\nrandomChump Test\n" << RESET;
	randomChump(name);

	return (0);
}