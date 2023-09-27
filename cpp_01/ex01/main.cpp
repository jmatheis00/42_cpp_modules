/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:46:09 by jmatheis          #+#    #+#             */
/*   Updated: 2023/09/28 00:09:47 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// zombieHorde calls Constructor
// delete[] calls Destructor for an array of objects
int main(void)
{
	int no;

	no = 7;
	std::cout << GREEN << "\nzombieHorde Test\n"
			  << RESET;
	Zombie *example = zombieHorde(no, "Foo1");
	for (int i = 0; i < no; i++)
		example[i].announce();
	delete[] example;
	return (0);
}