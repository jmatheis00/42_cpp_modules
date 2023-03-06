/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:46:09 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/06 15:37:57 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int	no;

	no = 10;
	std::cout << GREEN << "\nzombieHorde Test\n" << RESET;
	Zombie *example = zombieHorde(no, "Foo1"); //calls Constructor
    if (!example)
	{
		std::cout << "Allocation fail" << std::endl;
		return (1);
	}
	for (int i = 0; i < no; i++)
	{
		example[i].announce();
	}
	delete[] example; // calls Destructor for an array of objects
	return (0);
}