/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:46:09 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/12 14:19:17 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// NEW ZOMBIE: new() --> allocated on HEAP
// We want to use Zombie outside of the function
// random Chump: NOT allocated --> on STACK
//Destructor for Zombie "on Stack" automatically called
int main(void)
{
	std::cout << GREEN << "\nnewZombie Test\n" << RESET;
	Zombie *example = newZombie("Foo1");
	example->announce();
	delete example;

	std::cout << GREEN << "\nrandomChump Test\n" << RESET;
	randomChump("Foo2");
	std::cout << std::endl;
	return (0);
}