/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:46:09 by jmatheis          #+#    #+#             */
/*   Updated: 2023/02/07 21:18:59 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	// NEW ZOMBIE: new() --> allocated on HEAP
	// We want to use Zombie outside of the function
	std::cout << GREEN << "\nnewZombie Test\n" << RESET;
	Zombie *example = newZombie("Foo1"); //calls Constructor
    if (!example)
	{
		std::cout << "Allocation fail" << std::endl;
		return (1);
	}
	example->announce();
	delete example; // calls Destructor

	// random Chump: NOT allocated --> on STACK
	std::cout << GREEN << "\nrandomChump Test\n" << RESET;
	randomChump("Foo2");
	std::cout << std::endl;
	//Destructor for not allocated Zombie automatically called when main function returns
	return (0);
}