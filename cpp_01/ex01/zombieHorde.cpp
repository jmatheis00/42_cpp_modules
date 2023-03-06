/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:13 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/06 15:34:48 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *temp;

    temp = new Zombie[N]; // calls Constructor for an array of [N] objects
    if (!temp)
	{
		std::cout << "Allocation of a zombieHorde failed" << std::endl;
		return (NULL);
	}
    for(int i = 0; i < N; i++)
    {
        temp[i].set_name(name);
    }
    return (temp);
}
