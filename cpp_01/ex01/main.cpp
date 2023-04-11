/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:46:09 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/10 20:22:26 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// zombieHorde calls Constructor
// delete[] calls Destructor for an array of objects
int main(void)
{
	int	no;

	no = 7;
	std::cout << GREEN << "\nzombieHorde Test\n" << RESET;
	Zombie *example = zombieHorde(no, "Foo1");
    if (!example)
	{
		std::cout << "Allocation fail" << std::endl;
		return (1);
	}
	for (int i = 0; i < no; i++)
		example[i].announce();

	delete[] example;
	return (0);
}